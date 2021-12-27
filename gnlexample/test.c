#include <stdio.h>
int func(char *buf)
{
	*buf = NULL;
	return 1;
}
int main()
{
	char buf[1][5];

	buf[0][0] = 'b';
	buf[0][1] = 'r';
	buf[0][2] = 'u';
	buf[0][3] = 'h';
	buf[0][4] = '\0';
	func(buf[0]);
	printf("%s\n", buf[0]);
}