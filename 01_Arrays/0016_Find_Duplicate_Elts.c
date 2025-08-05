/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void FindDuplicateElts(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    FindDuplicateElts();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void FindDuplicateElts(void)
{
    int Arr[6] = {1,2,3,2,4,1};
    bool visited[6] = {false};
    int Count = 0;

    printf("Duplicate elements in the array are: ");
    for(int i = 0; i < 6; ++i)
    {
        if (!visited[i])
        {
            Count = 1;
            for(int j = i + 1; j < 6; ++j)
            {
                if (Arr[i] == Arr[j])
                {
                    visited[j] = true;
                    Count++;
                }
            }
        }
        if (Count > 1)
        {
            printf("%d ", Arr[i]);
        }
    }
}