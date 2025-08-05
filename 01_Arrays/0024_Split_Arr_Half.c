/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void SplitArrIntoHalf(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    SplitArrIntoHalf();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void SplitArrIntoHalf(void)
{
    int Arr[6] = {1, 2, 3, 4, 5, 6};
    
    if((sizeof(Arr) / sizeof(Arr[0])) % 2 != 0)
    {
        printf("Array size is not even, cannot split into two equal halves.\n");
    }
    else
    {
        int size = sizeof(Arr) / sizeof(Arr[0]);
        int halfSize = size / 2;
        int firstHalf[halfSize];
        int secondHalf[halfSize];

        for(int i = 0; i < halfSize; ++i)
        {
            firstHalf[i] = Arr[i];
            secondHalf[i] = Arr[i + halfSize];
        }

        printf("First half of the array: ");
        for(int i = 0; i < halfSize; ++i)
        {
            printf("%d ", firstHalf[i]);
        }
        printf("\n");
        printf("Second half of the array: ");
        for(int i = 0; i < halfSize; ++i)
        {
            printf("%d ", secondHalf[i]);
        }
        printf("\n");
    }

    return;
}