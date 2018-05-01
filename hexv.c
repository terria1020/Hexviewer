#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("usage : %s filename\n", argv[0]);
		return 0;
	}
	FILE *fp;

	fp = fopen(argv[1], "rb");
	while (!feof(fp))
	{
		for (int i = 0; i <= 9; i++)
		{
			if (feof(fp))
			{
				break;
			}
			else
			{
				printf("%.2x  ", fgetc(fp));
			}
		}
		printf("\n");
	}
	fclose(fp);
	return 0;
}