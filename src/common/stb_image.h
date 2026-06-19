/* Minimal stub of stb_image.h to support headless builds in the lab repository.
 * This is NOT the real stb_image implementation; it is a small compatibility
 * shim to allow compilation when the real headers are not present.
 */
#ifndef STB_IMAGE_H
#define STB_IMAGE_H

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned char *stbi_load(const char *filename, int *x, int *y, int *comp, int req_comp);
extern void stbi_image_free(void *retval_from_stbi_load);

#ifdef __cplusplus
}
#endif

#endif /* STB_IMAGE_H */
