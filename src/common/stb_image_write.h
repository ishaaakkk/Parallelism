/* Minimal stub of stb_image_write.h to support headless builds.
 * Provides a trivial implementation of stbi_write_png when
 * STB_IMAGE_WRITE_IMPLEMENTATION is defined by the including file.
 */
#ifndef STB_IMAGE_WRITE_H
#define STB_IMAGE_WRITE_H

#ifdef __cplusplus
extern "C" {
#endif

int stbi_write_png(const char *filename, int w, int h, int comp, const void *data, int stride_in_bytes);

#ifdef __cplusplus
}
#endif

#ifdef STB_IMAGE_WRITE_IMPLEMENTATION
#include <stdio.h>
int stbi_write_png(const char *filename, int w, int h, int comp, const void *data, int stride_in_bytes)
{
    (void)filename; (void)w; (void)h; (void)comp; (void)data; (void)stride_in_bytes;
    /* Minimal stub: pretend we wrote the image successfully. */
    return 1;
}
#endif

#endif /* STB_IMAGE_WRITE_H */
