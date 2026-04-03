/* How to print a percentage sign */

#include <stdio.h> 

int main()
{
	printf("we use \\ to cancel the meaning of a char in a format specifier\n");
	printf("in this case the first backslash cancels the second backslash\n");
	printf("how do we print a percentage sign if we want to say 92 percent?\n ");
	printf("We use two consecutive signs, as in \"%%%%\", e.g.  92%%  \n");
	return 0;
}
