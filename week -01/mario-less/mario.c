#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (n - i - 2 < j)
            {  
                printf("#"); // 
            } 
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
