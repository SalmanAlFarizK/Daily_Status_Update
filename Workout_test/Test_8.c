#include<stdio.h>
#include<string.h>
#include <ctype.h>

void CntNoOfZeroAndOnesInBinary(void);
void FindFerqOfDigitInInt(void);
void ToggleCaseOfChar(void);
void  StringSort(void);

int main()
{
    StringSort();
    return 0;
}

void CntNoOfZeroAndOnesInBinary(void)
{
    int iZeroCnt = 0;
    int iOnesCnt = 0;
    int iNum = 10;

    while(iNum > 0)
    {
        if(iNum & 1)
        {
            iOnesCnt += 1;
        }
        else
        {
            iZeroCnt += 1;
        }
        iNum >>= 1;
    }
    printf("Ones cnt : %d, Zeros Cnt: %d\n",iOnesCnt,iZeroCnt);

    return;
}

void FindFerqOfDigitInInt(void)
{
    int iVal = 234234;
    int freq[10] = {0};
    int digit;

    while(iVal != 0)
    {
        digit = iVal % 10;
        freq[digit]++;
        iVal /= 10;
    }
    for(int i = 0; i < 10; ++i)
    {
        if(freq[i] > 0)
        {
            printf("%d occurs %d times\n",i,freq[i]);
        }
    }

    return;
}

void ToggleCaseOfChar(void)
{
    char cStr[] = "Earth Is a Beautiful Place..!";

    printf("String before toggling : %s\n",cStr);

    for(int i = 0; i < strlen(cStr); ++i)
    {
        if(isalpha(cStr[i]))
        {
            cStr[i] ^= (1 << 5);
        } 
    }
    printf("String after toggling : %s\n",cStr);

    return;
}

void StringSort(void)
{
    char cStr[] = "programming";
    
    printf("Before sorting : %s\n",cStr);

    for(int i = 0; i < strlen(cStr); ++i)
    {
        for(int j = i+1; j < strlen(cStr); ++j)
        {
            if(cStr[i] > cStr[j])
            {
                char cTemp = cStr[i];
                cStr[i] = cStr[j];
                cStr[j] = cTemp;
            }
        }
    }

    printf("After sorting : %s\n",cStr);

    return;
}