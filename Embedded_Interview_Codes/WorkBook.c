#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define CRC32_PLY       (0xEDB88320U)
#define CIRC_BUF_SIZE   (8)

typedef struct
{
    uint8_t buffer[CIRC_BUF_SIZE];
    int head;  // write index
    int tail;  // read index
} CircBuf_t;

// 03, 04, 06,08, 09, 10, 11, 14, 19, 20, 21, 22, 23, 29, 30, 33, 35, 37, 40 - 44, 
void PositionOfRightMostSetBit(void);
void Cnt1sInBinaryUsingLUT(void);
void ReverseEndianessOf32Bit(void);
void UserDefItoA(void);
void GetTrailingZeros(void);
void MulByBitwise(void);
void LeftRotBitsByK(void);
void RightRotBitsByK(void);
void FindMissingNoByXor(void);
void SetClrToggleSpecificBit(void);
void CalcCrc32(void);
void FloatDecimalString(void);// Pending
void DetectMulOverFlow(void);
void Copy4ByteBlocks(void);
void CntLeadingZeroes(void);
void UserDefStrStr(void);
void ByteAlignedBitFieldExtractor(void);
void VarLenIntEncoder(void);
void FindFirstNonRepeatingChar(void);
void CntSetBits(void);
void MoveAllZeroToEnd(void);
void CircularBufferForByteStorage(void);
void IntSqrtWithBitManPul(void);

int main()
{
    IntSqrtWithBitManPul();
    return 0;
}

void PositionOfRightMostSetBit(void)
{
    int x = 40;
    int iBitPos = 0;

    x &= (-x);
    iBitPos = (int)log2(x) + 1;

    printf("The position of the right most set bit is %d\n",iBitPos);
    
    return;
}

void Cnt1sInBinaryUsingLUT(void)
{
    uint8_t lookup_table[256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, // 0-15
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, // 16-31
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, // 32-47
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, // 48-63
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, // 64-79
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, // 80-95
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, // 96-111
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, // 112-127
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, // 128-143
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, // 144-159
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, // 160-175
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, // 176-191
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, // 192-207
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, // 208-223
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, // 224-239
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8  // 240-255
    };
    uint32_t uiVal = 0x01ABCDEF;
    uint8_t ucNoOfSetBits = 0;

    ucNoOfSetBits = lookup_table[(uiVal >> 0)  & 0xFF] +
                    lookup_table[(uiVal >> 8)  & 0xFF] +
                    lookup_table[(uiVal >> 16) & 0xFF] +
                    lookup_table[(uiVal >> 24) & 0xFF];
    
    printf("The number of set bits in 0x%X is %d\n",uiVal,ucNoOfSetBits);

    return;
}

void ReverseEndianessOf32Bit(void)
{
    uint32_t uiVal = 0x57ABEFCD;
    
    printf("Before converting: 0x%X\n",uiVal);

    uiVal = (((uiVal >> 24) & 0x000000FF) |
             ((uiVal >> 8)  & 0x0000FF00) |
             ((uiVal << 8)  & 0x00FF0000) |
             ((uiVal << 24) & 0xFF000000));

    printf("After converting: 0x%X\n",uiVal);

    return;
}

void UserDefItoA(void)
{
    uint32_t uiVal = 1234;
    char cStr[100] = {0};
    uint8_t ucDigCnt = 0;

    while(uiVal > 0)
    {
        int temp = uiVal % 10;
        cStr[ucDigCnt++] = (temp > 9) ? (temp - 10 + 'a') : (temp + '0');
        uiVal /= 10;
    }
    cStr[ucDigCnt] = '\0';

    for(int i = 0; i < strlen(cStr)/2; ++i)
    {
        char cTemp = cStr[i];
        cStr[i] = cStr[strlen(cStr) - i -1];
        cStr[strlen(cStr) - i -1] = cTemp;
    }

    printf("%s",cStr);

    return;
}

void GetTrailingZeros(void)
{
    int iVal = 0b1000001000000;
    int iCtzVal = 0;

    iVal &= (-iVal);
    iCtzVal = (int)log2(iVal);

    printf("The number of trailing zeroes is %d\n",iCtzVal);
    return;
}

