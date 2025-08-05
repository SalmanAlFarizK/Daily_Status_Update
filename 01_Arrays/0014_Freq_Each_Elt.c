/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void FreqOfEachElt(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    FreqOfEachElt();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void FreqOfEachElt(void)
{
    int Arr[6] = {1, 2, 2, 3, 3, 3};
    bool visited[6] = {false};
    int Count = 0;

    for(int i = 0; i < 6; ++i)
    {
        if (visited[i])
            continue;  // Skip already processed element

        Count = 1;

        for(int j = i + 1; j < 6; ++j)
        {
            if (Arr[i] == Arr[j])
            {
                visited[j] = true;
                Count++;
            }
        }

        printf("%d occurs %d times\n", Arr[i], Count);
    }

    return;
}
