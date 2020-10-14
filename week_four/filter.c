// =====================================================================================================

// Code part of other code in cs50x directory, other code was written by cs50x staff and is not included

// =====================================================================================================
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Access each individual pixel
    for (int row = 0; row < height; row ++)
    {
        for (int col = 0; col < width; col++)
        {
            double red = image[row][col].rgbtRed;
            double blue = image[row][col].rgbtBlue;
            double green = image[row][col].rgbtGreen;
            // calculate average of blue, green, and red values
            double avg = (blue + green + red) / 3.0;
            int roundedAvg = round(avg);

            // Set blue, green, and red to same average value to get shade of grey
            image[row][col].rgbtRed = roundedAvg;
            image[row][col].rgbtBlue = roundedAvg;
            image[row][col].rgbtGreen = roundedAvg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Access each individual pixel
    for (int row = 0; row < height; row ++)
    {
        for (int col = 0; col < width; col++)
        {
            double originalRed = image[row][col].rgbtRed;
            double originalGreen = image[row][col].rgbtGreen;
            double originalBlue = image[row][col].rgbtBlue;

            // Algorithm for sepia shade of each color value
            double sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            double sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            double sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            int roundedSepiaRed = round(sepiaRed);
            int roundedSepiaGreen = round(sepiaGreen);
            int roundedSepiaBlue = round(sepiaBlue);

            // If any vals go over 255, set val to 255
            if (roundedSepiaRed > 255)
            {
                roundedSepiaRed = 255;
            }
            if (roundedSepiaGreen > 255)
            {
                roundedSepiaGreen = 255;
            }
            if (roundedSepiaBlue > 255)
            {
                roundedSepiaBlue = 255;
            }

            image[row][col].rgbtRed = roundedSepiaRed;
            image[row][col].rgbtGreen = roundedSepiaGreen;
            image[row][col].rgbtBlue = roundedSepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Use nested loop to get to target pixel
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width / 2; col++)
        {
            RGBTRIPLE temp = image[row][col];
            image[row][col] = image[row][width - (1 + col)];
            image[row][width - (1 + col)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];
    //make copy of original array to preserve values
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            copy[row][col] = image[row][col];
        }
    }

    // Use nested loop to get to target pixel
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            RGBTRIPLE target = copy[row][col];
            float count = 0.0;
            double totalRed = 0.0;
            double totalGreen = 0.0;
            double totalBlue = 0.0;

            // Find all border pixels
            for (int i = -1; i < 2; i++)
            {
                //check that row + i still exists in graph
                if (row + i < height && row + i >= 0)
                {

                    //if column + 1 is less than width, set right val and add to total
                    if (col + 1 < width)
                    {
                        RGBTRIPLE right = copy[row + i][col + 1];
                        totalRed += right.rgbtRed;
                        totalGreen += right.rgbtGreen;
                        totalBlue += right.rgbtBlue;
                        count++;
                    }

                    //if col - 1 is greater than or equal to 0, set left val and add to total
                    if (col - 1 >= 0)
                    {
                        RGBTRIPLE left = copy[row + i][col - 1];
                        totalRed += left.rgbtRed;
                        totalGreen += left.rgbtGreen;
                        totalBlue += left.rgbtBlue;
                        count++;
                    }

                    // set center value
                    RGBTRIPLE center = copy[row + i][col];
                    totalRed += center.rgbtRed;
                    totalGreen += center.rgbtGreen;
                    totalBlue += center.rgbtBlue;
                    count++;

                }
            }

            int avgRed = round((float)totalRed / count);
            int avgGreen = round((float)totalGreen / count);
            int avgBlue = round((float)totalBlue / count);

            avgRed %= 255;
            avgGreen %= 255;
            avgBlue %= 255;

            image[row][col].rgbtRed = avgRed;
            image[row][col].rgbtGreen = avgGreen;
            image[row][col].rgbtBlue = avgBlue;
        }
    }
    return;
}
