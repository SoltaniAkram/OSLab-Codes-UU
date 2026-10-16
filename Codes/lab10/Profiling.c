//profiling.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 4096
#define LENGTH 4096
#define ITERATIONS 100

// Cache Unfriendly (column-major)
void bad_access_pattern(unsigned char *pixel) {
    unsigned char temp[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        temp[i] = pixel[i * WIDTH]; }  // big stride : cache-miss
}
// Cache Friendly (row-major)
void good_access_pattern(unsigned char *pixel) {
    unsigned char temp[WIDTH];
    for (int i = 0; i < WIDTH; i++) {
        temp[i] = pixel[i];  }          // sequential (cache-hit)
}
int main(int argc, char *argv[]) {
    unsigned char *image = malloc(WIDTH * LENGTH); // assign dynamic memory for the pixels
    memset(image, 128, WIDTH * LENGTH); // assign 128 to every pixel
    for (int iter = 0; iter < ITERATIONS; iter++) {
        if (iter % 2 == 0) {
            bad_access_pattern(image);      // results in cache miss
        } else {
            good_access_pattern(image);  }   // results in cache hit
        }
    free(image); // free the assigned memory
    return 0;   }
