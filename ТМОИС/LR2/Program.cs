using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main()
    {
        Console.WriteLine("Введите элементы первого множества (через пробел):");
        List<int> firstList = ReadSetFromConsole();

        //if (firstList.Count %2 != 0)
        //{
        //    Console.WriteLine("Размерность списка должна быть четной");
        //    return;
        //}

        Console.WriteLine("Введите элементы второго множества (через пробел):");
        List<int> secondList = ReadSetFromConsole();

        //if (secondList.Count % 2 != 0)
        //{
        //    Console.WriteLine("Размерность списка должна быть четной");
        //    return;
        //}

        var firstTuples = SplitIntoPairs(firstList);
        Console.WriteLine("Кортежи первого множества:");
        foreach (var tuple in firstTuples)
        {
            Console.WriteLine($"({tuple.Item1}, {tuple.Item2})");
        }

        var secondTuples = SplitIntoPairs(secondList);
        Console.WriteLine("\nКортежи второго множества:");
        foreach (var tuple in secondTuples)
        {
            Console.WriteLine($"({tuple.Item1}, {tuple.Item2})");
        }
        
        var projectionXFirst = ProjectOnX(firstTuples);
        Console.WriteLine("Проекция на X первого отношения:");
        Console.WriteLine(string.Join(" ", projectionXFirst));

        var projectionYFirst = ProjectOnY(firstTuples);
        Console.WriteLine("\nПроекция на Y первого отношения:");
        Console.WriteLine(string.Join(" ", projectionYFirst));

        var projectionXSecond = ProjectOnX(secondTuples);
        Console.WriteLine("\nПроекция на X второго отношения:");
        Console.WriteLine(string.Join(" ", projectionXSecond));

        var projectionYSecond = ProjectOnY(secondTuples);
        Console.WriteLine("\nПроекция на Y второго отношения:");
        Console.WriteLine(string.Join(" ", projectionYSecond));
        
        var invertedFirst = InvertRelation(firstTuples);
        Console.WriteLine("Инверсия первого отношения:");
        foreach (var tuple in invertedFirst)
        {
            Console.WriteLine($"({tuple.Item1}, {tuple.Item2})");
        }

        var invertedSecond = InvertRelation(secondTuples);
        Console.WriteLine("\nИнверсия второго отношения:");
        foreach (var tuple in invertedSecond)
        {
            Console.WriteLine($"({tuple.Item1}, {tuple.Item2})");
        }
        
        var composition = ComposeRelations(firstTuples, secondTuples);
        Console.WriteLine("Композиция первого и второго отношения:");
        foreach (var tuple in composition)
        {
            Console.WriteLine($"({tuple.Item1}, {tuple.Item2})");
        }
    }

    private static List<(int, int)> SplitIntoPairs(List<int> set)
    {
        var pairs = new List<(int, int)>();
        
        for (int i = 0; i < set.Count - 1; i += 2)
        {
            if (i + 1 < set.Count)
            {
                pairs.Add((set[i], set[i + 1]));
            }
            else
            {
                pairs.Add((set[i], set[i]));
            }
        }
        
        return pairs;
    }

    private static List<int> ProjectOnX(List<(int, int)> relation)
    {
        return relation.Select(tuple => tuple.Item1)
                      .Distinct()
                      .OrderBy(x => x)
                      .ToList();
    }

    private static List<int> ProjectOnY(List<(int, int)> relation)
    {
        return relation.Select(tuple => tuple.Item2)
                      .Distinct()
                      .OrderBy(y => y)
                      .ToList();
    }

    private static List<(int, int)> InvertRelation(List<(int, int)> relation)
    {
        return relation.Select(tuple => (tuple.Item2, tuple.Item1)).ToList();
    }

    private static List<(int, int)> ComposeRelations(List<(int, int)> first, List<(int, int)> second)
    {
        var composition = new List<(int, int)>();
        
        foreach (var tuple1 in first)
        {
            foreach (var tuple2 in second)
            {
                if (tuple1.Item2 == tuple2.Item1)
                {
                    var newTuple = (tuple1.Item1, tuple2.Item2);
                    if (!composition.Contains(newTuple))
                    {
                        composition.Add(newTuple);
                    }
                }
            }
        }
        
        return composition;
    }

    private static List<int> ReadSetFromConsole()
    {
        bool isInvalidInput = false;
        while (true)
        {
            string input = Console.ReadLine();
            if (string.IsNullOrWhiteSpace(input))
            {
                Console.WriteLine("Введите хотя бы один элемент:");
                continue;
            }

            string[] elements = input.Split(' ');
            List<int> result = new List<int>();

            foreach (string element in elements)
            {
                if (int.TryParse(element, out int number))
                {
                    result.Add(number);
                }
                else
                {
                    Console.WriteLine($"Ошибка: '{element}' не является числом. Попробуйте снова:");
                    isInvalidInput = true;
                    break;
                }
            }

            if (!isInvalidInput)
            {
                return result;
            }

            isInvalidInput = false;
        }
    }
}