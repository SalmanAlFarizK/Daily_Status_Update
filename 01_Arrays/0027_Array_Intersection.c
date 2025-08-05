/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void ArrayInterSection(int* pArr1, int* pArr2, int size1, int size2);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    int Arr1[4] = {1, 2, 3, 4};
    int Arr2[4] = {3, 4, 5, 6};
    ArrayInterSection(Arr1, Arr2, 4, 4);
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void ArrayInterSection(int* pArr1, int* pArr2, int size1, int size2)
{
    if(NULL != pArr1
    && NULL != pArr2
    && NULL != pArr1 + size1
    && NULL != pArr2 + size2)
    {
        for(int i = 0; i < size1; ++i)
        {
            for(int j = 0; j < size2; ++j)
            {
                if(pArr1[i] == pArr2[j])
                {
                    printf("%d ", pArr1[i]);
                    break;
                }
            }
        }
    }
    else
    {
        printf("Invalid input arrays\n");
    }
    printf("\n");
    return;
}