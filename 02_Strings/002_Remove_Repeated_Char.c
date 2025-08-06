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
void RemoveRepeatedChar(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    RemoveRepeatedChar();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void RemoveRepeatedChar(void)
{
    char cStr[] = "programming";
    char result[100];
    int j = 0;
    int len = strlen(cStr);
    for(int i = 0; i < len; ++i)
    {
        int found = 0; 
        for(int k = 0; k < j; ++k)
        {
            if(cStr[i] == result[k])
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            result[j++] = cStr[i];
        }
    }
    result[j] = '\0';
    printf("Original String: %s\n", cStr);
    printf("String after removing repeated characters: %s\n", result);
    return;
}