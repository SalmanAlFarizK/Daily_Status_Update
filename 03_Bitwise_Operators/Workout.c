#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SET_NTH_BIT(num,n)      (num | (1 << n))
#define CLEAR_NTH_BIT(num,n)    (num & ~(1 << n))
#define TOGGLE_NTH_BIT(num,n)   (num ^ (1 << n))

void CheckOddOrEven(void)
{
    int val = 9;
    if(val & 1)
    {
        printf("Odd\n");
    }
    else
    {
        printf("Even\n");
    }

    return;
}

void CehckPowOf2(void)
{
    int val = 8;
    if((val > 0) &&
       (val & (val - 1)) == 0)
    {
        printf("Power of 2\n");
    }
    else
    {
        printf("Not the power of 2\n");
    }

    return;
}

void SetBits(uint32_t x,int p, int n, uint32_t y)
{
    uint32_t Mask = ~(~0U << n);
    x = (x & ~(Mask << (p - n + 1))) | ((y & Mask) << (p - n + 1));
    printf("0x%X",x);
}

void ReverseBitsInInt(void)
{
    uint32_t iVal = 0x6F;  // Example value
    uint32_t iRes = 0;

    for (int i = 0; i < 32; i++) // Process all bits
    {
        iRes <<= 1;         // Shift result left to make space
        iRes |= (iVal & 1); // Copy the LSB of iVal to result
        iVal >>= 1;         // Shift iVal right to get next bit
    }

    printf("Reversed: 0x%08X\n", iRes);
}

void MultiplyBy9(int iNum)
{
    printf("%d\n",(iNum << 3) + iNum);
}

void ConvertLittileEndianToBigEndian(void)
{
    uint32_t uiVal = 0x12ABCDEF;
    uint32_t uiConvertedVal = 0;

    uiConvertedVal |= (((uiVal >> 24) & 0x000000FF)|
                       ((uiVal >> 8)  & 0x0000FF00)|
                       ((uiVal << 8) & 0x00FF0000) |
                       ((uiVal << 24)  & 0xFF000000));

    printf("0x%X",uiConvertedVal);
    return;
}

void GetNthBit(void)
{
    int N = 2;
    int iVal = 10;

    if(iVal & (1 << (N - 1)))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    return;
}

void SetNthBit(void)
{
    int N = 3;
    int iVal = 10;

    iVal |= (1 << (N-1));
    printf("%d",iVal);

    return;
}

void ClearNthBit(void)
{
    int iVal = 10;
    int N = 2;

    iVal &= ~(1 << (N-1));
    printf("%d",iVal);

    return;
}

void ToggleNthBit(void)
{
    int ival = 10;
    int N = 2;

    ival ^= (1 << (N-1));
    printf("%d",ival);

    return;
}

void GetHighestSetBitOfaNum(void)
{
    uint32_t uiVal = 18;
    uint8_t ucHighestBitPos = 0;

    while(uiVal > 0)
    {
        ucHighestBitPos += 1;
        uiVal >>= 1;
    }

    printf("%d",ucHighestBitPos);

    return;
}

void GetLowestSetBit(void)
{
    uint32_t uiVal = 18;
    uint8_t ucLowestSetBitPos = 0;

    while(uiVal > 0)
    {
        ucLowestSetBitPos += 1;
        if(uiVal & 1)
        {
            break;
        }
        uiVal >>= 1;
    }

    printf("%d",ucLowestSetBitPos);

    return;
}

void FlipBits(void)
{
    uint8_t ucVal = 5;
    uint8_t ucFlippedVal = ~ucVal;

    printf("Flipped value is : %d\n",ucFlippedVal);
    return;
}

void CountZeroesAndOnes(void)
{
    uint8_t ucVal = 10;
    uint8_t ucZeroCnt = 0, ucOneCnt = 0;

    ucVal = ~(ucVal);
    while(ucVal > 0)
    {
        if(ucVal & 1)
        {
            ucZeroCnt += 1;
        }
        else
        {
            ucOneCnt += 1;
        }
        ucVal >>= 1;
    }

    printf("Zero count : %d Ones count : %d\n",ucZeroCnt,ucOneCnt);

    return;
}

void RotateBitsLeftByN(void)
{
    uint8_t ucval = 16;
    uint8_t ucRotVal = 2;
    uint8_t ucTotalBits = 8 * sizeof(ucval);

    uint8_t ucResult = (ucval << ucRotVal) | (ucval >> (ucTotalBits - ucRotVal));

    printf("%d",ucResult);

    return;
}

void ConvertDecimalToBinary(void)
{
    uint8_t ucVal = 13;
    
    for(int i = sizeof(ucVal)*8 - 1; i >= 0; --i)
    {
        printf("%d",(ucVal >> i)&1);
    }
    printf("\n");
    return;
}

void Swap2Numbers(void)
{
    int Num1 = 78, Num2 = 100;
    printf("Number before swapping : %d %d\n",Num1,Num2);

    Num1 = Num1 ^ Num2;
    Num2 = Num1 ^ Num2;
    Num1 = Num1 ^ Num2;
    printf("Number After swapping : %d %d\n",Num1,Num2);

    return;
}

int main()
{
    Swap2Numbers();
    return 0;
}