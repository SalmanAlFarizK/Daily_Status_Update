/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void FindSecLargestElt(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    FindSecLargestElt();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void FindSecLargestElt(void)
{
    int Arr[4] = {10,20,50,40};
    int Largest = Arr[0];
    int SecLargest = Arr[0];

    for(int i = 1; i < 4; ++i)
    {
        if(Arr[i] > Largest)
        {
            SecLargest = Largest;
            Largest = Arr[i];
        }
        else if(Arr[i] > SecLargest && Arr[i] < Largest)
        {
            SecLargest = Arr[i];
        }
    }
    printf("The second largest element in the array is: %d\n", SecLargest);
    return;
}