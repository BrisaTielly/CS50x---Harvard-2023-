#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int testKey(string key)
{

    for (int i = 0; i < strlen(key); i++)
    {
     
        if (!((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z')))
        {
      
            return 1;
        }
        
        for (int k = 0; k < strlen(key); k++)
        {
            for (int j = 0; j < strlen(key); j++)
            {
                if (key[k] == key[j] && k != j)
                {
                  
                    return 1;
                }
            }
        }

    }
    return 0;
}


int main(int argc, string argv[])
{
    string text = "VCHPRZGJNTLSKFBDQWAXEUYMOI";

    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else 
    {
        if (strlen(argv[1]) != 26)
        {
            return 1;
        }

        text = argv[1];

        for (int i = 0; i < strlen(text); i++)
        {
            text[i] = toupper(text[i]);
        }

        if (testKey(text))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: "); 
    string ciphertext = plaintext;

    int j = 0;


    for (int i = 0; i < strlen(plaintext); i++)
    {
        j = (int)plaintext[i];


        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = text[j - 97];
            ciphertext[i] = ciphertext[i] + 32;;
        }
        else
        {
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                ciphertext[i] = text[j - 65];
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
    }
    
    printf("ciphertext: %s\n", ciphertext);
    
    return 0;
}