void MulByBitwise(void)
{
    int num1 = 15;
    int num2 = -2;
    int res = 0;
    int isNegative = 0;

    if(num1 < 0)
    {
        num1 = -num1;
        isNegative = !isNegative;
    }

    if(num2 < 0)
    {
        num2 = -num2;
        isNegative = !isNegative;
    }

    while(num2 > 0)
    {
        if(num2 & 1)
        {
            res += num1;
        }

        num2 >>= 1;
        num1 <<= 1;
    }

    if(isNegative)
    {
        res = -res;
    }

    printf("The product is : %d\n",res);
    return;
}

void LeftRotBitsByK(void)
{
    uint32_t uiVal = 0x12345678;
    uint8_t ucKVal = 8;

    ucKVal %= 32;

    uiVal = ((uiVal << ucKVal)) | (uiVal >> (32 - ucKVal));

    printf("After left rotation : 0x%X\n",uiVal);
    
    return;
}

void RightRotBitsByK(void)
{
    uint32_t uiVal = 0x12345678;
    uint8_t ucKVal = 8;

    ucKVal %= 32;

    uiVal = ((uiVal >> ucKVal)) | (uiVal << (32 - ucKVal));

    printf("After rotation : 0x%X\n",uiVal);

    return;
}

void FindMissingNoByXor(void)
{
    int iArr[10] = {1,2,3,4,5,6,8,9,10};
    int iNaturalXor = 0;
    int iArrXor = 0;

    for(int i = 0; i < 10; ++i)
    {
        iArrXor ^= iArr[i];
    }

    for(int i = 1; i <= 10; ++i)
    {
        iNaturalXor ^= i;
    }

    printf("The missing number is : %d\n",iNaturalXor ^ iArrXor);
    return;
}

uint32_t SetBit(uint32_t uival, uint8_t ucPos)
{
    uival |= (1 << ucPos);

    return uival;
}

uint32_t ClearBit(uint32_t uiVal, uint8_t ucClrPos)
{
    uiVal &= ~(1 << ucClrPos);

    return uiVal;
}

uint32_t ToggleBit(uint32_t uiVal, uint8_t ucTogglePos)
{
    uiVal ^= (1 << ucTogglePos);

    return uiVal;
}

void SetClrToggleSpecificBit(void)
{
    uint32_t uiVal = 32;
    printf("After Setting the 4th bit of %d is %d\n",uiVal,SetBit(uiVal, 4));

    uiVal = SetBit(uiVal, 4);

    printf("After Clearing the 4th bit of %d is %d\n",uiVal,ClearBit(uiVal, 4));

    uiVal = ClearBit(uiVal, 4);

    printf("After Toggling the 4th bit of %d is %d\n",uiVal,ToggleBit(uiVal, 4));

    return;
}

void CalcCrc32(void)
{
    uint32_t uiCrc32 = 0xFFFFFFFF;
    uint8_t ucData[] = "123456789";

    for(int i = 0; i < strlen(ucData); ++i)
    {
        uiCrc32 ^= ucData[i];

        for(int bit = 0; bit < 8; ++bit)
        {
            if(uiCrc32 & 1)
            {
                uiCrc32 = ((uiCrc32 >> 1) ^ CRC32_PLY);
            }
            else
            {
                uiCrc32 >>= 1;
            }
        }
    }
    uiCrc32 = ~(uiCrc32);

    printf("The 32 bit crc for given data buffer is : 0x%X\n",uiCrc32);

    return;
}

void FloatDecimalString(void)
{
    float fVal = 3.14;
    char cFloatBuff[20];
    int iWhole = 0;
    float fFrac = 0;

    iWhole = (int)fVal;
    fFrac = fVal - fFrac;

    sprintf(cFloatBuff,"%.2f",fVal);

    printf("%s",cFloatBuff);
    return;
}

void DetectMulOverFlow(void)
{
    int iVal1 = 50000;
    int iVal2 = 50000;
    int iRes = 0;

    if(iVal1 > 0 
    && iVal2 > 0)
    {
        iRes = (iVal1 * iVal2);

        if((iRes/iVal1) != iVal2)
        {
            printf("Overflow occured %d\n",iRes);
        }
        else
        {
            printf("Product of %d and %d is : %d\n",iVal1,iVal2,iRes);
        }
    }
    else
    {
        printf("Product is 0\n");
    }
    return;
}

