/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void SortDescendingOrder(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    SortDescendingOrder();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void SortDescendingOrder(void)
{
    int Arr[4] = {7,2,9,4};
    int temp = 0;
    printf("Oringinal array: ");
    for(int i = 0; i < 4; ++i)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
    for(int i = 0; i < 4; ++i)
    {
        for(int j = i + 1; j < 4; ++j)
        {
            if(Arr[i] < Arr[j])
            {
                temp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = temp;
            }
        }
    }
    printf("Array after sorting in descending order: ");
    for(int i = 0; i < 4; ++i)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
    return;
}