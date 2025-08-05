/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void SortAscendingOrder(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    SortAscendingOrder();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void SortAscendingOrder(void)
{
    int Arr[4] = {20,5,10,8};
    int temp = 0;

    printf("Original array: ");
    for(int i = 0; i < 4; ++i)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
    for(int i = 0; i < 4; ++i)
    {
        for(int j = i + 1; j < 4; ++j)
        {
            if(Arr[i] > Arr[j])
            {
                temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
    }
    printf("Array after sorting in ascending order: ");
    for(int i = 0; i < 4; ++i)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
    return;
}