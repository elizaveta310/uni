using System;
class Program { static void Main() { int number; int position = 0; int maxEven = 0; int maxPosition = 0; bool found = false;
    do
    {
        Console.Write("Введіть число (0 - кінець): ");
        number = Convert.ToInt32(Console.ReadLine());

        if (number != 0)
        {
            position++;

            if (number % 2 == 0)
            {
                if (!found || number > maxEven)
                {
                    maxEven = number;
                    maxPosition = position;
                    found = true;
                }
            }
        }

    } while (number != 0);

    if (found)
    {
        int temp = Math.Abs(maxEven);
        int sum = 0;

        do
        {
            sum = sum + temp % 10;
            temp = temp / 10;

        } while (temp > 0);

        Console.WriteLine("Максимальне парне число: " + maxEven);
        Console.WriteLine("Його порядковий номер: " + maxPosition);
        Console.WriteLine("Сума його цифр: " + sum);
    }
    else
    {
        Console.WriteLine("Парних чисел у послідовності немає.");
    }
}
}
