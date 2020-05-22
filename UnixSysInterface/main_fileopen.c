#include <stdio.h>

int main(void)
{
	FILE *newf = fopen("new.txt", "w");
	char buff[10] = "somerandom";
	//for (int i = 0; i < 10; i++)
	//	putc(buff[i], newf);
	fprintf(newf, "%s", buff);

	fclose(newf);

	return 0;
}
