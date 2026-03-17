#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate the average between rgb for each pixel then apply the value
            int average =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int max_8bit_value = 255;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        // applying the sepia algoritm
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = max_8bit_value;
            }
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = max_8bit_value;
            }
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = max_8bit_value;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // using a temp pixel to swap
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // set how many pixels where considerated
            // store rgb value
            int iterations = 0;
            float red = 0;
            float green = 0;
            float blue = 0;
            // iterate over each pixel around the main, then sum it to the rgb value
            for (int ii = (i - 1); ii <= (i + 1); ii++)
            {
                // conditionals for the edges
                if (ii < 0 || ii >= height)
                    continue;
                for (int jj = (j - 1); jj <= (j + 1); jj++)
                {
                    if (jj < 0 || jj >= width)
                    {
                        continue;
                    }
                    iterations++;
                    red += copy[ii][jj].rgbtRed;
                    green += copy[ii][jj].rgbtGreen;
                    blue += copy[ii][jj].rgbtBlue;
                }
            }
            // blur the rgb
            red = round(red / iterations);
            green = round(green / iterations);
            blue = round(blue / iterations);
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
