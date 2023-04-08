#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float RGBgray;
    for (int i = 0; i < height; i++)
    {
        for (int z = 0; z < width; z++)
        {
            RGBgray = round((image[i][z].rgbtRed + image[i][z].rgbtGreen + image[i][z].rgbtBlue) /3.00);
            image[i][z].rgbtRed = RGBgray;
            image[i][z].rgbtGreen = RGBgray;
            image[i][z].rgbtBlue = RGBgray;
        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int blue;
    int green;
    int red;

    int original_red;
    int original_blue;
    int original_green;

    for(int i = 0; i < height; i++)
     {
        for(int z=0;z<width;z++)
    {
           original_red=image[i][z].rgbtRed;
           original_blue=image[i][z].rgbtBlue;
           original_green=image[i][z].rgbtGreen;

           red = round(0.393 * original_red + 0.769 * original_green + 0.189 * original_blue);
           if(red>255)
           {
             image[i][z].rgbtRed = 255;
           }
           else
           {
             image[i][z].rgbtRed = red;
           }
           green = round(0.349 * original_red + 0.686 * original_green + 0.168 * original_blue);
           if(green>255)
           {
             image[i][z].rgbtGreen=255;
           }
           else
           {
             image[i][z].rgbtGreen= green;
           }
            blue= round(0.272*original_red + 0.534 *original_green + 0.131*original_blue);
            if(blue>255)
            {
              image[i][z].rgbtBlue=255;
            }
            else
            {
              image[i][z].rgbtBlue = blue;
            }
       }
         }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int ref[3];
    for(int i=0;i<height;i++)
    {
        for(int z=0;z<width/2;z++){
        ref[0] = image[i][z].rgbtBlue;
        ref[1] = image[i][z].rgbtGreen;
        ref[2] = image[i][z].rgbtRed;

        image[i][z].rgbtBlue = image[i][width - z - 1].rgbtBlue;
        image[i][z].rgbtGreen = image[i][width - z - 1].rgbtGreen;
        image[i][z].rgbtRed = image[i][width - z - 1].rgbtRed;

        image[i][width - z - 1].rgbtBlue = ref[0];
        image[i][width - z - 1].rgbtGreen = ref[1];
        image[i][width - z - 1].rgbtRed = ref[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE you[height][width];
    for(int i=0;i<height;i++){
        for(int z=0;z<height;z++){
            int red=0;
            int green=0;
            int blue=0;
            float counter = 0.00;

            for(int x=-1;x<2;x++)
            {
                for(int y=-1;y<2;y++)
                {
                    int X=i+x;
                    int Y=z+y;

                if(X<0 || X>(height-1) || Y<0 || Y>(width-1)){
                    continue;
                }
                red += image[X][Y].rgbtRed;
                blue += image[X][Y].rgbtBlue;
                green += image[X][Y].rgbtGreen;
                counter++;
                }
                you[i][z].rgbtRed=round(red/counter);
                you[i][z].rgbtGreen=round(green/counter);
                you[i][z].rgbtBlue=round(blue/counter);
            }

        }
    }
for(int i=0;i<height;i++)
    {
    for(int z=0;z<height;z++)
    {
         image[i][z].rgbtRed = you[i][z].rgbtRed;
         image[i][z].rgbtGreen = you[i][z].rgbtGreen;
         image[i][z].rgbtBlue = you[i][z].rgbtBlue;
    }
    }
    return;
}