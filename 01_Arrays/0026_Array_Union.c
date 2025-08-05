/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void ArrayUnion(int* pArr1, int* pArr2, int size1, int size2);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    int Arr1[4] = {1, 2, 3, 4};
    int Arr2[4] = {3, 4, 5, 6};
    ArrayUnion(Arr1, Arr2, 4, 4);
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void ArrayUnion(int* pArr1, int* pArr2, int size1, int size2)
{
    int * pUnionArr = NULL;
    int UnionCount = 0;
    int isDuplicate = 0;

    if(NULL != pArr1
    && NULL != pArr2
    && NULL != pArr1 + size1
    && NULL != pArr2 + size2)
    {
        pUnionArr = (int*)malloc((size1 + size2) * sizeof(int));

        if(NULL != pUnionArr)
        {
            for(int i = 0; i < size1; ++i)
            {
                pUnionArr[UnionCount] = pArr1[i];

                UnionCount += 1;
            }

            for(int i = 0; i < size2; ++i)
            {
                isDuplicate = 0;

                for(int j = 0; j < UnionCount; ++j)
                {
                    if(pArr2[i] == pUnionArr[j])
                    {
                        isDuplicate = 1;
                        break;
                    }
                }

                if(!isDuplicate)
                {
                    pUnionArr[UnionCount] = pArr2[i];
                    UnionCount += 1;
                }
            }

            printf("Union of the two arrays: ");
            for(int i = 0; i < UnionCount; ++i)
            {
                printf("%d ", pUnionArr[i]);
            }
            printf("\n");

            free(pUnionArr);
        }
    }
    else
    {
        printf("Invalid input arrays\n");
    }
    return;
}