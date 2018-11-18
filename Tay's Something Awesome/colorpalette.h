//colorpalette.h

//legit this whole chunk is from the chessboard code
//(they gave us write header for the bmp file)
#define BYTES_PER_PIXEL 3
#define BITS_PER_PIXEL (BYTES_PER_PIXEL*8)
#define NUMBER_PLANES 1
#define PIX_PER_METRE 2835
#define MAGIC_NUMBER 0x4d42
#define NO_COMPRESSION 0
#define OFFSET 54
#define DIB_HEADER_SIZE 40
#define NUM_COLORS 0
#define COLORS_IN_PALETTE 6
#define GREY 190

#define SIZE 128
#define BMP_FILE "colorpalette.bmp"
typedef unsigned char  bits8;
typedef unsigned short bits16;
typedef unsigned int   bits32;

void writeHeader (FILE *file);
void writeMonthColor (FILE *outputFile, int month);
void writeDayColor (FILE *outputFile, int day, int month);
void writeYearColor (FILE *outputFile, int year, int month);
void writeCloseishColor (FILE *outputFile, int month);
void writeHeckingCloseColor (FILE *outputFile, int month, int year);
void writeGrey (FILE *outputFile);

unsigned char stepsToRed (int steps);
unsigned char stepsToBlue (int steps);
unsigned char stepsToGreen (int steps);
