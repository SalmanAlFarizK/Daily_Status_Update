/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void FindSecSmallElt(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    FindSecSmallElt();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void FindSecSmallElt(void)
{
    int Arr[6] = {12,13,1,10,34,1};
    int firstSmall = Arr[0], secondSmall = Arr[0];

    for(int i = 1; i < 6; ++i)
    {
        if(Arr[i] < firstSmall)
        {
            secondSmall = firstSmall;
            firstSmall = Arr[i];
        }
        else if(Arr[i] > firstSmall &&
                Arr[i] < secondSmall)
        {
            secondSmall = Arr[i];
        }        
    }
    printf("The second small element in the array is : %d",secondSmall);

    return;
}