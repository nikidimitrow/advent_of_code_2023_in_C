#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Open the input file
    FILE *fp = fopen("input", "r");
    if (fp == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    // Initialize variables to keep track of the current index and the current sum
    int index = 0;
    int temp_index = 0;
    __int128 sum = 0;
    __int128 temp_sum = 0;
    int only_valid_chars = 1;

    // Read the lines in the file one by one
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Check if the line contains only numbers
        
        for (int i = 0; i < strlen(line); i++) {
            if (!isdigit(line[i]) && line[i] != '\n') {
                only_valid_chars = 0;
                break;
            }
        }
        // If the line is empty, print the index and sum and reset them
        if (line[0] == '\n') {
            index++;
            sum = 0;
        } else {
            // Otherwise, parse the number and add it to the sum
            __int128 number = atoll(line);
            sum += number;

            //Collect the biggest sum at the moment
            if(temp_sum < sum){
                temp_sum = sum;
                temp_index = index;
            }
        }
    }
        // Print a message indicating whether the line contains only valid characters
        if (only_valid_chars) {
            printf("Line contains only valid characters\n");
        } else {
            printf("Line contains invalid characters\n");
        }

    // Print the final index and sum
    printf("Index: %d Sum: %lld\n", temp_index, (long long) temp_sum);
    // Answer is 67450 at 183 index

    // Close the input file
    fclose(fp);

    return 0;
}
