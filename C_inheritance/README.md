# Inhertence: Simulating Genetic Inheritance of Blood Type

This project demonstrates a simulation of genetic inheritance for blood types using C. The program creates a family tree of individuals, simulating the inheritance of blood type alleles across generations.

## Features

- Simulates inheritance of blood type alleles over multiple generations.
- Dynamically allocates memory for family members.
- Generates random alleles for the founding generation.
- Prints a structured family tree, including children, parents, and grandparents.
- Frees dynamically allocated memory to prevent memory leaks.

## Requirements
- C compiler (e.g. GCC)
- Standard C libraries (`stdio.h`, `stdlib.h`, `stdbool.h`, `time.h`)

## How It Works

1. **Structure Definition**:
   - Each person is represented as a `struct` with pointers to their parents and an array of two alleles.

2. **Random Alleles**:
   - Founding generation individuals are assigned alleles randomly from the set `{'A', 'B', 'O'}`.

3. **Inheritance Logic**:
   - Each child inherits one random allele from each parent.

4. **Memory Management**:
   - Dynamic memory allocation ensures flexibility for different family sizes.
   - Recursive memory deallocation prevents memory leaks.

## Functions

- `create_family(int generations)`
Creates a family tree recursively. If generations > 1, it creates two parents and assigns alleles based on their alleles.

- `print_family(person *p, int generation)`
Prints the family tree with proper indentation and labels for each generation.

- `free_family(person *p)`
Frees memory allocated for a person and their ancestors recursively.

- `random_allele()`
Returns a random blood type allele (`A`, `B`, or `O`).

## Usage

1. Compile the code:
   ```bash
   gcc inheritance.c -o inheritance
2. Run the program:
   ```bash
   ./inheritance
## Exemple Output
   ```Child (Generation 0): blood type AB
    Parent (Generation 1): blood type AO
        Grandparent (Generation 2): blood type AA
        Grandparent (Generation 2): blood type BO
    Parent (Generation 1): blood type BO
        Grandparent (Generation 2): blood type AB
        Grandparent (Generation 2): blood type OO```