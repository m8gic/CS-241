/* Avery Schleicher
 * Prints out given shapes to match example
 * output file 1 blank line between
 * (\n at the end of each line) 
 **/

#include <stdio.h>

char top(void) {
   	 printf("    +++++++++++++\n");
   	 printf("   /             \\\n");
   	 printf("  /   CSCI1230    \\\n");
   	 printf(" /                 \\\n");
   	 printf("/___________________\\\n");
}
char bottom(void) {
	printf("\\___________________/\n");
	printf(" \\      *****      /\n");
	printf("  \\     *****     /\n");
	printf("   \\____~___~____/\n");
}
int main(void) {
	top();
	printf("\n");
	bottom();
	printf("\n");
	top();
	bottom();
	printf("\n");
	return 0;
	
}
