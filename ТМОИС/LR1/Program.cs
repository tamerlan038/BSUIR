public class Program
{
    public static void Main()
    {
        List<int> resultList = new List<int>();
        List<int> unionList = new List<int>();
        List<int> intersectList = new List<int>();

        Console.WriteLine("Введите элементы первого множества (через пробел): \n");
        List<int> firstList = ReadSetFromConsole();

        Console.WriteLine("Введите элементы второго множества (через пробел): \n");
        List<int> secondList = ReadSetFromConsole();

        // 1. Объединение
        Console.Write("Объединение: ");
        unionList = firstList.Union(secondList).ToList();
        Console.WriteLine(string.Join(" ", unionList));

        // 2. Пересечение
        Console.Write("Пересечение: ");
        intersectList = firstList.Intersect(secondList).ToList();
        Console.WriteLine(string.Join(" ", intersectList));

        // 3. Разность
        foreach (var element in firstList)
        {
            if (!secondList.Contains(element))
            {
                resultList.Add(element);
            }
        }

        Console.Write("Разность: ");
        Console.WriteLine(string.Join(" ", resultList));
        resultList.Clear();

        // 4. Симметрическая разность
        foreach (var element in unionList)
        {
            if (!intersectList.Contains(element))
            {
                resultList.Add(element);
            }
        }

        Console.Write("Симметрическая Разность: ");
        Console.WriteLine(string.Join(" ", resultList));
        resultList.Clear();

        // 5. Дополнение
        Console.Write("Дополнение (относительно U): ");
        foreach (var element in unionList)
        {
            if (!secondList.Contains(element))
            {
                resultList.Add(element);
            }
        }

        Console.Write("Дополнение: ");
        Console.WriteLine(string.Join(" ", resultList));
        resultList.Clear();
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
                if (int.TryParse(element, out int number)) // TryParse - переводит в число
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
                return result; // выход из цикла вайл
            }

            isInvalidInput = false;
        }
    }
}