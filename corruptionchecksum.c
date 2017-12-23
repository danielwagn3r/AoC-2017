#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

#include "corruptionchecksum.h"

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
	char *input = malloc(sizeof(char) * (inputFileSize + 1));

	if (input == NULL)
	{
		perror("Allocating memory failed!");
		return EXIT_FAILURE;
	}
	size_t i;
	for (i = 0; (character = fgetc(inputFile)) != EOF; i++)
	{
		input[i] = character;
	}

	input[i] = '\0';

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
	int lineMinimum = INT_MAX;
	int lineMaximum = INT_MIN;

	const char *valid = "0123456789";
	const char *current = input;

	while (current != NULL && strlen(current) > 0)
	{
		size_t valid_len = strspn(current, valid);

		if (valid_len != strlen(current))
		{
			char *token = malloc(valid_len * sizeof(char) + 1);

			strncpy(token, current, valid_len);
			token[valid_len] = '\0';

			int number = atoi(token);

			current += valid_len;

			if (current[0] == '\t')
			{
				if (lineMaximum < number)
					lineMaximum = number;
				if (lineMinimum > number)
					lineMinimum = number;
			}
			else if (current[0] == '\n')
			{
				if (lineMaximum < number)
					lineMaximum = number;
				if (lineMinimum > number)
					lineMinimum = number;

				sum += lineMaximum - lineMinimum;

				lineMaximum = INT_MIN;
				lineMinimum = INT_MAX;
			}
			else
				fprintf(stderr, "unexpected\n");

			size_t skip = strcspn(current, valid);

			current += skip;

			free(token);
		}
		else
			break;
	}

	return sum;
}

int partTwo(char *input, size_t size)
{
	int sum = 0;

	const char *valid = "0123456789";
	const char *current = input;

	while (current != NULL && strlen(current) > 0)
	{
		size_t line_len = strcspn(current, "\n");

		fprintf(stdout, "length(%d)\n", line_len);

		current += line_len;

		size_t skip = strcspn(current, valid);

		current += skip;
	}

	return sum;
}

void usage()
{
	fprintf(stdout, "Usage: inversecaptcha.exe PART INPUTFILE");
}
