using System;
class Program { static void Main() { Console.Write("Введіть вік від 20 до 69: "); int age = Convert.ToInt32(Console.ReadLine());
    if (age < 20 || age > 69)
    {
        Console.WriteLine("Помилка! Вік повинен бути від 20 до 69.");
    }
    else
    {
        string word = "";

        switch (age % 10)
        {
            case 1:
                word = "рік";
                break;

            case 2:
            case 3:
            case 4:
                word = "роки";
                break;

            default:
                word = "років";
                break;
        }

        Console.WriteLine(age + " " + word);
    }
}
}
