#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Pointer Arithemetics. */
#define SIZEOF(type) ((char *)((type *)0 + 1) - (char *)((type *)0))
#define TO_LOWER(c) ((c) | (1 << 5))
#define TO_UPPER(c) ((c) & ~(1 << 5))
#define TOGGLE_EVEN_BITS(ucVal)   ((ucVal) ^ 0x55)

void PrintNonRepeatedChar(void)
{
    char cStr[] = "Hello World";
    int iLen = strlen(cStr);

    for(int i = 0; i < iLen; ++i)
    {
        int iCnt = 0;
        for(int j = 0; j < iLen; ++j)
        {
            if(cStr[i] == cStr[j])
            {
                iCnt += 1;
            }
        }

        if(iCnt == 1)
        {
            printf("%c ", cStr[i]);
        }
    }
    printf("\n");
    return;
}

void ConvertStrToInt(void)
{
    char cStr[] = "1234";
    int iLen = strlen(cStr);
    int iVal = 0;

    for(int i = 0; i < iLen; ++i)
    {
        iVal = (iVal * 10) + (cStr[i] - '0');
    }

    printf("The value corresponding to str is : %d\n",iVal);

    return;
}

void ReverseBitsOfInt(void)
{
    uint16_t uhVal = 0xABCD;
    uint16_t uhRes = 0;

    while(uhVal > 0)
    {
        uhRes <<= 1;
        uhRes |= (uhVal & 0x0001);
        uhVal >>= 1;
    }
    printf("Nuber After Reversing bits: %X\n",uhRes);

    return;
}


int main()
{
    /*
    * Q1: Find the size of the data type without using the sizeof() operator ?
    */
    printf("Size of uint8_t: %u\n", SIZEOF(uint8_t));
    printf("Size of int: %u\n", SIZEOF(int));
    printf("Size of double: %u\n", SIZEOF(double));

    /*
    * Q2: Print non repeated charecters from string ?
    */
    PrintNonRepeatedChar();

    /*
    * Q3: Convert string to int ?
    */
    ConvertStrToInt();

    /*
    * Q4. Reverse bits of an integer ?
    */
    ReverseBitsOfInt();

    /*Q5. Bitwise Macros */
    /*Q5.1 Uppercase to lowercase letters. */
    printf("Upper to lower: %c\n",TO_LOWER('A'));

    /*Q5.2 Lowercase to uppercase letters. */
    printf("Lower to Upper: %c\n",TO_UPPER('a'));

    /*Q5.3 Toggle the even bits of a 8 bit integer. */
    printf("Val after toggling even bits: %X\n",TOGGLE_EVEN_BITS(0xAB));

    
    return 0;
}
