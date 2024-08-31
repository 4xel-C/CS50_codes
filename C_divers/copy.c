// Copying an image using the binary read option of fopen and copying the binary datas into a new file
// allow possibility to copy all sort of files

#include <stdio.h>
#include <stdint.h>


// allow argument in the terminal loading file, argc = nombre d'arguments incluant le nom du fichier, argv les valeurs des arguments
int main(int argc, char *argv[])

typedef unint8_t BYTE // creer le type byte qui permet de recupérer une valeur de 8 bits quelconque (raw data)

{
    FILE *src = fopen(argv[1], "rb"); // ouvre le fichier spécifié par l'argument 1 du prompp en mode "read binary"
    FILE *dst = fopen(argv[2], "wb"); // écrit en binaire dans un nouveau fichier de nom spécifier dans le prompt

    BYTE b; //Reserve 8 bits (1 byte) dans b


    // read the file : &b: where to send the datas to write ? / sizeof(b): how big is the datas I want to write? 1: 1 byte at a time, src: source file
    while (fread(&b, sizeof(b), 1, src) != 0) //fread return how many bytes are successfully read, if return 0, the file is complete.
    {
        fwrite(&b, sizeof(b), 1, dst); // Ecrit les informations à l'adresse &b (stockés dans b), contenant la taille de b comme information, 1 byte à la fois, dans le fichier dst. 
    }  
//  ferme les deux fichiers
    fclose(dst);
    fclose(src);
}


string a = "axel"

char a = "A" + "B"
*char a = "Axel"