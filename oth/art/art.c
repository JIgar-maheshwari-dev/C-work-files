#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>

#define ORIGINAL_WIDTH 720
#define ORIGINAL_HEIGHT 720
#define RESIZED_WIDTH 100
#define RESIZED_HEIGHT 100

// Function to read and decode the JPG image
void readJpgImage(char *filename, unsigned char image[ORIGINAL_HEIGHT][ORIGINAL_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s.", filename);
        exit(1);
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;

    unsigned char *buffer = (unsigned char *)malloc(cinfo.output_width * cinfo.output_components);

    int row = 0;
    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        for (int i = 0; i < cinfo.output_width; i++) {
            image[row][i] = buffer[i * cinfo.output_components]; // Assuming grayscale
        }
        row++;
    }

    free(buffer);
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(file);
}

// Function to resize the image
void resizeImage(unsigned char original[ORIGINAL_HEIGHT][ORIGINAL_WIDTH], unsigned char resized[RESIZED_HEIGHT][RESIZED_WIDTH]) {
    for (int i = 0; i < RESIZED_HEIGHT; i++) {
        for (int j = 0; j < RESIZED_WIDTH; j++) {
            int sum = 0;
            for (int k = 0; k < ORIGINAL_HEIGHT / RESIZED_HEIGHT; k++) {
                for (int l = 0; l < ORIGINAL_WIDTH / RESIZED_WIDTH; l++) {
                    sum += original[i * (ORIGINAL_HEIGHT / RESIZED_HEIGHT) + k][j * (ORIGINAL_WIDTH / RESIZED_WIDTH) + l];
                }
            }
            resized[i][j] = sum / (ORIGINAL_HEIGHT / RESIZED_HEIGHT * ORIGINAL_WIDTH / RESIZED_WIDTH);
        }
    }
}

// Function to convert grayscale value to ASCII character
char intensityToAscii(unsigned char intensity) {
    char asciiChars[] = " .,-:;i1tfLCG08@";
    int numChars = strlen(asciiChars);
    return asciiChars[intensity * numChars / 256];
}

// Function to print ASCII art of the image
void printAsciiArt(unsigned char image[RESIZED_HEIGHT][RESIZED_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", intensityToAscii(image[i][j]));
        }
        printf("\n");
    }
}

int main() {
    char filename[] = "image.jpg"; // Change this to your image file
    unsigned char original[ORIGINAL_HEIGHT][ORIGINAL_WIDTH];
    unsigned char resized[RESIZED_HEIGHT][RESIZED_WIDTH];
    int width, height;

    readJpgImage(filename, original, &width, &height);
    resizeImage(original, resized);
    printf("Resized image dimensions: %d x %d\n", RESIZED_WIDTH, RESIZED_HEIGHT);
    printAsciiArt(resized, RESIZED_WIDTH, RESIZED_HEIGHT);

    return 0;
}

