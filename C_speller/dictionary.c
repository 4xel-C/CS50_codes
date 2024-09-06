// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
// Sum of the first 3 ASCII characters for the hash function=> Max value possible: ZZZ
const unsigned int N = 'Z' + 'Z' + 'Z' - (3 * 65);

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Create variable to store low cased word
    char low_word[LENGTH + 1];
    // convert word to lower case
    int counter = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        low_word[i] = tolower(word[i]);
        counter++;
    }
    low_word[counter] = '\0';

    unsigned int bucket = hash(low_word);
    node *head = table[bucket]; // Define the head of the linked list to search on the table

    while (head != NULL) // if head == NULL, while loop is skipped and return False, work also if
                         // there is no word on the hashtable bucket
    {

        if (strcmp(head->word, low_word) == 0)
        {
            return true; // mot trouvé
        }
        head = head->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // will sum the ascii value of the 3 fisrt uppercased letters of the word to generate the hash
    int value = 0;
    int len_word = strlen(word);
    if (len_word > 3)
    {
        for (int i = 0; i < 3; i++)
        {
            value += toupper(word[i]) - 65;
        }
    }
    else
    {
        for (int i = 0; i < len_word; i++)
        {
            value += toupper(word[i]) - 65;
        }
    }
    return value;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open the dictionary, read mode
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Dictionnary file could not have been loaded");
        fclose(source);
        return false;
    }

    // read through each characters of the dictionnary
    char word[LENGTH + 1];

    // lecture de 1 caractère à la fois et construction du mot
    while (fscanf(source, "%s", word) != EOF)
    {
        // give the hash of the word
        unsigned int bucket = hash(word);

        node *n = malloc(sizeof(node)); // create new node to contain the word
        if (n == NULL)
        {
            fclose(source);
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        if (table[bucket] == NULL)
        {
            //  Si il n'y a pas d'élément à la table, connecte le noeud à l'index n de la table
            table[bucket] = n; // connecter le noeud à l'adresse n
        }
        else
        {
            // insertion dans la chained list
            n->next = table[bucket];
            table[bucket] = n;
        }
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int counter = 0;
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        while (head != NULL)
        {
            counter++;
            head = head->next;
        }
    }
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *head = NULL;
    node *tmp = NULL;
    for (int i = 0; i < N; i++)
    {

        head = table[i]; // get each entry of the hash table,
        while (head != NULL)
        {
            tmp = head;
            head = head->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    return true;
}
