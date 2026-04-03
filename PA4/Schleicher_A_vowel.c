#include <ctype.h>
#include <stdio.h>
/**
 * Avery Schleicher
 */

int main(void) {
	int vowelCount = 0, letterCount = 0, charCount = 0,
	aCount = 0, eCount = 0,iCount = 0, oCount = 0, uCount = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\r') {
			continue;
		}
		if (iscntrl(c) && !isspace(c)) {
			return 1;
		}
                if (isspace(c)) {
			continue;
		}
		charCount ++;

		if (isalpha(c)) {
			letterCount++;
			switch (tolower(c)) {
				case 'a':
					vowelCount++;
					aCount++;
					break;
				case 'e':
					vowelCount++;
					eCount++;
					break;
				case 'i': 
					vowelCount++;
					iCount++;
					break;
				case 'o':
					vowelCount++;
					oCount++;
					break;
				case 'u':
					vowelCount++;
					uCount++;
					break;
				default:
					break;
				}


			}
		}


	printf("The text has %d vowels.\n", vowelCount);
	printf("%5.1f%% are A\n",   (float) aCount/vowelCount *(100.0));
	printf("%5.1f%% are E\n",   (float) eCount/vowelCount * (100.0));
	printf("%5.1f%% are I\n",   (float) iCount/vowelCount * (100.0));
	printf("%5.1f%% are O\n",   (float) oCount/vowelCount * (100.0));
	printf("%5.1f%% are U\n",   (float) uCount/vowelCount * (100.0));
        printf("\n");
        printf("There are %d characters in total, %d of those characters are letters.\n",
               charCount, letterCount);
        printf("%5.1f%% of the letter characters are vowels.\n",(float)vowelCount / 
	       letterCount * 100.0);
        printf("%5.1f%% of all the characters in the text are vowels.\n", (float)vowelCount 
	       / charCount * 100.0);

		return 0;
}
