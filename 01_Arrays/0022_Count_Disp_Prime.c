/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void CountAndDispPrime(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    CountAndDispPrime();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void CountAndDispPrime(void)
{
    int Arr[6] = {2,4,5,6,7,8};
    int primeCount = 0;

    printf("Prime numbers in the array are: ");
    for(int i = 0; i < 6; ++i)
    {
        int isPrime = 1;
        if(Arr[i] < 2)
        {
            isPrime = 0;
        }
        else
        {
            for(int j = 2; j * j <= Arr[i]; ++j)
            {  
                if(Arr[i] % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
        }
        if(isPrime)
        {
            printf("%d ", Arr[i]);
            primeCount++;
        }
    }
    printf("\nTotal prime numbers count: %d\n", primeCount);
    return;
}