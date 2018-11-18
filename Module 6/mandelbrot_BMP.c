// sample unit tests for the escapeSteps function

// to run these tests:
//   1. rename or comment out the main function in mandelbrot.c
//   2. compile the tests using
//     gcc -Wall -Werror -O -std=c99 -o mandelbrotTest mandelbrot.c mandelbrotTest.c
//   3. run mandelbrotTest

// richard buckland
// 29 april 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL (BYTES_PER_PIXEL*8)
#define NUMBER_PLANES 1
#define PIX_PER_METRE 2835
#define MAGIC_NUMBER 0x4d42
#define NO_COMPRESSION 0
#define OFFSET 54
#define DIB_HEADER_SIZE 40
#define NUM_COLORS 0

#define COLOUR_WHITE 255
#define COLOUR_BLACK 0

#define BMP_FILE "mandelbrot.bmp"

typedef unsigned char  bits8;
typedef unsigned short bits16;
typedef unsigned int   bits32;

#define SIZE 512
#define PLANE_SIZE 4 
int escapeSteps(double x, double y);
void writeHeader (FILE *file);

int main(int argc, char* argv[]){

	FILE *outputFile;
	
	outputFile = fopen(BMP_FILE, "wb");
	
	writeHeader(outputFile);
	
    double x = PLANE_SIZE / -2;
    double y = PLANE_SIZE / 2;
    while (y > PLANE_SIZE / -2) {
        x = PLANE_SIZE / -2;
        while (x < PLANE_SIZE / 2){
            if (escapeSteps(x, y) >= 255){
				bits8 byte = COLOUR_BLACK;
                fwrite (&byte, sizeof byte, 1, outputFile);
				fwrite (&byte, sizeof byte, 1, outputFile);
				fwrite (&byte, sizeof byte, 1, outputFile);
            } else {
				bits8 byte = COLOUR_WHITE;
                fwrite (&byte, sizeof byte, 1, outputFile);
				fwrite (&byte, sizeof byte, 1, outputFile);
				fwrite (&byte, sizeof byte, 1, outputFile);
            }
            x += 0.0078125;
        }
        y -= 0.0078125;
    }
	
	fclose(outputFile);
    return EXIT_SUCCESS;
}

int escapeSteps(double x, double y) {
   double r = 0;
   double i = 0;
   double nextR;
   double nextI;
   double iterations = 0;

   while ((r*r + i*i <= 4) && (iterations < 256)) {
        nextR = r*r - i*i + x;
        nextI = 2*r*i + y;

        r = nextR;
        i = nextI;

        iterations++; //counts how many iterations it takes
    }

    return iterations;
}


void writeHeader (FILE *file) {
   assert(sizeof (bits8) == 1);
   assert(sizeof (bits16) == 2);
   assert(sizeof (bits32) == 4);
 
   bits16 magicNumber = MAGIC_NUMBER;
   fwrite (&magicNumber, sizeof magicNumber, 1, file);
 
   bits32 fileSize = OFFSET + (SIZE * SIZE * BYTES_PER_PIXEL);
   fwrite (&fileSize, sizeof fileSize, 1, file);
 
   bits32 reserved = 0;
   fwrite (&reserved, sizeof reserved, 1, file);
 
   bits32 offset = OFFSET;
   fwrite (&offset, sizeof offset, 1, file);
 
   bits32 dibHeaderSize = DIB_HEADER_SIZE;
   fwrite (&dibHeaderSize, sizeof dibHeaderSize, 1, file);
 
   bits32 width = SIZE;
   fwrite (&width, sizeof width, 1, file);
 
   bits32 height = SIZE;
   fwrite (&height, sizeof height, 1, file);
 
   bits16 planes = NUMBER_PLANES;
   fwrite (&planes, sizeof planes, 1, file);
 
   bits16 bitsPerPixel = BITS_PER_PIXEL;
   fwrite (&bitsPerPixel, sizeof bitsPerPixel, 1, file);
 
   bits32 compression = NO_COMPRESSION;
   fwrite (&compression, sizeof compression, 1, file);
 
   bits32 imageSize = (SIZE * SIZE * BYTES_PER_PIXEL);
   fwrite (&imageSize, sizeof imageSize, 1, file);
 
   bits32 hResolution = PIX_PER_METRE;
   fwrite (&hResolution, sizeof hResolution, 1, file);
 
   bits32 vResolution = PIX_PER_METRE;
   fwrite (&vResolution, sizeof vResolution, 1, file);
 
   bits32 numColors = NUM_COLORS;
   fwrite (&numColors, sizeof numColors, 1, file);
 
   bits32 importantColors = NUM_COLORS;
   fwrite (&importantColors, sizeof importantColors, 1, file);
}
