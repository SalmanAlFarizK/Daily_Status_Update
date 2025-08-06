/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void FindMaxAndMinElt(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    FindMaxAndMinElt();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void FindMaxAndMinElt(void)
{
    int Arr[6] = {1000,11,445,1,330,3000};
    int iMaxELt = Arr[0], iMinElt = Arr[0];

    for(int i = 1; i < 6; ++i)
    {
        if(Arr[i] > iMaxELt)
        {
            iMaxELt = Arr[i];
        }

        if(Arr[i] < iMinElt)
        {
            iMinElt = Arr[i];
        }
    }

    printf("The Maximum Element in the array : %d\nMinimum Element of the array : %d \n",iMaxELt, iMinElt);
}