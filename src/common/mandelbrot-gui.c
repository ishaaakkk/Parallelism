/* Minimal stub implementations for GUI hooks. These are intentionally
 * simplistic so the code can compile and run in headless mode.
 */

#include "mandelbrot-gui.h"
#include <stdlib.h>

int setup(int width, int height, Display **display, Window *win, GC *gc, long *min_color, long *max_color)
{
    (void)width; (void)height;
    if (display) *display = NULL;
    if (win) *win = (Window)0;
    if (gc) *gc = (GC)0;
    if (min_color) *min_color = 0;
    if (max_color) *max_color = 0;
    /* Return EXIT_FAILURE to indicate no X11 display was opened. */
    return EXIT_FAILURE;
}

void interact(Display *display, Window *win, int width, int height, double real_min, double real_max, double imag_min, double imag_max)
{
    (void)display; (void)win; (void)width; (void)height;
    (void)real_min; (void)real_max; (void)imag_min; (void)imag_max;
    /* No interactive GUI in the headless stub. */
}
