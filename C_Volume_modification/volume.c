// C code to load a .wav file and edit the binary information to rise the volume by a given factor.

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy header from input file to output file
    // Create the variable to store the header (44 bytes)
    uint8_t header[HEADER_SIZE];
    // Read the file and save the datas into the header variable
    fread(header, HEADER_SIZE, 1, input);
    // write the data of the header variable into the new file.
    fwrite(header, HEADER_SIZE, 1, output);

    // Read samples from input file and write updated data to output file
    // create a buffer for a single sample (2 bytes per samples, 16bits.)

    int16_t buffer;
    // fread() return the numbers of bytes read in the file. When the file is over, it returns 0,
    // indicating we finished copying.
    while (fread(&buffer, sizeof(int16_t), 1, input) != 0)
    {
        // update the volume of the sample
        buffer *= factor;

        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
