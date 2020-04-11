#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print(FILE *fp);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage : %s filename\n", argv[0]);
		return 0;
	}
	FILE *fp;

	fp = fopen(argv[1], "rb");
	if (fp == NULL)
	{
		printf("[%s] is not exist or file open error.\n", argv[1]);
		return 0;
	}

	print(fp);
	fclose(fp);
	return 0;
}

void print(FILE *fp)
{
	char * ascii;
	ascii = (char*)malloc(sizeof(char) * 17);
	int index = 0x0;
	int d;
	while (1)
	{
		
		printf("0x%X :", index);
		if (index < 0x1000) printf("\t\t\t");
		else if (index < 0x10000) printf("\t\t");
		for (int i = 0; i <= 15; i++)
		{
			d = fgetc(fp);
			if (d >= 0x20 && d < 0x7f) ascii[i] = d;
			else ascii[i] = '.';
			if (feof(fp)) {
				printf("\n");
				free(ascii);
				return;
			}
			printf("%.2X  ", d);
		}
		ascii[16] = 0;
		printf("\t%s\n", ascii);
		index += 0x10;
	}
}