#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int jpegBlock = 512;
int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could'nt open file, please try again\n");
        return 2;
    }

    // Create a buffer for a block of data
    uint8_t buffer[jpegBlock];
    int count = 0;
    char filename[8];
    FILE *img = NULL;
    // While there's still data left to read from the memory card
    while (fread(buffer, sizeof(uint8_t), jpegBlock, card) == jpegBlock)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count);

            img = fopen(filename, "w");
            if (img == NULL)
            {
                return 2;
            }

            fwrite(buffer, sizeof(buffer), 1, img);
            count++;
        }
        else
        {
            if (img != NULL)
            {
                fwrite(buffer, sizeof(uint8_t), jpegBlock, img);
            }
        }
    }
    if (img != NULL)
        fclose(img);
    fclose(card);
    return 0;
}
