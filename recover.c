#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    //accept only one command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //define byte
    typedef uint8_t byte;

    //define variables
    byte block[512];
    char image[100];
    bool jpeg_found = false;
    bool initial_jpeg = false;
    FILE *output;
    int jpeg_count = 0;

    //check if file is blank
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    else
    {
        //read file
        while (fread(block, sizeof(byte), 512, input))
        {
            //check if it is start of jpeg
            if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
            {
                jpeg_found = true;
                if (jpeg_count == 0)
                {
                    initial_jpeg = true;
                }
                else if (jpeg_count > 0)
                {
                    fclose(output);
                }

                //open new file and copy initial jpeg block into it
                sprintf(image, "%03i.jpg", jpeg_count);
                output = fopen(image, "w");
                fwrite(block, sizeof(byte), 512, output);
                jpeg_count++;
            }

            //continue writing jpeg to file
            else if (jpeg_count > 0)
            {
                fwrite(block, sizeof(byte), 512, output);
            }
        }

        //close all files
        fclose(input);
        fclose(output);
        return 0;
    }
}


