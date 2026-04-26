# test.py
import tkinter as tk
import numpy as np
from pathlib import Path
import sys

def sigmoid(x: np.ndarray) -> np.ndarray:
    return 1 / (1 + np.exp(-x))

def rgb_to_cmyk(rgb: np.ndarray) -> np.ndarray:
    R, G, B = rgb[0, 0], rgb[0, 1], rgb[0, 2]
    K = 1 - max(R, G, B)
    if K == 1:
        return np.array([[0.0, 0.0, 0.0, 1.0]], dtype=np.float64)
    C = (1 - R - K) / (1 - K)
    M = (1 - G - K) / (1 - K)
    Y = (1 - B - K) / (1 - K)
    return np.array([[C, M, Y, K]], dtype=np.float64)

def cmyk_to_rgb_display(cmyk: np.ndarray) -> tuple[float, float, float]:
    """Визуализация CMYK на RGB-экране (математически обратное преобразование)"""
    C, M, Y, K = cmyk[0]
    R = (1 - C) * (1 - K)
    G = (1 - M) * (1 - K)
    B = (1 - Y) * (1 - K)
    return R, G, B

def to_hex(r: float, g: float, b: float) -> str:
    """Безопасное преобразование в HEX с клиппингом [0,1]"""
    r, g, b = np.clip([r, g, b], 0.0, 1.0)
    return f"#{int(round(r*255)):02x}{int(round(g*255)):02x}{int(round(b*255)):02x}"

WEIGHTS_FILE = Path(__file__).parent / "cmyk_model_weights.npz"
if not WEIGHTS_FILE.is_file():
    print(f"❌ Файл '{WEIGHTS_FILE.name}' не найден в папке скрипта.")
    print("💡 Сначала запустите обучение, чтобы сохранить веса.")
    sys.exit(1)

data = np.load(WEIGHTS_FILE)
w = data["w"].copy()
b = data["b"].copy()

def model_predict(rgb_input: np.ndarray) -> np.ndarray:
    return sigmoid(rgb_input @ w + b)

root = tk.Tk()
root.title("RGB → CMYK: Визуальный тест нейросети")
root.geometry("520x340")
root.resizable(False, False)

panels_frame = tk.Frame(root)
panels_frame.pack(pady=15)

def make_panel(parent, title):
    f = tk.Frame(parent)
    f.pack(side=tk.LEFT, padx=20)
    tk.Label(f, text=title, font=("Segoe UI", 11, "bold")).pack()
    color_box = tk.Frame(f, width=110, height=80, bd=2, relief="solid", bg="gray")
    color_box.pack(pady=6)
    color_box.pack_propagate(False)
    val_lbl = tk.Label(f, text="", font=("Segoe UI", 9), justify="left")
    val_lbl.pack()
    return color_box, val_lbl

rgb_box, rgb_txt = make_panel(panels_frame, "Исходный (RGB)")
true_box, true_txt = make_panel(panels_frame, "Эталон (CMYK)")
pred_box, pred_txt = make_panel(panels_frame, "Модель (CMYK)")

# Ошибка и кнопка
err_lbl = tk.Label(root, text="MSE: -", font=("Segoe UI", 12, "bold"), fg="#cc0000")
err_lbl.pack(pady=8)

btn = tk.Button(root, text="🔄 Сгенерировать новый цвет", font=("Segoe UI", 12, "bold"),
                bg="#4CAF50", fg="white", activebackground="#43a148", activeforeground="white")
btn.pack(fill="x", padx=50, pady=10)

def generate():
    rgb = np.random.rand(1, 3)
    r, g, b_val = rgb[0]
    hex_rgb = to_hex(r, g, b_val)
    rgb_box.config(bg=hex_rgb)
    rgb_txt.config(text=f"R:{r:.2f}  G:{g:.2f}  B:{b_val:.2f}")

    cmyk_true = rgb_to_cmyk(rgb)
    R_t, G_t, B_t = cmyk_to_rgb_display(cmyk_true)
    true_box.config(bg=to_hex(R_t, G_t, B_t))
    c, m, y, k = cmyk_true[0]
    true_txt.config(text=f"C:{c:.2f}  M:{m:.2f}\nY:{y:.2f}  K:{k:.2f}")

    cmyk_pred = model_predict(rgb)
    R_p, G_p, B_p = cmyk_to_rgb_display(cmyk_pred)
    pred_box.config(bg=to_hex(R_p, G_p, B_p))
    pc, pm, py, pk = cmyk_pred[0]
    pred_txt.config(text=f"C:{pc:.2f}  M:{pm:.2f}\nY:{py:.2f}  K:{pk:.2f}")

    mse = float(np.sum((cmyk_true - cmyk_pred)**2))
    err_lbl.config(text=f"Среднеквадратичная ошибка (MSE): {mse:.5f}")

btn.config(command=generate)
generate()

root.mainloop()