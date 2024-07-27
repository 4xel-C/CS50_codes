// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // create memory for storing the low cased word
    char *low_word = malloc(sizeof(word));
     // convert word to lower case
    int counter = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        low_word[i] = tolower(word[i]);
        counter++;
    }
    low_word[counter] = '\0';

    unsigned int bucket = hash(word);
    node *head = table[bucket]; // Define the head of the linked list to search on the table

    while (head != NULL)   // if head == NULL, while loop is skipped and return False, work also if there is no word on the hashtable bucket
    {

        if (strcmp(head->word, low_word) == 0)
        {
            free(low_word);
            return true;  // mot trouvé
        }
        head = head->next;
    }
    free(low_word);
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open the dictionary, read mode
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Dictionnary file could not have been loaded");
        return false;
    }

    // read through each characters of the dictionnary
    char word[LENGTH + 1];
    char c;
    int i = 0; // index du mot

    // lecture de 1 caractère à la fois et construction du mot
    while (fread(&c, sizeof(char), 1, source))
    {
        // if end of the word, append to the hashtable
        if (c == '\n')
        {
            word[i] = '\0'; // fin du mot
            unsigned int bucket = hash(word); // genere le bucket de la hash table

            node *n = malloc(sizeof(node)); // cree le nouveau noeud qui contiendra le mot
            if (n == NULL)
            {
                // fclose(source);
                free(n);
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
            i = 0; // reset index du mot

        }
        else
        {
            word[i] = c;
            i++;
        }
    }
    // fclose(source);
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
    for (int i = 0; i < N; i++)
    {
        node *head = table[i]; // get each entry of the hash table,
        while (head != NULL)
        {
            node *temp = head;
            head = head->next;
            free(temp);
        }
    }
    return true;
}
