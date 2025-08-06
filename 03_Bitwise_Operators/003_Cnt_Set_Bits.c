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
void CountNumOfSetBits(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    CountNumOfSetBits();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void CountNumOfSetBits(void)
{
    uint8_t ucVal = 0;
    uint8_t ucSetBitCnt = 0;
    printf("Enter a value\n");
    scanf("%d",&ucVal);

    while(ucVal > 0)
    {
        if(ucVal & 0x01)
        {
            ucSetBitCnt += 1;
        }

        ucVal >>= 1;
    }

    printf("%d is the Number of set bits\n", ucSetBitCnt);
    return;
}