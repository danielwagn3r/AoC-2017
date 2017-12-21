#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#include "inversecaptcha.h"

int main(int argc, char **argv)
{
	/* check number of command-line arguments */
	if (argc != 3)
	{
		usage();

		/* return error */
		return EXIT_FAILURE;
	}

	FILE *inputFile = fopen(argv[2], "r");

	if (!inputFile)
	{
		perror("File opening failed!");
		return EXIT_FAILURE;
	}

	fseek(inputFile, 0L, SEEK_END);
	size_t inputFileSize = ftell(inputFile);
	fseek(inputFile, 0L, SEEK_SET);

	int character; // note: int, not char, required to handle EOF
	char *input = malloc(sizeof(char) * inputFileSize);

	if (input == NULL)
	{
		perror("Allocating memory failed!");
		return EXIT_FAILURE;
	}
	size_t i;
	for (i = 0; (character = fgetc(inputFile)) != EOF; i++)
	{
		/* stop reading if a non-digit is found */
		if (isdigit(character))
		{
			input[i] = character;
		}
		else
		{
			break;
		}
	}

	input = realloc(input, i);
	inputFileSize = i;

	fclose(inputFile);

	int sum;
	switch (argv[1][0])
	{
	case '1':
		sum = partOne(input, inputFileSize);
		break;

	case '2':
		sum = partTwo(input, inputFileSize);
		break;

	default:
		sum = -1;
	}

	fprintf(stdout, "%d\n", sum);

	free(input);

	return EXIT_SUCCESS;
}

int partOne(char *input, size_t size)
{
	int sum = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (input[i] == input[(i + 1) % (size)])
		{
			sum += input[i] - '0';
		}
	}

	return sum;
}

int partTwo(char *input, size_t size)
{
	int sum = 0;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (input[i] == input[(i + size / 2) % (size)])
		{
			sum += input[i] - '0';
		}
	}

	return sum;
}

void usage()
{
	fprintf(stdout, "Usage: inversecaptcha.exe PART INPUTFILE");
}