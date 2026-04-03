#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @author Avery Schleicher
 * Image manipulation inside of a 2D array. std in reading as well.
 */

#define EXIT_CODE_BAD_INPUT_FILE 1
#define EXIT_CODE_BAD_CMD_LINE 2

int size; // number of rows/cols in the image

/**** Description and prototype of the functions
 * getSize: reads the image size from standard input
 *
 * getOrigImage: reads the image from standard input,
 *               exceptions: illegal characters in the image
 *
 * outputImage: prints the final image
 *
 * inBounds: returns true if-and-only-if entry [row][col] is
 *           within the bounds of the array
 *
 * invert: do the invert transformation and leaves the result in a new 2D array
 *
 * rotate: rotate the image clockwise 90 degrees (to do a flip horizontal)
 *
 * flipVer: flip thorough an imaginary vertical line down the center of image
 *
 * removeRedEye: airbrush away every isolated dot
 *
 * crop: removes border of k pixels
 */

void getSize(int *size) {
    if (scanf("%d", size) != 1 || *size < 1) {
        exit(EXIT_CODE_BAD_INPUT_FILE);
    }
}
void getOrigImage(int origImage[][size]) {
    char ch;
    // newline after size
    scanf("%c", &ch);
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (scanf("%c", &ch) != 1) {
                exit(EXIT_CODE_BAD_INPUT_FILE);
            }
            if (ch != '*' && ch != ' ') {
                exit(EXIT_CODE_BAD_INPUT_FILE);
            }
            origImage[row][col] = ch;
        }
        // newline
        if (scanf("%c", &ch) != 1 || ch != '\n') {
            exit(EXIT_CODE_BAD_INPUT_FILE);
        }
    }
}
void copyImage(int picture[][size], int result[][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            result[row][col] = picture[row][col];
        }
    }
}

void outputImage(int picture[][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            printf("%c", picture[row][col]);
        }
        printf("\n");
    }
}

bool inBounds(int row, int col) {
    if (row >= 0 && row < size && col >= 0 && col < size) {

        return 1;
    }
    return 0;
}

void invert(int picture[][size], int result[][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {

            if (picture[row][col] == '*') {
                result[row][col] = ' ';
            } else {
                result[row][col] = '*';
            }
        }
    }
}

void rotate(int picture[][size], int result[][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            result[row][col] = picture[size - 1 - col][row];
        }
    }
}

void flipVer(int picture[][size], int result[][size]) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            result[row][col] = picture[row][size - 1 - col];
        }
    }
}

void removeRedEye(int picture[][size], int result[][size]) {
    int hasNeighbor;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {

            if (picture[row][col] == ' ') {
                result[row][col] = ' ';
            } else {
                hasNeighbor = 0;

                for (int r = row - 1; r <= row + 1; r++) {
                    for (int c = col - 1; c <= col + 1; c++) {

                        if (inBounds(r, c) && !(r == row && c == col)) {
                            if (picture[r][c] == '*') {
                                hasNeighbor = 1;
                            }
                        }
                    }
                }
                if (hasNeighbor) {
                    result[row][col] = '*';
                } else {
                    result[row][col] = ' ';
                }
            }
        }
    }
}
int crop(int picture[][size], int k) {
    if (k < 0 || 2 * k >= size) {
        exit(EXIT_CODE_BAD_CMD_LINE);
    }

    int newSize = size - 2 * k;

    for (int row = 0; row < newSize; row++) {
        for (int col = 0; col < newSize; col++) {
            picture[row][col] = picture[row + k][col + k];
        }
    }
    return newSize;
}

int main(int argc, char *argv[]) {

    getSize(&size);

    int original[size][size];
    int result[size][size];

    getOrigImage(original);

    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "inv") == 0) {
            invert(original, result);
            copyImage(result, original);
        } else if (strcmp(argv[i], "redeye") == 0) {
            removeRedEye(original, result);
            copyImage(result, original);
        } else if (strcmp(argv[i], "flip") == 0) {
            if (i + 1 >= argc) {
                exit(EXIT_CODE_BAD_CMD_LINE);
            }
            if (strcmp(argv[i + 1], "V") == 0 || strcmp(argv[i + 1], "v") == 0) {
                flipVer(original, result);
                copyImage(result, original);
            } else if (strcmp(argv[i + 1], "H") == 0 || strcmp(argv[i + 1], "h") == 0) {
                rotate(original, result);
                copyImage(result, original);

                rotate(original, result);
                copyImage(result, original);
            } else {
                exit(EXIT_CODE_BAD_CMD_LINE);
            }
            i++;
        } else if (strcmp(argv[i], "crop") == 0) {
            if (i + 1 >= argc) {
                exit(EXIT_CODE_BAD_CMD_LINE);
            }

            int k = atoi(argv[i + 1]);
            size = crop(original, k);
            i++;
        } else {
            exit(EXIT_CODE_BAD_CMD_LINE);
        }
        outputImage(original);
        return 0;
    }
}
