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
void LowestFreqOfChar(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    LowestFreqOfChar();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void LowestFreqOfChar(void)
{
    char cStr[] = "engineering";
    int iFreq[256] = {0};
    int iCnt = 0;

    for(int i = 0; i < strlen(cStr); ++i)
    {
        iCnt = 1;
        for(int j = 0; j < strlen(cStr); ++j)
        {
            if(cStr[i] == cStr[j])
            {
                iCnt += 1;
            }
        }
        iFreq[i] = iCnt - 1;
    }

    for(int i = 0; i < strlen(cStr); ++i)
    {
        if(iFreq[i] == 1)
        {
            printf("%c occurs %d times\n",cStr[i],iFreq[i]);
        }
    }

    return;
}