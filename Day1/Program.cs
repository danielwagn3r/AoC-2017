// See https://aka.ms/new-console-template for more information
Console.WriteLine("AoC 2017 Day 1");

var input = (await File.ReadAllLinesAsync("input.txt")).First().Select(c => c - '0').ToArray();

Console.WriteLine($"One: {PuzzleOne(input)}");
Console.WriteLine($"Two: {PuzzleTwo(input)}");

int PuzzleOne(int[] input)
{
	return input.Select((d, i) => (d, i)).Where(d => (d.d == input[(d.i + 1) % input.Length])).Sum(d => d.Item1);
}

int PuzzleTwo(int[] input)
{
	return input.Select((d, i) => (d, i)).Where(d => (d.d == input[(d.i + input.Length / 2) % input.Length])).Sum(d => d.Item1);
}
