//tay ur actual bae xxx
//something awesome?
//help my soul

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>
#include "colorpalette.h"

int main(int argc, char *argv[]){
    //asks user for birthday!
    printf("**************\n");
    printf("write your birthday in the form day/month/year (in numbers): ");
    int day = 0;
    int month = 0;
    int year = 0;
    //read their bday in and put the values into day, month, year
    scanf("%d/%d/%d", &day, &month, &year);
    //check that they actually put stuff in (and in the right place)
    assert(day != 0);
    assert(month != 0);
    assert(year != 0);
    //initiating file pointer
    FILE *outputFile;
    outputFile = fopen(BMP_FILE, "wb");
    //writing the bmp file (using code from chessboard)
    writeHeader(outputFile);

    int col = 1;
    int row = 1;
        while (row <= SIZE){
            while (col <= SIZE){
                writeDayColor (outputFile, day, month);
                col++;
            }
            col = 1;
            while (col <= SIZE){
                writeMonthColor (outputFile, month);
                col++;
            }
            col = 1;
            while (col <= SIZE){
                writeYearColor (outputFile, year, month);
                col++;
            }
            col = 1;
            while (col <= SIZE){
                writeHeckingCloseColor (outputFile, month, year);
                col++;
            }
            col = 1;
            while (col <= SIZE){
                writeCloseishColor (outputFile, month);
                col++;
            }
            col = 1;
            while (col <= SIZE){
                writeGrey (outputFile);
                col++;
            }
            col = 1;

            row++;
        }

    fclose(outputFile);
    printf("**************\n");
    printf("check it out! (it's called colorpalette.bmp)\n");
    printf("if you don't like it, get a new birthday lmao\n");
    printf("**************\n\n");
    return EXIT_SUCCESS;
}

