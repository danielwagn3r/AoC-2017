#ifndef CORRUPTIONCHECKSUM_H
#define CORRUPTIONCHECKSUM_H

#include <stdint.h>

int main(int argc, char **argv);

void usage();

int partOne(char *input, size_t size);

int partTwo(char *input, size_t size);

#endif