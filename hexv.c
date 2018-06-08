#include <stdio.h>

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
	int index = 0x0;
	while (1)
	{
		printf("0x%x : ", index);
		for (int i = 0; i <= 15; i++)
		{
			
			if (feof(fp))
			{
				printf("\n");
				return;
			}
			else
			{
				printf("%.2x  ", fgetc(fp));
			}
		}
		printf("\n");
		index += 0x10;
	}

}
