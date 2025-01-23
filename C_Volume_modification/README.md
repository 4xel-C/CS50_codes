# Volume Adjuster for .wav Files

This program loads a `.wav` file and increases the volume by a given factor. The factor is provided as a command-line argument. The program reads the binary data from the input `.wav` file, modifies the audio samples by multiplying them by the factor, and writes the resulting audio data to an output file.

## Requirements

- C Compiler (e.g., GCC)
- A `.wav` file with 16-bit signed samples

## Usage

To compile and run the program, use the following commands:

Compile the code:
```bash
gcc -o volume volume.c
```
Run the program with the following arguments:
```
./volume input.wav output.wav factor
```
Where:
- input.wav: The input .wav file.
- output.wav: The output .wav file to store the modified audio.
- factor: A floating-point number representing the volume scaling factor. For example, use 2.0 to double the volume.

## Description
**- Header Size:** The program assumes the .wav file has a standard 44-byte header.
**- Factor:** The factor multiplies the audio samples to adjust the volume. Higher factors increase the volume, while values less than 1.0 decrease it.
**- Input/Output:** The program reads the input file byte by byte, modifies the audio data, and writes it to the output file.