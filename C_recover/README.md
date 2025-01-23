# Recover JPEG Images from Memory Card

This program reads a memory card file containing contiguous JPEG images, extracts the images using their binary signatures, and saves them into separate files.

## Features
- Scans a memory card image for JPEG file headers.
- Recovers JPEG images and writes them to individual files named incrementally.
- Processes the memory card in 512-byte blocks.

## Prerequisites
- A valid memory card image file to analyze.
- A C compiler (e.g., GCC) to compile the program.

## Usage
1. Clone this repository or copy the code into a `.c` file.
2. Compile the program using:
   ```bash
   gcc -o recover recover.c
    ```
3. Run the program with the memory card image as an argument:
`./recover image`

Replace `image` with the path to your memory card image file.

## Code Explanation
### Key Concepts
- **JPEG Header Identification:** The program checks for JPEG file headers using the signature:
    - 0xff, 0xd8, 0xff, and (buffer[3] & 0xf0) == 0xe0
- **Block Reading:** Reads 512-byte blocks to find and write JPEG data.
**File Handling:** Ensures proper file opening, writing, and closing.

### Steps
1. Verify the command-line argument.
2. Open the memory card file.
3. Read the memory card in 512-byte chunks.
4. Identify JPEG headers to start a new image.
5. Write data blocks to the corresponding image file.
6. Increment file counter and repeat until the card file ends.