void Copy4ByteBlocks(void)
{
    uint8_t ucSrc[] = "Hello world, space is always the science of wonder :)";
    uint8_t ucDest[100] = {0};
    uint8_t ucCpyByte = strlen(ucSrc) + 1;

    uint8_t* pucDest = ucDest;
    uint8_t* pucSrc = ucSrc;

    uint8_t ucNWords = ucCpyByte / 4;
    uint8_t ucNBytes = ucCpyByte % 4;

    while(ucNWords--)
    {
        *(uint32_t*)pucDest = *(uint32_t*)pucSrc;
        pucDest += 4;
        pucSrc += 4;
    }

    while(ucNBytes--)
    {
        *pucDest++ = *pucSrc++;
    }

    printf("The copied string is : %s\n",ucDest);

    return;
}

void CntLeadingZeroes(void)
{
    uint32_t uiVal = 0x80000000;
    uint8_t ucLeadingZeroVal = 0;

    if((uiVal >> 16) == 0)
    {
        ucLeadingZeroVal += 16;
        uiVal <<= 16;
    }

    if((uiVal >> 24) == 0)
    {
        ucLeadingZeroVal += 8;
        uiVal <<= 8;
    }

    if((uiVal >> 28) == 0)
    {
        ucLeadingZeroVal += 4;
        uiVal <<= 4;
    }

    if((uiVal >> 30) == 0)
    {
        ucLeadingZeroVal += 2;
        uiVal <<= 2;
    }

    if((uiVal >> 31) == 0)
    {
        ucLeadingZeroVal += 1;
    }

    printf("The number of leading zeros values is %d\n",ucLeadingZeroVal);

    return;
}

void UserDefStrStr(void)
{
    char cMainStr[] = "This is a test string";
    char cSubStr[] = "test";
    int iStartIndx = 0;
    int Found = 0;

    for(int i = 0; i < strlen(cMainStr); ++i)
    {
        if(cSubStr[0] == cMainStr[i])
        {
            Found = 1;
            iStartIndx = i;
            int j;
            for(j = 1; j < strlen(cSubStr); ++j)
            {
                if(cSubStr[j] != cMainStr[i+j])
                {
                    Found = 0;
                    break;
                }
            }
            if(Found)
            {
                break;
            }
        }
    }

    if(Found)
    {
        printf("The substring is found at index %d\n",iStartIndx);
    }
    else
    {
        printf("The substring is not found\n");
    }

    return;
}

void ByteAlignedBitFieldExtractor(void)
{
    uint8_t buf[] = { 0b10110110, 0b10010000 }; // 1011 0110 1001 (12 bits)
    int start = 2;
    int len   = 5;
    uint32_t uiRes = 0;

    for(int i = 0; i < len; ++i)
    {
        int bit_index = start + i;
        int byte_index = bit_index / 8;
        int bit_in_byte = 7 - (bit_index % 8); // MSB-first
        uint8_t bit = (buf[byte_index] >> bit_in_byte) & 1;

        uiRes = (uiRes << 1) | bit;
    }

    printf("The assembled value is %d\n",uiRes);

    return;
}

void VarLenIntEncoder(void)
{
    uint32_t uiVal = 0x2000;
    uint32_t uiDecoded = 0;
    uint8_t ucEncodedBuff[10] = {0};

    /* Encode */
    int i = 0;
    while(uiVal >= 0x80)
    {
        ucEncodedBuff[i++] = (uiVal & 0x7F) | 0x80;
        uiVal >>= 7;
    }
    ucEncodedBuff[i++] = uiVal & 0x7F;

    printf("Encoded val is : ");
    for(int j = 0; j < i; ++j)
    {
        printf("%2X",ucEncodedBuff[j]);
    }
    printf("\n");

    /* Decode */
    int shift = 0;
    i = 0;
    while(1)
    {
        uint8_t ucByte = ucEncodedBuff[i++];
        uiDecoded |= ((uint32_t)(ucByte & 0x7F) << shift);
        if(!(ucByte & 0x80))
        {
            break;
        }
        shift += 7;
    }

    printf("Decoded variant : 0x%X\n",uiDecoded);

    return;
}

