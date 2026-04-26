import numpy as np
from numpy import ndarray
import os
EPOCHES = 100000
LEARNING_RATE = 0.005
EVAL_EVERY = 50

FILENAME = "cmyk_model_weights.npz"
if os.path.isfile(FILENAME):
    data = np.load(FILENAME)
    w = data["w"]
    b = data["b"]

else:
    np.random.seed(42)  # Для воспроизводимости
    w = np.random.rand(3, 4)
    b = np.random.rand(1, 4)
# Проверка (опционально)
print(f"w shape: {w.shape}, b shape: {b.shape}")

def sigmoid(x: ndarray) -> ndarray:
    return 1 / (1 + np.exp(-x))

def loss(y: ndarray, p: ndarray) -> float:
    return np.sum((p - y) ** 2)

def loss_grad(y: ndarray, p: ndarray) -> ndarray:
    return 2 * (p - y)  # ✅ ИСПРАВЛЕНО: (y-p) -> (p-y)

def sigmoid_grad(x: ndarray) -> ndarray:
    s = sigmoid(x)
    return s * (1 - s)

def rgb_to_cmyk(rgb: np.ndarray) -> np.ndarray:
    R, G, B = rgb[0, 0], rgb[0, 1], rgb[0, 2]
    K = 1 - max(R, G, B)
    if K == 1:
        C = M = Y = 0.0
    else:
        C = (1 - R - K) / (1 - K)
        M = (1 - G - K) / (1 - K)
        Y = (1 - B - K) / (1 - K)
    return np.array([[C, M, Y, K]], dtype=np.float64)



accumulated_loss = 0.0

best_loss = 9999999

for i in range(EPOCHES):
    x = np.random.rand(1, 3)
    y = rgb_to_cmyk(x)

    # Forward pass
    N = x @ w + b          # @ предпочтительнее для матриц
    p = sigmoid(N)
    
    current_loss = loss(y, p)
    accumulated_loss += current_loss

    # Вывод средней ошибки за период
    if (i + 1) % EVAL_EVERY == 0:
        mean_loss = accumulated_loss / EVAL_EVERY
        print(f"Step {i+1} | Mean Loss (last {EVAL_EVERY}): {mean_loss:.6f}")
        
        if accumulated_loss < best_loss:
            np.savez(FILENAME, w=w, b=b)
            print(f"Веса сохранены в {FILENAME}")
            best_loss = accumulated_loss

        accumulated_loss = 0.0


    # Backward pass
    dlds = loss_grad(y, p)       # (1, 4) ∂L/∂p
    dsdn = sigmoid_grad(N)       # (1, 4) ∂p/∂N
    dldn = dlds * dsdn           # (1, 4) ∂L/∂N (chain rule)

    dldb = dldn                  # (1, 4) ∂L/∂b
    dldw = x.T @ dldn            # (3, 4) ∂L/∂w (матричное умножение)

    w -= dldw * LEARNING_RATE
    b -= dldb * LEARNING_RATE
    


