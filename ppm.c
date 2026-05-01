#include "ppm.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sys/mman.h>


ppmimage *ppm_readimage(const char *filename){
    FILE *file = fopen(filename, "rb");
    if(file == NULL) {
        perror("Error : Couldn't open file");
        return NULL;
    }

    //get the file size 
    fseek(file, 0, SEEK_END);
    size_t filesize = ftell(file);


    //get file descriptor
    int file_desc = fileno(file);

    //go back to the beginning of the file
    rewind(file);

    ppimage *result = malloc(sizeof *result);

    // get magic number (p6)
    char type[3] = {0};
    fscanf(file, "%2s", type);
    if (strcmp(type, "P6") != 0){
        perror("This is not a P6 PPM file!!!!");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%u %u", &(result->cols), &(result->rows));
    fscanf(file, "%u", &(result->maxval));

    off_t offset = ftell(file);

    //mapping the file into the memory (basically storing)
    uint8_t *rawdat = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, file_desc, 0);

    if(rawdata == MAP_FAILED){
        perror("mmap error");
        fclose(file);
        free(result);
        return NULL;
    }


    // how many bytes per color value
    uint8_t bytes_per_value = (result->maxval > 256 ? 2 : 1);
    const int values_per_pixel = 3;

    uint8_t *pixeldata = rawdata + offset + 1;

    result->pixels = calloc(result->rows, sizeof(pixel*));
    for(int y=0; y < result->rows; y++){
        result->pixels[y] = calloc(result->cols, sizeof(pixel));
        for(int x = 0; x < result->cols; x++) {
            uint8_t *pixel_start = pixeldata + (y * result->cols * values_per_value * bytes_per_value)
            
        }
    }

}   

void ppm_destroy(ppmimage* image){

}

void ppm_writeimage(const char *filename, ppmimage *image){

}