/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void SortArrayOfStrings(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    SortArrayOfStrings();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void SortArrayOfStrings(void)
{
    char Str[3][10] = {"John", "Alice", "Bob"};
    char temp[10];
    int n = 3;

    printf("Array of strings before sorting:\n");
    for(int i = 0; i < n; ++i)
    {
        printf("%s ", Str[i]);
    }
    printf("\n");
    for(int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - i - 1; ++j)
        {
            if(strcmp(Str[j], Str[j + 1]) > 0)
            {
                strcpy(temp, Str[j]);
                strcpy(Str[j], Str[j + 1]);
                strcpy(Str[j + 1], temp);
            }
        }
    }
    printf("Array of strings after sorting:\n");
    for(int i = 0; i < n; ++i)
    {
        printf("%s ", Str[i]);
    }
    printf("\n");

    return;
}