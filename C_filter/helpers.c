#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average =
                ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0) + 0.5;
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
    int sepiaBlue = 0;
    int sepiaGreen = 0;
    int sepiaRed = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaBlue = (0.131 * image[i][j].rgbtBlue + 0.534 * image[i][j].rgbtGreen +
                         0.272 * image[i][j].rgbtRed) +
                        0.5;
            sepiaGreen = (0.168 * image[i][j].rgbtBlue + 0.686 * image[i][j].rgbtGreen +
                          0.349 * image[i][j].rgbtRed) +
                         0.5;
            sepiaRed = (0.189 * image[i][j].rgbtBlue + 0.769 * image[i][j].rgbtGreen +
                        0.393 * image[i][j].rgbtRed) +
                       0.5;
            if (sepiaBlue < 256)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }

            if (sepiaGreen < 256)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (sepiaRed < 256)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reversed_row[width];
    for (int i = 0; i < height; i++)
    {
        // iteration on the half of the line to exchange the pixels
        for (int j = 0; j < width / 2; j++)
        {
            // saving the row into a temp file
            RGBTRIPLE temp = image[i][j];
            // reversing the first half
            image[i][j] = image[i][width - j - 1];
            // reversing the second half
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // iterate over each pixel to edit their value
    for (int col = 0; col < height; col++)
    {
        for (int row = 0; row < width; row++)
        {
            // Create a divider to divide by the number of pixel detected around the one to modify
            float divider = 0;
            int averageBlue = 0;
            int averageGreen = 0;
            int averageRed = 0;

            // iterate for each pixel around
            for (int i = col - 1; i <= col + 1; i++)
            {
                for (int j = row - 1; j <= row + 1; j++)
                {
                    // Ensure the pixel is not out of range
                    if (i >= 0 && i < height && j >= 0 && j < width)
                    {
                        // addition of all the value of the untouched copy
                        averageBlue += copy[i][j].rgbtBlue;
                        averageGreen += copy[i][j].rgbtGreen;
                        averageRed += copy[i][j].rgbtRed;
                        divider++;
                    }
                }
            }
            // calculate average and update the value in the image and round to the nearest integer
            averageBlue = (averageBlue / divider) + 0.5;
            averageGreen = (averageGreen / divider) + 0.5;
            averageRed = (averageRed / divider) + 0.5;
            // update  the image
            image[col][row].rgbtBlue = averageBlue;
            image[col][row].rgbtGreen = averageGreen;
            image[col][row].rgbtRed = averageRed;
        }
    }
    return;
}
