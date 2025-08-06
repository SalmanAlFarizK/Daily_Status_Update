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
void CountBitFlips(void);

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main()
{
    CountBitFlips();
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void CountBitFlips(void)
{
    uint8_t ucVal1 = 0x07;
    uint8_t ucVal2 = 0x03;
    uint8_t xor = ucVal1 ^ ucVal2;  // XOR to find differing bits
    uint8_t ucNoOfBitFLips = 0;

    while (xor)
    {
        if (xor & 1)
        {
            ucNoOfBitFLips++;
        }
        xor >>= 1;
    }

    printf("The number of bit flips needed: %d\n", ucNoOfBitFLips);

    return;
}