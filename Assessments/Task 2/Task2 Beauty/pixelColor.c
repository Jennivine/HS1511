//cute pink one
#include "pixelColor.h"

#define MAX_STEPS 256
#define MAGIC_NUMBER 65

unsigned char stepsToRed (int steps) {
    return 255;
}


unsigned char stepsToBlue (int steps) {
    return ((steps*6*MAGIC_NUMBER) % (MAX_STEPS - 60) + 40);
}


unsigned char stepsToGreen (int steps) {
    return ((steps*7*MAGIC_NUMBER) % (MAX_STEPS - 20));
}