void writeHeader (FILE *file) {
    //lowkey the code from chessboard because the header file is yuckkkk
    //width was like the only thing I changed
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

    //yeah I just changed the width according to how many colours I wanted
    //in my colourpalette
    bits32 width = COLORS_IN_PALETTE * SIZE;
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

unsigned char stepsToRed (int month) {
    //hardcoding red brightness values for colours I want for each month
    int red = 0;
    if (month == 1){
        red = 255;
    } else if (month == 2){
        red = 255;
    } else if (month == 3){
        red = 255;
    } else if (month == 4){
        red = 255;
    } else if (month == 5){
        red = 255;
    } else if (month == 6){
        red = 235;
    } else if (month == 7){
        red = 210;
    } else if (month == 8){
        red = 212;
    } else if (month == 9){
        red = 212;
    } else if (month == 10){
        red = 212;
    } else if (month == 11){
        red = 216;
    } else if (month == 12){
        red = 252;
    } else {
        //makes grey to show if I'm doing something wrong
        red = 100;
    }
    return red;
}

unsigned char stepsToGreen (int month) {
    //hardcoding green brightness values for colours I want for each month
    int green = 0;
    if (month == 1){
        green = 243;
    } else if (month == 2){
        green = 231;
    } else if (month == 3){
        green = 214;
    } else if (month == 4){
        green = 195;
    } else if (month == 5){
        green = 207;
    } else if (month == 6){
        green = 209;
    } else if (month == 7){
        green = 203;
    } else if (month == 8){
        green = 227;
    } else if (month == 9){
        green = 246;
    } else if (month == 10){
        green = 255;
    } else if (month == 11){
        green = 255;
    } else if (month == 12){
        green = 255;
    } else {
        //makes grey to show if I'm doing something wrong
        green = 100;
    }
    return green;
}

unsigned char stepsToBlue (int month) {
    //hardcoding blue brightness values for colours I want for each month
    int blue = 0;
    if (month == 1){
        blue = 196;
    } else if (month == 2){
        blue = 196;
    } else if (month == 3){
        blue = 193;
    } else if (month == 4){
        blue = 212;
    } else if (month == 5){
        blue = 254;
    } else if (month == 6){
        blue = 255;
    } else if (month == 7){
        blue = 255;
    } else if (month == 8){
        blue = 255;
    } else if (month == 9){
        blue = 255;
    } else if (month == 10){
        blue = 228;
    } else if (month == 11){
        blue = 204;
    } else if (month == 12){
        blue = 200;
    } else {
        //makes grey to show if I'm doing something wrong
        blue = 100;
    }
    return blue;
}

void writeDayColor (FILE *outputFile, int day, int month){
    bits8 red;
    bits8 green;
    bits8 blue;
    red = stepsToRed(month);
    green = stepsToGreen(month);
    blue = stepsToBlue(month);

    int darken;
    //day number determines the darkness
    darken = day * 5;
    //yeah lol my bday is on the 26th so that's why I used it as a magic number
    darken = darken % 26;
    if (darken == 0){
        //yeah another magic number but that's my bday month :)
        darken = 8;
    }

    red = red - darken;
    blue = blue - darken;
    green = green - darken;

    //write them into the bmp file
    fwrite (&blue, sizeof blue, 1, outputFile);
    fwrite (&green, sizeof green, 1, outputFile);
    fwrite (&red, sizeof red, 1, outputFile);
}

void writeMonthColor (FILE *outputFile, int month){
    bits8 red;
    bits8 green;
    bits8 blue;
    red = stepsToRed(month);
    green = stepsToGreen(month);
    blue = stepsToBlue(month);
    //when you write into a bmp file, the order is blue, green, red
    //(I had to search that up because I was getting some weird-ass colours
    // that I didn't pay for excuse me)
    fwrite (&blue, sizeof blue, 1, outputFile);
    fwrite (&green, sizeof green, 1, outputFile);
    fwrite (&red, sizeof red, 1, outputFile);
}

void writeYearColor (FILE *outputFile, int year, int month){
    //had to do all that stuff with 'redValue' because in a bmp,
    // the value is less than 255 and an unsigned char can't do anything
    // with higher values. It wraps around if I try to add anything to it,
    // and looks hella weird, so I had to make it an int and then
    // make it an unsigned char
    bits8 red;
    bits8 green;
    bits8 blue;
    int redValue;
    int greenValue;
    int blueValue;

    //get the colour values for the month
    redValue = stepsToRed(month);
    greenValue = stepsToGreen(month);
    blueValue = stepsToBlue(month);

    int lighten;
    //the year will determine the amount of lightness we get!
    lighten = year * 5;
    //26 is a magic number because I want it to go light and
    //that was a good number to go up by (lmao it's just the
    //date of my birthday and I'm vain)
    lighten = lighten % 26;
    //lol my bday strikes again (august lol!!!!)
    if (lighten == 0){
        lighten = 8;
    }

    redValue = redValue + lighten;
    blueValue = blueValue + lighten;
    greenValue = greenValue + lighten;

    //capping them off at max brightness (255)
    if (redValue >= 255){
        redValue = 255;
    }
    if (greenValue >= 255){
        greenValue = 255;
    }
    if (blueValue >= 255){
        blueValue = 255;
    }

    //change the values back into chars from ints
    red = redValue;
    green = greenValue;
    blue = blueValue;

    //write them into the bmp file
    fwrite (&blue, sizeof blue, 1, outputFile);
    fwrite (&green, sizeof green, 1, outputFile);
    fwrite (&red, sizeof red, 1, outputFile);
}

void writeCloseishColor (FILE *outputFile, int month){
    bits8 red;
    bits8 green;
    bits8 blue;
    //I want this colour to be somewhat closeish but a bit across the rainbow,
    //so I just made it the next month's colour!
    //Also I made it wrap around because I only have 12 month colours lol
    month = month + 1;
    if (month == 13){
        month = 1;
    }

    //get the month colours
    red = stepsToRed(month);
    green = stepsToGreen(month);
    blue = stepsToBlue(month);

    //write them into the bmp
    fwrite (&blue, sizeof blue, 1, outputFile);
    fwrite (&green, sizeof green, 1, outputFile);
    fwrite (&red, sizeof red, 1, outputFile);
}

void writeHeckingCloseColor (FILE *outputFile, int month, int year){
    //You know what, this is going to be even closer to my month colour
    //than my 'closeish color', it'll be an average!!!! yeet
    bits8 red1;
    bits8 green1;
    bits8 blue1;

    bits8 red2;
    bits8 green2;
    bits8 blue2;

    //get the month colour values
    red1 = stepsToRed(month);
    green1 = stepsToGreen(month);
    blue1 = stepsToBlue(month);

    //next month and wraparound the year
    month = month + 1;
    if (month == 13){
        month = 1;
    }

    //get the next month's colour values
    red2 = stepsToRed(month);
    green2 = stepsToGreen(month);
    blue2 = stepsToBlue(month);

    //now we average them bc I'm hecking extra!!!!
    red1 = (red1 + red2) / 2;
    green1 = (green1 + green2) / 2;
    blue1 = (blue1 + blue2) / 2;

    //guess what I'm not done
    //gonna make them lighter (according to the year value) bc um yes I like
    //aesthetic and pastels
    int lighten;
    int redValue = red1;
    int blueValue = blue1;
    int greenValue = green1;
    //(see function writeYearColour to see all my comments on making it lighter
    //using the year value input)
    lighten = year * 5;
    lighten = lighten % 26;
    //lol my bday strikes again (august lol!!!!)
    if (lighten == 0){
        lighten = 8;
    }

    redValue = redValue + lighten;
    blueValue = blueValue + lighten;
    greenValue = greenValue + lighten;

    //capping them off at max brightness (255)
    if (redValue >= 255){
        redValue = 255;
    }
    if (greenValue >= 255){
        greenValue = 255;
    }
    if (blueValue >= 255){
        blueValue = 255;
    }

    //turn the ints back into my fav chars xxxx (so they actually
    //fit in the bmp lol)
    red1 = redValue;
    green1 = greenValue;
    blue1 = blueValue;


    //write them into the bmp
    fwrite (&blue1, sizeof blue1, 1, outputFile);
    fwrite (&green1, sizeof green1, 1, outputFile);
    fwrite (&red1, sizeof red1, 1, outputFile);
}

void writeGrey (FILE *outputFile){
    //because every colour palette needs a neutral somewhere ahahaha
    bits8 red = GREY;
    bits8 green = GREY;
    bits8 blue = GREY;
    fwrite (&blue, sizeof blue, 1, outputFile);
    fwrite (&green, sizeof green, 1, outputFile);
    fwrite (&red, sizeof red, 1, outputFile);

}
