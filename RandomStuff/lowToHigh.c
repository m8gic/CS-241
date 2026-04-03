/* Lower case to upper case */ 
#include <stdio.h>

int main()
{
	int i;
	char c;
	printf("Please enter a character\n");
	c = getchar();
	if ('a' <= c &&  c <= 'z')
		putchar (c - ('a' - 'A'));
	else 
		putchar(c);
	printf("\n");

	return 0;
}
