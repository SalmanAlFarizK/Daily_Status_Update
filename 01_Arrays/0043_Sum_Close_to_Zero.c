/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void FindEltsSumCloseToZero(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    FindEltsSumCloseToZero();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void FindEltsSumCloseToZero(void)
{
    int Arr[6] = {1,60,-10,70,-80,85};
    int iMinSum = Arr[1] + Arr[2], Sum = 0;
    int iIndex1 = 0, iIndex2 = 1;

    for(int i = 0; i < 6; ++i)
    {
        for(int j = i+1; j < 6; ++j)
        {
            Sum = Arr[i] + Arr[j];

            if(Sum < iMinSum &&
               Sum > 0)
            {
                iMinSum = Sum;
                iIndex1 = i;
                iIndex2 = j;
            }
        }
    }
    printf("The Numbers are : %d and %d\n",Arr[iIndex1],Arr[iIndex2]);
    return;
}