void FindFirstNonRepeatingChar(void)
{
    char cStr[] = "embedded";
    int iFreqCnt[256] = {0};
    char cRes;
    int found = 0;

    for(int i = 0; i < strlen(cStr); ++i)
    {
        iFreqCnt[(char)cStr[i]] += 1;
    }

    for(int i = 0; i < strlen(cStr); ++i)
    {
        if(iFreqCnt[(char)cStr[i]] == 1)
        {
            cRes = cStr[i];
            found = 1;
            break;
        }
    }
    
    if(found)
    {
        printf("The fisrt non repeating charecter is %c\n",cRes);
    }
    else
    {
        printf("Not found %c\n",'\0');
    }
    return;
}

void CntSetBits(void)
{
    uint8_t ucVal = 0xF0;
    uint8_t ucSetBitCnt = 0;

    while(ucVal != 0)
    {
        ucVal &= (ucVal - 1);
        ucSetBitCnt += 1;
    }

    printf("The number of set bits is %d\n",ucSetBitCnt);

    return;
}

void MoveAllZeroToEnd(void)
{
    int iArr[10] = {0,1,2,0,0,4,0,9,7,0};
    int iArrLen = 10;
    int iNonZeroIdx = 0;

    printf("Before moving 0's to end: ");
    for(int i = 0; i <iArrLen; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    for(int i = 0; i < iArrLen; ++i)
    {
        if(iArr[i] > 0)
        {
            iArr[iNonZeroIdx++] = iArr[i];
        }
    }

    for(int i = iNonZeroIdx; i < iArrLen; ++i)
    {
        iArr[i] = 0;
    }

    printf("After moving 0's to end: ");
    for(int i = 0; i <iArrLen; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    return;
}

void CircBuf_Init(CircBuf_t *cb)
{
    cb->head = 0;
    cb->tail = 0;
}

int CircBuf_IsEmpty(CircBuf_t *cb)
{
    return (cb->head == cb->tail);
}

int CircBuf_IsFull(CircBuf_t *cb)
{
    return ((cb->head + 1) % CIRC_BUF_SIZE == cb->tail);
}

int CircBuf_Write(CircBuf_t *cb, uint8_t data)
{
    int next = (cb->head + 1) % CIRC_BUF_SIZE;
    if (next == cb->tail) // full
    {
        return 0;
    }
    cb->buffer[cb->head] = data;
    cb->head = next;
    return 1;
}

int CircBuf_Read(CircBuf_t *cb, uint8_t *data)
{
    if (CircBuf_IsEmpty(cb))
    {
        return 0;
    }
    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % CIRC_BUF_SIZE;
    return 1;
}

/* Print all data in circular buffer */
void CircBuf_PrintData(CircBuf_t *cb)
{
    if (CircBuf_IsEmpty(cb))
    {
        printf("Buffer empty\n");
        return;
    }

    printf("Buffer contents: ");
    int idx = cb->tail;
    while (idx != cb->head)
    {
        printf("%c ", cb->buffer[idx]);
        idx = (idx + 1) % CIRC_BUF_SIZE;
    }
    printf("\n");
}


void CircularBufferForByteStorage(void)
{
    CircBuf_t cb;
    CircBuf_Init(&cb);

    CircBuf_Write(&cb, 0x41); // 'A'
    CircBuf_Write(&cb, 0x42); // 'B'
    CircBuf_Write(&cb, 0x43); // 'C'

    CircBuf_PrintData(&cb);   // should print: 41 42 43

    uint8_t val;
    CircBuf_Read(&cb, &val);
    printf("Read: %c\n", val);

    CircBuf_PrintData(&cb);   // should print: 42 43

    return;
}

void IntSqrtWithBitManPul(void)
{
    uint32_t n = 27;
    unsigned int res = 0; 
    unsigned int bit = 1u << 30;  

    while (bit > n)
        bit >>= 2;

    while (bit != 0) {
        if (n >= res + bit) {
            n -= res + bit;
            res = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }

    printf("result is %d\n",res);

    return;
}