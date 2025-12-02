// Every time the dial points at 0, increment a count by 1
// Return final count

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

    if (line_length == NULL) {
        return NULL;
    }

    // Null terminate the rotation's string.
    lineptr[line_length - 1] = '\0';

    return lineptr;
}

int process_rotation(char* rotation_string)
{
    int negative = ( rotation_string[0] == 'L' );
    double value = strtod(rotation_string[1], NULL);
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

    int dial = 0;
    int count = 0;

    for (int i = 0; i < FILE_LENGTH; i++) {
        int value = read_rotation(rotations_array[i]);
        dial += value;
        if (dial > 99) {
            dial = dial % 100;
        }

        if (dial == 0) {
            count++;
        }
    }

}