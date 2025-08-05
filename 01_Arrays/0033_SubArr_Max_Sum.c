/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void KadanesAlgorithm(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    KadanesAlgorithm();
    return 0;
}

/*****************************************************************************
* Function Definitions
*****************************************************************************/
void KadanesAlgorithm(void)
{
    int Arr[8] = {-2,-3,4,-1,-2,1,5,-3};
    int maxSoFar = Arr[0];
    int maxEndingHere = Arr[0];

    for(int i = 1; i < 8; ++i)
    {
        maxEndingHere = (maxEndingHere + Arr[i] > Arr[i]) ? (maxEndingHere + Arr[i]) : Arr[i];
        if(maxEndingHere > maxSoFar)
        {
            maxSoFar = maxEndingHere;
        }
    }
    printf("Maximum contiguous subarray sum is: %d\n", maxSoFar);
    return;
}