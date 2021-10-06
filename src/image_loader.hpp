// author: Colin Seifer
// file: image_loader.hpp
// description: holds stb_image.h

#ifndef IMAGE_LOADER_HPP
#define IMAGE_LOADER_HPP

class Image_Loader{
public:
    static unsigned char * Load_Image(const char *fn, int *width, int *height, bool noflip = false);
    static void Free_Image(unsigned char *img);
};

#endif