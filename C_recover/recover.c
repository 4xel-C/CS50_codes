// Read a memory card containing contiguous jpg images. read the binary extraction of the file and copy each jpg signature into new files incremented automaticly 
// to recover the photos inside the memory image 

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
    // recuperating file name from command line argument
    char *file = argv[1];

    // opening  file
    FILE *card = fopen(file, "r");
    if (card == NULL)
    {
        printf("COuld not open the file");
        return 1;
    }

    // Set output  file pionter to NULL
    FILE *img = NULL;

    // create buffer to read and sotre datas (on a 512 bytes buffer to store the blocks of data)
    uint8_t buffer[512];

    // create a counter to keep track of the filenames
    int counter = 0;

    // buffer to store formated string (only an array of 8 should be enough for "###.jpg"'/0')
    char string_buffer[8];

    while (fread(buffer, 1, 512, card))
    {
        // if find a new  jpg  file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Check if the output pointer img is pointing a file, in that case close this file to
            // open another one (Means that we are already writting in a file)
            if (img != NULL)
            {
                fclose(img);
            }

            //  Point the img pointer to a new file to write in, using sprintf to store the correct
            //  filename in string_buffer
            sprintf(string_buffer, "%03i.jpg", counter);
            counter++;
            img = fopen(string_buffer, "w");
            // Check if the file have been created correctly
            if (img == NULL)
            {
                printf("Could not have create the image");
                return 1;
            }
        }

        // If the pointer is not NULL, it means we have found the first file and we can start
        // writting or continue writting the current image
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(card);
    fclose(img);
}
