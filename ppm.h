#ifndef PPM_H
#define PPM_H

#include <stdint.h>
#include <stdbool.h>


typedef struct {
    uint16_t r, g, b;
} pixel;

typedef struct {
    unsigned int rows;
    unsigned int cols;
    unsigned int maxval; // biggest numeric value a pixel can have . for e.g 255 (color depth)

    pixel **pixels;

} ppmimage;

ppmimage *ppm_readimage(const char *filename);
void ppm_destroy(ppmimage* image);
void ppm_writeimage(const char *filename, ppmimage *image);


#endif