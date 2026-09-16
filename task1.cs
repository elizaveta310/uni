using System;
class Program { static void Main() { Console.Write("Введите координату A: "); double A = Convert.ToDouble(Console.ReadLine());
    Console.Write("Введите координату B: ");
    double B = Convert.ToDouble(Console.ReadLine());

    Console.Write("Введите координату C: ");
    double C = Convert.ToDouble(Console.ReadLine());

    double distanceB = Math.Abs(B - A);
    double distanceC = Math.Abs(C - A);

    if (B == A || C == A)
    {
        Console.WriteLine("Одна из точек B или C совпадает с точкой A.");
    }
    else if (B == C)
    {
        Console.WriteLine("Точки B и C совпадают между собой.");
    }
    else if (distanceB == distanceC)
    {
        Console.WriteLine("Точки B и C равноудалены от точки A.");
    }
    else if (distanceB < distanceC)
    {
        Console.WriteLine("Ближе к A находится точка B.");
        Console.WriteLine("Расстояние: " + distanceB);
    }
    else
    {
        Console.WriteLine("Ближе к A находится точка C.");
        Console.WriteLine("Расстояние: " + distanceC);
    }
}
}
