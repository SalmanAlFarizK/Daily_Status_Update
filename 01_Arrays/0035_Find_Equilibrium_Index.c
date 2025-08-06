/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void FindEquilibriumIndex(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    FindEquilibriumIndex();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void FindEquilibriumIndex(void)
{
    int Arr[7] = {-7,1,5,2,-4,3,0};
    int leftSum = 0, rightSum = 0;

    for(int i = 0; i < 7; ++i)
    {
        leftSum = 0;
        for(int j = 0; j < i; ++j)
        {
            leftSum += Arr[j];
        }

        rightSum = 0;
        for(int k = i + 1; k < 7; ++k)
        {
            rightSum += Arr[k];
        }

        if(leftSum == rightSum)
        {
            printf("Equilibrium index found at: %d\n", i);
            break;
        }
    }

    return; 
}