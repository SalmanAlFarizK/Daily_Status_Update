/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void MergeArrays(int* pArr1, int* pArr2, int size1, int size2);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    int Arr1[] = {1, 3, 5, 7};
    int Arr2[] = {2, 4, 6, 8};
    int size1 = sizeof(Arr1) / sizeof(Arr1[0]);
    int size2 = sizeof(Arr2) / sizeof(Arr2[0]);
    
    MergeArrays(Arr1, Arr2, size1, size2);
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void MergeArrays(int* pArr1, int* pArr2, int size1, int size2)
{
    int * pMergedArr = NULL;

    if(NULL != pArr1
    && NULL != pArr2
    && NULL != pArr1 + size1
    && NULL != pArr2 + size2)
    {
        pMergedArr = (int*)malloc((size1 + size2) * sizeof(int));

        if(NULL == pMergedArr)
        {
            printf("Memory allocation failed\n");
        }
        else
        {
            memcpy(pMergedArr, pArr1, size1 * sizeof(int));
            memcpy(pMergedArr + size1, pArr2, size2 * sizeof(int));

            printf("Merged Array: ");
            for(int i = 0; i < size1 + size2; ++i)
            {
                printf("%d ", pMergedArr[i]);
            }
        }
    }
    else
    {
        printf("Invalid input arrays\n");
    }
    if(pMergedArr)
    {
        free(pMergedArr);
    }
    printf("\n");
    return;
}