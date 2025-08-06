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
void HighestFreqOfChar(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    HighestFreqOfChar();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void HighestFreqOfChar(void)
{
    char cStr[] = "engineering";
    int iLen = strlen(cStr);
    char cRes;
    int iResCnt = 0;
    int iTempresCnt = 0;

    for(int i = 0; i < iLen; ++i)
    {
        iTempresCnt = 1;
        for(int j = i+1; j < iLen; ++j)
        {
            if(cStr[i] == cStr[j])
            {
                iTempresCnt += 1;
            }
        }
        if(iTempresCnt > iResCnt)
        {
            iResCnt = iTempresCnt;
            cRes = cStr[i];
        }
    }
    printf("%c Appears %d times\n",cRes,iResCnt);

    return;
}