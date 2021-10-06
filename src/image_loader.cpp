// author: Colin Seifer
// file: image_loader.hpp
// description: holds stb_image.h

#include "image_loader.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"
    
unsigned char * Image_Loader::Load_Image(const char *fn, int *width, int *height, bool noflip){
    // width and height of image
    int channels = 0;
    unsigned char *image;
    // load image
    if(!noflip){
        stbi_set_flip_vertically_on_load(true);
    }
    image = stbi_load(fn, width, height, &channels, 0);

    return image;
}

void Image_Loader::Free_Image(unsigned char *img){
    stbi_image_free(img);
}