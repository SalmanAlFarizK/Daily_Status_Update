/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void CheckArraySubset(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    CheckArraySubset();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void CheckArraySubset(void)
{
    int Arr1[5] = {1,2,3,4,5};
    int Arr2[3] = {2,4,5};
    bool bFound = false;

    for(int i = 0; i < 3; ++i)
    {
        bFound = false;

        for(int j = 0; j < 5; ++j)
        {
            if(Arr2[i] == Arr1[j])
            {
                bFound = true;
            }
        }

        if(true != bFound)
        {
            break;
        }
    }
    if(true == bFound)
    {
        printf("Array2 is Subset of Array1\n");
    }
    else
    {
        printf("Array2 is not the Subset of Array1\n");
    }
    return;
}