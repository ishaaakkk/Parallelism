/* Minimal mandelbrot GUI header (stub) used for headless builds.
 * Provides prototypes for setup() and interact() expected by the lab code.
 */
#ifndef MANDELBROT_GUI_H
#define MANDELBROT_GUI_H

#include <X11/Xlib.h>
#include <assert.h>

int setup(int width, int height, Display **display, Window *win, GC *gc, long *min_color, long *max_color);
void interact(Display *display, Window *win, int width, int height, double real_min, double real_max, double imag_min, double imag_max);

#endif /* MANDELBROT_GUI_H */
