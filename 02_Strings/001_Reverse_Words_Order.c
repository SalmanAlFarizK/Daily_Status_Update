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
void ReverseWordsOrder(void);
void ReverseWords(char* s);
void Reverse(char* begin,char* end);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    ReverseWordsOrder();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void ReverseWordsOrder(void)
{
    char cStr[] = "hello world from C";
    ReverseWords(cStr);
    printf("The string with reversed word order: %s",cStr);
}

void Reverse(char* begin,char* end)
{
    char temp;
    while (begin < end) 
    {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }

    return;
}

void ReverseWords(char* s)
{
    char* word_begin = s;

    char* temp = s;
    while (*temp) 
    {
        temp++;
        if (*temp =='\0') 
        {
            Reverse(word_begin,temp - 1);
        }
        else if (*temp == ' ') 
        {
            Reverse(word_begin,temp - 1);
            word_begin = temp + 1;
        }
    }

    Reverse(s, temp - 1);

    return;
}