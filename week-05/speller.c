


#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"


typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;



const unsigned int N = 30000;


node *table[N];


int dictionary_size = 0;


bool check(const char *word)
{
    
    

    
    int index = hash(word);

    
    node *n = table[index];

    
    while (n != NULL)
    {
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }

        
        n = n->next;
    }
    return false;
}


unsigned int hash(const char *word)
{
    
    

    
    int sum = 0;
    
    int len = strlen(word);

    
    for (int i = 0; i < len; i++)
    {
        int value = tolower(word[i]);
        sum += value;
    }

    
    
    return sum % N;
}


bool load(const char *dictionary)
{
    
    
    FILE *dictionary_file = fopen(dictionary, "r");

    
    if (dictionary == NULL)
    {
        printf("Not able to read %s\n", dictionary);
        return false;
    }

    

    
    char new_word[LENGTH + 1];

    while (fscanf(dictionary_file, "%s", new_word) == 1)
    {
        
        node *n = malloc(sizeof(node));

        
        if (n == NULL)
        {
            printf("Something with allocating memory failed");
            return false;
        }

        
        strcpy(n->word, new_word);

        
        int index = hash(new_word);

        
        
        n->next = table[index];
        table[index] = n;

        
        dictionary_size += 1;
    }

    
    fclose(dictionary_file);

    return true;
}


unsigned int size(void)
{
    
    
    return dictionary_size;
}


bool unload(void)
{
    
    

    for (int i = 0; i < N; i++)
    {
        
        node *n = table[i];

        while (table[i] != NULL)
        {
            
            node *temp = table[i]->next;

            
            free(table[i]);

            
            table[i] = temp;
        }
    }
    return true;
}
