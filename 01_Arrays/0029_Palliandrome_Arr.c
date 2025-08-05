/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
bool IsArrayPalliandrome(int* pArr, int size);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    int Arr[5] = {1,2,3,2,1};
    if(IsArrayPalliandrome(Arr, 5))
    {
        printf("The array is a palliandrome.\n");
    }
    else
    {
        printf("The array is not a palliandrome.\n");
    }
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
bool IsArrayPalliandrome(int* pArr, int size)
{
    bool isPalliandrome = true;

    if(NULL != pArr
    && NULL != pArr + size)
    {
        for(int i = 0; i < size / 2; ++i)
        {
            if(pArr[i] != pArr[size - 1 - i])
            {
                isPalliandrome = false;
                break;
            }
        }
    }
    else
    {
        printf("Invalid input array\n");
        isPalliandrome = false;
    }

    return isPalliandrome;
}