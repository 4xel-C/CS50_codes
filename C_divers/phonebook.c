 #include <stdio.h>
 #include <string.h>

 int main(void)
 {
    // open csv file in "append" mod to add datas and not overwritting
    FILE *file = fopen("phonebook.csv", "a"); // fopen return an adress of the file if found. If not found return NULL

// checking if file is correctly found
    if file == NULL
    {
        return 1;
    }

    char *name = get_string("name: "):
    char *number = get_string("number: ");

// permet d'écrire dans le fichier ouvert et d'y rentrer de nouvelles lignes
    fprint(file, "%s, %s\n", name, number);
 }