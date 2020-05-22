#include <unistd.h>

int main(void)
{
	int n;
	int buf[10];
	while ((n = read(0, buf, 10)) > 0)
		write(1, buf, 10);
	return 0;
}
