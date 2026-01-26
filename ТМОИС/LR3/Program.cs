using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static List<T> Intersect<T>(List<T> A, List<T> B) =>
        A.Where(B.Contains).ToList();

    static List<T> Union<T>(List<T> A, List<T> B)
    {
        var res = new List<T>(A);
        foreach (var b in B)
            if (!res.Contains(b))
                res.Add(b);
        return res;
    }

    static List<T> Subtract<T>(List<T> A, List<T> B) =>
        A.Where(x => !B.Contains(x)).ToList();

    static bool Equal<T>(List<T> A, List<T> B)
    {
        if (A.Count != B.Count) return false;
        return A.All(B.Contains) && B.All(A.Contains);
    }

    static List<(T, T)> Invert<T>(List<(T, T)> g) =>
        g.Select(p => (p.Item2, p.Item1)).Distinct().ToList();

    static List<(T, T)> Compose<T>(List<(T, T)> g1, List<(T, T)> g2)
    {
        var result = new List<(T, T)>();

        foreach (var p1 in g1)
            foreach (var p2 in g2)
                if (Equals(p1.Item2, p2.Item1))
                    result.Add((p1.Item1, p2.Item2));

        return result.Distinct().ToList();
    }

    static List<T> Image<T>(List<(T, T)> g, List<T> set) =>
        g.Where(p => set.Contains(p.Item1))
         .Select(p => p.Item2)
         .Distinct()
         .ToList();

    static List<T> Preimage<T>(List<(T, T)> g, List<T> set) =>
        g.Where(p => set.Contains(p.Item2))
         .Select(p => p.Item1)
         .Distinct()
         .ToList();

    static List<string> InputSet(string name)
    {
        Console.WriteLine($"Введите элементы множества {name} через пробел:");
        var input = Console.ReadLine()!;
        return input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                   .Select(x => x.Trim())
                   .Where(x => !string.IsNullOrEmpty(x))
                   .ToList();
    }

    static List<(string, string)> InputGraph(string setNameX, string setNameY)
    {
        Console.WriteLine($"Введите пары отношения между {setNameX} и {setNameY} (каждая пара в формате 'a b', по одной паре на строку). Для завершения ввода введите пустую строку:");
        
        var g = new List<(string, string)>();
        
        while (true)
        {
            var input = Console.ReadLine()?.Trim();
            if (string.IsNullOrEmpty(input))
                break;
            
            var p = input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            if (p.Length == 2)
            {
                g.Add((p[0], p[1]));
            }
            else
            {
                Console.WriteLine("Ошибка: введите пару в формате 'a b'");
            }
        }
        
        return g;
    }

    static List<(string, string)> InputGraphFromString(string name)
    {
        Console.WriteLine($"Введите пары отношения для {name} (каждая пара в формате 'a b', по одной паре на строку). Для завершения ввода введите пустую строку:");
        
        var g = new List<(string, string)>();
        
        while (true)
        {
            var input = Console.ReadLine()?.Trim();
            if (string.IsNullOrEmpty(input))
                break;
            
            var p = input.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            if (p.Length == 2)
            {
                g.Add((p[0], p[1]));
            }
            else
            {
                Console.WriteLine("Ошибка: введите пару в формате 'a b'");
            }
        }
        
        return g;
    }

    static void PrintSet(string name, List<string> set)
    {
        Console.Write($"{name} = {{ ");
        Console.Write(string.Join(", ", set));
        Console.WriteLine(" }");
    }

    static void PrintGraph(string name, List<(string, string)> graph)
    {
        if (graph.Count == 0)
        {
            Console.WriteLine($"{name} = {{ }}");
            return;
        }

        Console.Write($"{name} = {{ ");
        Console.Write(string.Join(", ", graph.Select(p => $"({p.Item1},{p.Item2})")));
        Console.WriteLine(" }");
    }

    static void Main()
    {
        Console.WriteLine("Ввод множеств и отношений\n");

        // Ввод множества пар H (через пробел и Enter)
        var H = InputGraphFromString("H");
        
        var X = InputSet("X");
        var Y = InputSet("Y");
        var G = InputGraph("X", "Y");

        Console.WriteLine("\nИсходные данные");
        PrintGraph("H", H);
        PrintSet("X", X);
        PrintSet("Y", Y);
        PrintGraph("G", G);

        Console.WriteLine("\n Все операции \n");

        Console.WriteLine("1. Объединение G и H");
        var unionGH = Union(G, H);
        PrintGraph("G U H", unionGH);
        Console.WriteLine();

        Console.WriteLine("2. Пересечение G и H ");
        var intersectGH = Intersect(G, H);
        PrintGraph("G П H", intersectGH);
        Console.WriteLine();

        Console.WriteLine("3. Разность G и H");
        var subtractGH = Subtract(G, H);
        PrintGraph("G \\ H", subtractGH);
        Console.WriteLine();

        Console.WriteLine("4. Разность H и G");
        var subtractHG = Subtract(H, G);
        PrintGraph("H \\ G", subtractHG);
        Console.WriteLine();

        Console.WriteLine("5. Инверсия отношения G^-1");
        var invertedG = Invert(G);
        PrintGraph("G^-1", invertedG);
        Console.WriteLine();

        Console.WriteLine("6. Инверсия отношения H^-1");
        var invertedH = Invert(H);
        PrintGraph("H^-1", invertedH);
        Console.WriteLine();

        Console.WriteLine("7. Композиция G и H");
        var compositionGH = Compose(G, H);
        PrintGraph("G о H", compositionGH);
        Console.WriteLine();

        Console.WriteLine("8. Композиция H и G");
        var compositionHG = Compose(H, G);
        PrintGraph("H о G", compositionHG);
        Console.WriteLine();

        Console.WriteLine("\n14. Операции с подмножествами");
        
        Console.WriteLine("Введите подмножество A принадлежащее множеству X (элементы через пробел):");
        var A = InputSet("A");
        
        var imageA_G = Image(G, A);
        Console.Write("Образ множества A через G: ");
        PrintSet("Γ_G(A)", imageA_G);

        // var imageA_H = Image(H, A);
        // Console.Write("Образ множества A через H: ");
        // PrintSet("Γ_H(A)", imageA_H);

        Console.WriteLine("Введите подмножество B принадлежащее множеству Y (элементы через пробел):");
        var B = InputSet("B");
        
        var preimageB_G = Preimage(G, B);
        Console.Write("Прообраз множества B через G: ");
        PrintSet("Γ_G^-1(B)", preimageB_G);

        // var preimageB_H = Preimage(H, B);
        // Console.Write("Прообраз множества B через H: ");
        // PrintSet("Γ_H^-1(B)", preimageB_H);
    }
}