#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"head.h"


void replace() {
    char filename[] = "./files/read.txt";
    char word_to_replace[] = "Jigar";
    char replacement_word[] = "JIGAR";
    FILE *file;
    char line[256];
    int byte_position;

    // Use grep to find byte positions of the word
    char grep_command[256];
    sprintf(grep_command, "grep -abo %s %s", word_to_replace, filename);
    FILE *grep_output = popen(grep_command, "r");

    // Read byte positions from grep output
    while (fgets(line, sizeof(line), grep_output)) {
        sscanf(line, "%d:", &byte_position);

        // Open file for reading and writing
        file = fopen(filename, "r+");
        if (file == NULL) {
            perror("Error opening file");
		exit(1);
        }

        // Seek to the byte position
        fseek(file, byte_position, SEEK_SET);

        // Replace the word
        fputs(replacement_word, file);

        // Close the file
        fclose(file);
    }

    pclose(grep_output);

}

