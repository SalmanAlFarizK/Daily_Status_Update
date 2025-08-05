/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void RemoveDuplicateElts(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    RemoveDuplicateElts();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void RemoveDuplicateElts(void)
{
    int Arr[6] = {2, 3, 2, 4, 3, 5};
    int UniqueArr[6];
    int uniQueCount = 0;
    bool isDuplicate;

    for(int i = 0; i < 6; ++i)
    {
        isDuplicate = false;

        for(int j = 0; j < uniQueCount; ++j)
        {
            if(Arr[i] == UniqueArr[j])
            {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate)
        {
            UniqueArr[uniQueCount] = Arr[i];
            uniQueCount++;
        }
    }

    printf("Array after removing duplicates: ");
    for(int i = 0; i < uniQueCount; ++i)
    {
        printf("%d ", UniqueArr[i]);
    }

    printf("\n");
    return;
}
