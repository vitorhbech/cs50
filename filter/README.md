# Filter — Image Processing in C

This project implements several image filters by manipulating pixel data in BMP images.

The program applies transformations directly to image pixels using algorithms implemented in C. Starter code for reading and writing BMP files was provided by the CS50 course staff. Algorithm implementations in helpers.c were developed by me.

## Implemented Filters

### Grayscale
Converts the image to shades of gray by averaging the RGB values of each pixel.

### Reflect
Mirrors the image horizontally by swapping pixels across the vertical axis.

### Blur
Applies a box blur effect by averaging the values of neighboring pixels.

## Concepts Practiced

- 2D arrays
- image processing algorithms
- memory manipulation in C