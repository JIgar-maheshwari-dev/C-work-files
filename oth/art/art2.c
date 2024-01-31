#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>

#define RESIZED_WIDTH 100
#define RESIZED_HEIGHT 100

// Function to read and decode the JPG image
void readJpgImage(char *filename, unsigned char image[RESIZED_HEIGHT][RESIZED_WIDTH], int *width, int *height) {
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

// Function to resize the image while maintaining aspect ratio
void resizeImage(unsigned char original[RESIZED_HEIGHT][RESIZED_WIDTH], unsigned char resized[RESIZED_HEIGHT][RESIZED_WIDTH], int originalWidth, int originalHeight) {
    double aspectRatio = (double)originalWidth / (double)originalHeight;
    int newWidth, newHeight;

    if (aspectRatio >= 1) {
        newWidth = RESIZED_WIDTH;
        newHeight = (int)(RESIZED_WIDTH / aspectRatio);
    } else {
        newWidth = (int)(RESIZED_HEIGHT * aspectRatio);
        newHeight = RESIZED_HEIGHT;
    }

    for (int i = 0; i < newHeight; i++) {
        for (int j = 0; j < newWidth; j++) {
            int originalX = (int)((double)j / (double)newWidth * (double)originalWidth);
            int originalY = (int)((double)i / (double)newHeight * (double)originalHeight);
            resized[i][j] = original[originalY][originalX];
        }
    }
}

// Function to convert grayscale value to ASCII character
char intensityToAscii(unsigned char intensity) {
    char asciiChars[] = " .:-=+*#%@";
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
    unsigned char original[RESIZED_HEIGHT][RESIZED_WIDTH];
    unsigned char resized[RESIZED_HEIGHT][RESIZED_WIDTH];
    int originalWidth, originalHeight;

    readJpgImage(filename, original, &originalWidth, &originalHeight);
    resizeImage(original, resized, originalWidth, originalHeight);
    printf("Resized image dimensions: %d x %d\n", RESIZED_WIDTH, RESIZED_HEIGHT);
    printAsciiArt(resized, RESIZED_WIDTH, RESIZED_HEIGHT);

    return 0;
}

