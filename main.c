#include <stdio.h>
#include <stdlib.h>

// Return 1 if failed
// Return 0 if success
int copy(char *input, FILE *output)
{
	FILE *file = fopen(input, "r");

	if (file == NULL) {
		fprintf(stderr, "Could not open file.\n");
		return -1;
	}

	int c;
	while ((c = fgetc(file)) != EOF) {
		fputc(c, output);
	}

	fclose(file);
	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Usage : ./main <input_file> <output_file>\n");
		return EXIT_FAILURE;
	}

	char *filename = argv[1];
	FILE *output = fopen(argv[2], "w");

	if (output == NULL) {
		fprintf(stderr, "Could not open output file.\n");
		return -1;
	}

	int cp = copy(filename, output);
	
	fclose(output);

	if (cp == 0) {
		printf("File '%s' successfully copied to '%s'.\n", argv[1], argv[2]);
	} else {
		fprintf(stderr, "Error: Could not copy file '%s' to '%s'.\n",argv[1], argv[2]);
	}

	return 0;
}
