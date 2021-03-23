// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> //To use strcasecmp - compare strings case-insensitively
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table - 26 for total letters in alphabet
const unsigned int N = 26;
unsigned int word_count;
unsigned int hash_value;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //Hash input "word" to obtain the hash value
    hash_value = hash(word);

    //Access linked list at the hash value index within the hash table
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        //Compare the string of input "word" to the string in the linked list
        if (strcasecmp(word, cursor->word) == 0)
        {
            //If they match, return true
            return true;
        }

        //Take cursor and set it equal to whatever the next pointer is pointing to
        cursor = cursor->next;

    }

    //Word is not in dictionary, return false
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c*/
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Open dictionary file
    FILE *input_file = fopen(dictionary, "r");
    if (input_file == NULL)
    {
        printf("Could not open\n");
        return false;
    }

    //Create word array
    char word[LENGTH + 1];

    //Read strings from the file one at a time until it reaches End of File
    while (fscanf(input_file, "%s", word) != EOF)
    {
        //Create a new node
        node *n = malloc(sizeof(node));

        //Check for NULL value
        if (n == NULL)
        {
            return false;
        }

        //Copy word into node using strcpy
        //Copies the string from word to word value within the node data struct
        strcpy(n->word, word);

        //Hash word to get hash value using hash function created above
        //A hash function returns a non-negative integer value called a hash value
        hash_value = hash(word);

        //Set new pointer
        //Set pointer to the first item in the list corresponding to your hash value
        n->next = table[hash_value];

        //set head of list to new pointer/node value, n
        table[hash_value] = n;

        //Keep track of total number of words
        word_count++;

    }

    //Close input file (dictionary file)
    fclose(input_file);

    //If function is successful, return true
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor; //Set the tmp pointer to the same value as the cursor pointer
            cursor = cursor->next; //Move the cursor pointer to the next value in the linked list
            free(tmp); //Free the tmp value
        }

        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}
