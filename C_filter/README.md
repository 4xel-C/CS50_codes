# Filtering BMP images in C

This program processes 24-bit uncompressed BMP images by applying filters such as grayscale, sepia, horizontal reflection, and blur. It operates directly on the image's binary data using a command-line interface.

## Features

- Supported filters:
  - **Grayscale** (`-g`): Converts the image to grayscale.
  - **Sepia** (`-s`): Applies a sepia tone to the image.
  - **Reflection** (`-r`): Reflects the image horizontally.
  - **Blur** (`-b`): Applies a blur effect.
- Validates the input file format to ensure compatibility.
- Reads and writes **24-bit uncompressed BMP 4.0** files.

## Requirements

### Tools and Libraries

- **C Compiler** (e.g., `gcc`)
- **CS50 Library**: For working with BMP headers (`helpers.h`).
- BMP input files in **24-bit uncompressed BMP 4.0** format.

## Installation

1. Clone the repository or download the source files.
2. Compile the program:
   ```bash
   gcc -o filter filter.c helpers.c -lcs50
   ```

## Usage
Run the program with:
```./filter [flag] infile outfile```

Where:

- [flag] is one of the supported filters:
 - `-g:` Grayscale
 - `-s:` Sepia
 - `-r:` Reflection
 - `-b:` Blur
- `infile` is the path to the input BMP file.
- `outfile` is the path to the output BMP file.

## Filter Implementations:
 ### 1. Grayscale:
 The grayscale filter calculates the average intensity of the red, green, and blue components for each pixel and applies this value to all three components:
 ```average = ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0) + 0.5;```
 ### 2. Sepia:
 The sepia filter uses specific coefficients to calculate new red, green, and blue values:
 ```
sepiaBlue = (0.131 * rgbtBlue + 0.534 * rgbtGreen + 0.272 * rgbtRed) + 0.5;
sepiaGreen = (0.168 * rgbtBlue + 0.686 * rgbtGreen + 0.349 * rgbtRed) + 0.5;
sepiaRed = (0.189 * rgbtBlue + 0.769 * rgbtGreen + 0.393 * rgbtRed) + 0.5;
```
 ### 3. Reflection:
 The reflection filter horizontally swaps pixels in each row:
 ### 4. Blur:
 The blur filter averages the RGB values of a pixel and its surrounding neighbors.
The final values are rounded to the nearest integer.