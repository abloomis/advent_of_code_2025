/* 
 * alex loomis
 * advent of code 2025
 * day 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_LENGTH 4269

char* read_rotation(FILE* file) 
{
    char* lineptr = NULL;
    size_t buffer_size = 0;
    ssize_t line_length;  
    line_length = getline(&lineptr, &buffer_size, file);

    if (line_length <= 0) {
        return NULL;
    }

    // Null terminate the rotation's string.
    lineptr[line_length - 1] = '\0';

    return lineptr;
}

int convert_rotation(char* str)
{
    int negative = ( str[0] == 'L' );
    memmove(str, str + 1, strlen(str));
    double value = strtod(str, NULL);
    if (negative) {
        return ( ((int) value) * -1 );
    } else {
        return ((int) value);
    }
}

int main(int argc, char** argv) 
{
    // Open the file provided as arg 1
    FILE* fstream;
    fstream = fopen(argv[1], "r");
    if (!fstream) {
        printf("Error opening %s!\n", argv[1]);
        return 1;
    }

    char* rotations_array[FILE_LENGTH];
    for (int i = 0; i < FILE_LENGTH; i++) {
        rotations_array[i] = read_rotation(fstream);
    }

    int dial = 50;
    int count = 0;

    for (int i = 0; i < FILE_LENGTH; i++) {
        int value = convert_rotation(rotations_array[i]);
        dial += value;
        while (dial > 99) {
            dial = dial - 100;
            count++;  // pass zero
        }
        while (dial < 0) {
            dial = dial + 100;
            count++;  // pass zero
        }
    }

    printf("\nTimes the dial pointed at 0: %d\n", count);
    return 0;
}