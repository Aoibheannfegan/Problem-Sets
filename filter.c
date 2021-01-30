// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            
            int red = 0;
            int green = 0;
            int blue = 0;
            int counter = 0;
            
            if (h >= 0 && w >=0)
            {
                red += image[h][w].rgbtRed;
                green += image[h][w].rgbtGreen;
                blue += image[h][w].rgbtBlue;
                counter++;
            }
            if (h >= 0 && (w - 1) >=0)
            {
                red += image[h][w - 1].rgbtRed;
                green += image[h][w - 1].rgbtGreen;
                blue += image[h][w - 1].rgbtBlue;
                counter++;
            }
            if (h >= 0 && (w + 1) >=0)
            {
                red += image[h][w + 1].rgbtRed;
                green += image[h][w + 1].rgbtGreen;
                blue += image[h][w + 1].rgbtBlue;
                counter++;
            }
            if ((h + 1) >= 0 && w >=0)
            {
                red += image[h + 1][w].rgbtRed;
                green += image[h + 1][w].rgbtGreen;
                blue += image[h + 1][w].rgbtBlue;
                counter++;
            }
            if ((h + 1) >= 0 && (w + 1) >=0)
            {
                red += image[h + 1][w + 1].rgbtRed;
                green += image[h + 1][w + 1].rgbtGreen;
                blue += image[h + 1][w + 1].rgbtBlue;
                counter++;
            }
            if ((h + 1) >= 0 && (w - 1) >=0)
            {
                red += image[h + 1][w - 1].rgbtRed;
                green += image[h + 1][w - 1].rgbtGreen;
                blue += image[h + 1][w - 1].rgbtBlue;
                counter++;
            }
            if ((h - 1) >= 0 && (w - 1) >=0)
            {
                red += image[h - 1][w - 1].rgbtRed;
                green += image[h - 1][w - 1].rgbtGreen;
                blue += image[h - 1][w - 1].rgbtBlue;
                counter++;
            }
            if ((h - 1) >= 0 && (w + 1) >=0)
            {
                red += image[h - 1][w + 1].rgbtRed;
                green += image[h - 1][w + 1].rgbtGreen;
                blue += image[h - 1][w + 1].rgbtBlue;
                counter++;
            }
            if ((h - 1) >= 0 && w >=0)
            {
                red += image[h - 1][w].rgbtRed;
                green += image[h - 1][w].rgbtGreen;
                blue += image[h - 1][w].rgbtBlue;
                counter++;
            }
            
            image[h][w].rgbtRed = round (red / counter);
            image[h][w].rgbtGreen = round (green / counter);
            image[h][w].rgbtBlue = round (blue / counter);
            
        }
    }    
            
    return;
}    

//reflect image
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w <= (width/2); w++)
        {
            RGBTRIPLE first_pixel = image[h][w];
            RGBTRIPLE swap_pixel = image[h][width - w];
            image[h][w] = swap_pixel;
            image[h][width - w] = first_pixel;
        }
    }
    return;
}


