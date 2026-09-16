using System;
class Program { static void Main() { Console.Write("Введіть N > 1: "); int N = Convert.ToInt32(Console.ReadLine());
    if (N <= 1)
    {
        Console.WriteLine("Помилка! N повинно бути більше 1.");
    }
    else
    {
        int number = N;
        bool prime = false;

        while (!prime)
        {
            int divisor = 2;
            prime = true;

            while (divisor < number)
            {
                if (number % divisor == 0)
                {
                    prime = false;
                }

                divisor++;
            }

            if (!prime)
            {
                number++;
            }
        }

        if (number == N)
        {
            Console.WriteLine(N + " - просте число.");
        }
        else
        {
            Console.WriteLine(N + " - не просте число.");
            Console.WriteLine("Найближче більше просте число: " + number);
        }
    }
}
}
