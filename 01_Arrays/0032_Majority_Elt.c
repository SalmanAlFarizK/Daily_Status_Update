/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void MajorityElt(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    MajorityElt();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void MajorityElt(void)
{
    int Arr[7] = {2,2,1,2,3,2,2};
    int MajorityELt = 0;
    int finalCount = 0;
    int tempCount = 0;

    for(int i = 0; i < 7; ++i)
    {
        tempCount = 0;

        for(int j = i+1; j < 7; ++j)
        {
            if(Arr[i] == Arr[j])
            {
                tempCount += 1;
            }
        }

        if(tempCount > finalCount)
        {
            finalCount = tempCount;
            MajorityELt = Arr[i];
        }
    }
    if(finalCount > (7 / 2))
    {
        printf("Majority Element in the array is: %d\n", MajorityELt);
    }
    else
    {
        printf("No Majority Element in the array.\n");
    }
    return;
}