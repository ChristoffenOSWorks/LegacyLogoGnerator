/*
 * The fourth triangle that has color.
 *
 * This is the final revision by Gage Morgan, started on October 3rd, 2015, finished on
 * October 17, 2015. In this revision, this compilation serves as commented Cairo for examples 
 * on how to build with the Cairo library.
 */

#include "/usr/include/cairo/cairo.h"

int
main (int argc, char *argv[])
{
        cairo_surface_t *surface = //Sets the Cairo surface context
            cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 421, 410); //Creates Cairo image surface, sets image resolution.
        cairo_t *cr = //Declare *cr as a Cairo context.
            cairo_create (surface); //Sets the Cairo context as a pointer, *cr.

	/* Fourth triangle */
	cairo_set_source_rgb (cr, 0, 0.63, 0.90); //Sets the color of the triangle.
	cairo_line_to (cr, 376, 130); //Draws a line from Point A to Point B.
	cairo_line_to (cr, 304, 222); //Draws a line from Point B to Point C.
	cairo_line_to (cr, 290, 147); //Draws a line from Point C back to Point A.	
	cairo_close_path (cr); //Finishes the connections between Points A and C, closes off the figure.

	cairo_fill_preserve (cr); //Preserve fill so shape doesn't output as an outline.
	cairo_set_source_rgb (cr, 0, 0.63, 0.90); //Sets the color of the triangle (again)
	cairo_stroke (cr); //Draw the final shape

	/* Write output and clean up */
        cairo_surface_write_to_png (surface, "../images/triangle4-color.png"); //Name the resulting image as triangle4-color.png
        cairo_destroy (cr); //Destroy the context pointer, frees up memory and/or lag
        cairo_surface_destroy (surface); //Destroy the surface pointer, frees up memory and/or lag

        return 0; //No numbers needed!!
}


