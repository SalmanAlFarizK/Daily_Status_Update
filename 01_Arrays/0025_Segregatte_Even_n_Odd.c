/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void SeggregateEvenNOdd(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    SeggregateEvenNOdd();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void SeggregateEvenNOdd(void)
{
    int Arr[6] = {1,2,3,4,5,6};
    int EvenArr[6] = {0};
    int OddArr[6] = {0};
    int EvenCount = 0, OddCount = 0;

    for(int i = 0; i < 6; ++i)
    {
        if(Arr[i] % 2 == 0)
        {
            EvenArr[EvenCount] = Arr[i];

            EvenCount += 1;
        }
        else
        {
            OddArr[OddCount] = Arr[i];

            OddCount += 1;
        }
    }
    printf("Even elements: ");
    for(int i = 0; i < EvenCount; ++i)
    {
        printf("%d ", EvenArr[i]);
    }
    printf("\nOdd elements: ");
    for(int i = 0; i < OddCount; ++i)
    {
        printf("%d ", OddArr[i]);
    }
    printf("\n");
    return;
}