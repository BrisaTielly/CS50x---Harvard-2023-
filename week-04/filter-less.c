#include "helpers.h"
#include <math.h>




void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    
    

    float average_color;
    
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            average_color = (image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.0;
            
            image[j][i].rgbtBlue = round(average_color);
            image[j][i].rgbtGreen = round(average_color);
            image[j][i].rgbtRed = round(average_color);
        }
    }

    return;
}


void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    

    
    

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            
            int sepiaRed = round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue);
            
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            
            int sepiaGreen = round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue);
            
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            
            int sepiaBlue = round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue);
            
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            
            image[j][i].rgbtBlue = sepiaBlue;
            image[j][i].rgbtGreen = sepiaGreen;
            image[j][i].rgbtRed = sepiaRed;
        }
    }
    return;
}


void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE current_row;
    
    for (int i = 0; i < width - (width / 2); i++)
    {
        for (int j = 0; j < height; j++)
        {

            current_row = image[j][i];
            image[j][i] = image[j][width - i - 1];
            image[j][width - i - 1] = current_row;
        }
    }
    return;
}


void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    

    
    RGBTRIPLE copy[height][width];

    
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            copy[j][i] = image[j][i];
        }
    }

    
    
    
    
    
    
    

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {

            float counter = 0;
            float blue_sum = 0;
            float green_sum = 0;
            float red_sum = 0;

            
            if (j - 1 >= 0 && i >= 0)
            {
                blue_sum += copy[j - 1][i].rgbtBlue;
                green_sum += copy[j - 1][i].rgbtGreen;
                red_sum += copy[j - 1][i].rgbtRed;
                counter++;
            }
            
            if (j - 1 >= 0 && i - 1 >= 0)
            {
                blue_sum += copy[j - 1][i - 1].rgbtBlue;
                green_sum += copy[j - 1][i - 1].rgbtGreen;
                red_sum += copy[j - 1][i - 1].rgbtRed;
                counter++;
            }

            
            if (j < height && i - 1 >= 0)
            {
                blue_sum += copy[j][i - 1].rgbtBlue;
                green_sum += copy[j][i - 1].rgbtGreen;
                red_sum += copy[j][i - 1].rgbtRed;
                counter++;
            }

            
            if (j < height && i >= 0)
            {
                blue_sum += copy[j][i].rgbtBlue;
                green_sum += copy[j][i].rgbtGreen;
                red_sum += copy[j][i].rgbtRed;
                counter++;
            }

            
            if (j - 1 >= 0 && i + 1 < width && i + 1 >= 0)
            {
                blue_sum += copy[j - 1][i + 1].rgbtBlue;
                green_sum += copy[j - 1][i + 1].rgbtGreen;
                red_sum += copy[j - 1][i + 1].rgbtRed;
                counter++;
            }

            
            if (j < height && i + 1 >= 0 && i + 1 < width)
            {
                blue_sum += copy[j][i + 1].rgbtBlue;
                green_sum += copy[j][i + 1].rgbtGreen;
                red_sum += copy[j][i + 1].rgbtRed;
                counter++;
            }

            
            if (j + 1 < height && j + 1 >= 0 && i >= 0)
            {
                blue_sum += copy[j + 1][i].rgbtBlue;
                green_sum += copy[j + 1][i].rgbtGreen;
                red_sum += copy[j + 1][i].rgbtRed;
                counter++;
            }

            
            if (j + 1 < height && j + 1 >= 0 && i - 1 >= 0)
            {
                blue_sum += copy[j + 1][i - 1].rgbtBlue;
                green_sum += copy[j + 1][i - 1].rgbtGreen;
                red_sum += copy[j + 1][i - 1].rgbtRed;
                counter++;
            }

            
            
            if (j + 1 < height && i + 1 < width)
            {
                blue_sum += copy[j + 1][i + 1].rgbtBlue;
                green_sum += copy[j + 1][i + 1].rgbtGreen;
                red_sum += copy[j + 1][i + 1].rgbtRed;
                counter++;
            }

            
            int blue_avg = round(blue_sum / counter);
            
            if (blue_avg > 255)
            {
                blue_avg = 255;
            }

            int green_avg = round(green_sum / counter);
            
            if (green_avg > 255)
            {
                green_avg = 255;
            }

            int red_avg = round(red_sum / counter);
            
            if (red_avg > 255)
            {
                red_avg = 255;
            }

            
            image[j][i].rgbtBlue = blue_avg;
            image[j][i].rgbtGreen = green_avg;
            image[j][i].rgbtRed = red_avg;
        }
    }

    return;
}