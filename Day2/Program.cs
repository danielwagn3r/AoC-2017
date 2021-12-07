// See https://aka.ms/new-console-template for more information

Console.WriteLine("AoC 2017 Day 2");

var input = (await File.ReadAllLinesAsync("input.txt")).Select(l => l.Split('\t').Select(n => int.Parse(n)).ToArray()).ToArray();

Console.WriteLine($"One: {Puzzle(input, MaximumPairDifference)}");
Console.WriteLine($"Two: {Puzzle(input, SumOfDivisiblePair)}");

int Puzzle(int[][] input, Func<int[], int> filter)
{
    return input.Select(l => filter(l)).Sum(); ;
}

int MaximumPairDifference(int[] input)
{
    return input.Max() - input.Min();
}

int SumOfDivisiblePair(int[] input)
{
    for (int i = 0; i < input.Length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (input[i] % input[j] == 0)
                return input[i] / input[j];
            else if (input[j] % input[i] == 0)
                return input[j] / input[i];
        }
    }

    return 0;
}