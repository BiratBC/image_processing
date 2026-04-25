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
    

}

void ppm_destroy(ppmimage* image){

}

void ppm_writeimage(const char *filename, ppmimage *image){

}