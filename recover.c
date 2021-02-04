#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    typedef uint8_t byte;
    byte block[512];
    char image[100];
    bool jpeg_found = false;
    FILE *output;
    int jpeg_count = 0;

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    else
    {
        while(fread(block, sizeof(byte), 512, input))
        {
            if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] &0xf0) == 0xe0)
            {
                if(jpeg_count == 0)
                {
                    sprintf(image, "%03i.jpg", jpeg_count);
                    output = fopen(image, "w");
                    fwrite(block, sizeof(block), 1, output);
                    jpeg_count++;
                }
                else if(jpeg_count > 0)
                {
                    fclose(output);
                    sprintf(image, "%03i.jpg", jpeg_count);
                    output = fopen(image, "w");
                    fwrite(block, sizeof(block), 1, output);
                    jpeg_count++;
                }
            }

            else if (jpeg_count > 0)
            {
                output = fopen(image, "a");
                fwrite(block, sizeof(block), 1, output);
            }
        }

        fclose(input);
        fclose(output);
        return 0;
    }
}



