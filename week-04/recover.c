#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        printf("Usage: ./recover your-file.raw\n");
        return 1;
    }

    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    
    
    
    
    

    
    
    unsigned char *buffer = malloc(BLOCK_SIZE);
    
    FILE *new_image = NULL;
    
    int counter = 0;
    
    int start_image = 0;
    int stop_image = 0;

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        
        
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            
            if ((start_image == 1 && stop_image == 1) || (start_image == 1 && counter == 1))
            {
                
                fclose(new_image);
                stop_image = 0;
            }

            if (start_image == 1)
            {
                
                stop_image = 1;
            }

            if (start_image == 0)
            {
                
                start_image = 1;
            }

            
            
            char filename[10];
            sprintf(filename, "%03i.jpg", counter);
            
            new_image = fopen(filename, "w");
            
            counter ++;
        }

        
        if ((stop_image == 1 && start_image == 1) || (start_image == 1 && counter == 1))
        {
            fwrite(buffer, BLOCK_SIZE, 1, new_image);
        }
    }

    
    fclose(file);
    fclose(new_image);
    free(buffer);
    return 0;

}