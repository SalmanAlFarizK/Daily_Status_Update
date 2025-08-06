/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void FindMaxDiffernce(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    FindMaxDiffernce();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void FindMaxDiffernce()
{
    int Arr[7] = {2,3,10,6,4,8,1};
    int iMinElt = Arr[0], iMaxDiff = Arr[1] - Arr[0];
    int iCurrDiff = 0;

    for(int i = 0; i < 7; ++i)
    {
        iCurrDiff = Arr[i] - iMinElt;
        if(iCurrDiff > iMaxDiff)
        {
            iMaxDiff = iCurrDiff;
        }

        if(Arr[i] < iMinElt)
        {
            iMinElt = Arr[i];
        }
    }

    printf("The maximum Difference is : %d\n",iMaxDiff);

    return;
}