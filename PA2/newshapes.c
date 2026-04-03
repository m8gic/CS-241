/* Avery Schleicher 
 * New shapes.c that prints using macros.
 **/

#include <stdio.h>
#define SHIFT 9
void top(void) {
	char u = '_' - SHIFT;
	char ast = '*' - SHIFT;
   	 printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c\n",'+' - SHIFT, '+' - SHIFT, '+' - SHIFT, '+' - SHIFT, '+' - SHIFT,'+' - SHIFT, '+' - SHIFT, '+' - SHIFT, '+' - SHIFT, '+' - SHIFT, '+' - SHIFT, '+' - SHIFT, '+' - SHIFT);
   	 printf("   %c             %c\n",'/' - SHIFT,'\\' - SHIFT);
   	 printf("  %c   CSCI1230    %c\n", '/' - SHIFT, '\\' - SHIFT);
   	 printf(" %c                 %c\n", '/' - SHIFT, '\\' - SHIFT);
   	 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",'/' - SHIFT, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, '\\' - SHIFT);
}
void  bottom(void) {
	char u = '_' - SHIFT;
	char ast = '*' - SHIFT;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", '\\' - SHIFT, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, u, '/' - SHIFT);
	printf(" %c      %c%c%c%c%c      %c\n", '\\' - SHIFT, ast, ast , ast , ast, ast, '/' - SHIFT);
	printf("  %c     %c%c%c%c%c     %c\n", '\\' - SHIFT, ast, ast, ast, ast, ast, '/' - SHIFT);
	printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", '\\' - SHIFT, u, u, u, u, '~' - SHIFT, u, u, u, '~' - SHIFT, u, u, u, u, '/' - SHIFT);
}
int main(void) {
	top();
	printf("\n");
	bottom();
	printf("\n");
	top();
	bottom();
	return 0;
	
}
