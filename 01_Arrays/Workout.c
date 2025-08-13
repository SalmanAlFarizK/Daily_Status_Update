#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define GET_SET_BITS(num)       \
 ({                              \
    unsigned int uiNum = num;   \
    int uiCnt = 0;              \
    while(uiNum > 0)            \
    {                           \
        if(uiNum & 1)           \
        {                       \
            uiCnt += 1;         \
        }                       \
        uiNum >>= 1;            \
    }                           \
    uiCnt;                      \
})

typedef struct _FnPointer_
{
    void(*pfnFnPtr)(void);
} FnPointer;

void ArrOfPtrAndPtrOfArr(void)
{
    int a = 10, b = 20, c = 30, d= 40, e = 50;
    int* piArr[5] = {&a,&b,&c,&d,&e};
    int iArr[5] = {1,32,45,4,67};
    int (*pArr)[5] = &iArr;

    printf("Demonstration of array of pointers : ");
    for(int i = 0; i < 5; ++i)
    {
        printf("%d ",*piArr[i]);
    }
    printf("\n");

    printf("Demonstration of pointer to an array : ");
    for(int i = 0; i < 5; ++i)
    {
        printf("%d ",(*pArr)[i]);
    }
    printf("\n");

    return;
}

int FindMaxRec(int arr[], int n)
{
    // Base case: if only one element, return it
    if (n == 1)
        return arr[0];

    // Get the maximum from the rest of the array
    int maxRest = FindMaxRec(arr, n - 1);

    // Return the bigger one between last element and max of rest
    return (arr[n - 1] > maxRest) ? arr[n - 1] : maxRest;
}

void FindMaxUsingRecurssion(void)
{
    int iArr[5] = {67,34,78,90,12};
    int maxVal = FindMaxRec(iArr, 5);

    printf("Maximum value = %d\n", maxVal);

    return;
}

void DemoStructWithFnPtr(void)
{
    FnPointer pFn;
    pFn.pfnFnPtr = ArrOfPtrAndPtrOfArr;

    printf("This is the demonstartion for struct with function pointers : \n");

    if(NULL !=  pFn.pfnFnPtr)
    {
        pFn.pfnFnPtr();
    }
    return;
}

void Reverse(char* pcWordBegin, char* pcWordEnd)
{
    char cTemp;
    while(pcWordBegin < pcWordEnd)
    {
        cTemp = *pcWordBegin;
        *pcWordBegin++ = *pcWordEnd;
        *pcWordEnd-- = cTemp;
    }

    return;
}

void ReverseEachWordInSentence(void)
{
    char cStr[] = "This is Hard";
    int iLen = strlen(cStr);
    char *pcWordBegin = cStr;
    char *pcTemp = cStr;

    while(*pcTemp)
    {
        pcTemp++;
        if(*pcTemp == ' ')
        {
            Reverse(pcWordBegin,pcTemp - 1);
            pcWordBegin = pcTemp + 1;
        }

        if(*pcTemp == '\0')
        {
            Reverse(pcWordBegin,pcTemp - 1);
        }
    }

    printf("%s",cStr);

    return;
}

void MyItoA(void)
{
    int iNum = 12345;
    char cStr[20] = {0};
    int i = 0;
    int isNegative = 0;

    if(iNum == 0)
    {
        cStr[i++] = '0';
        cStr[i] = '\0';
    }
    else
    {
        if(iNum < 0)
        {
            isNegative = 1;
            iNum = -iNum;
        }

        while(iNum != 0)
        {
            int iRem = iNum % 10;
            cStr[i++] = iRem + '0';
            iNum /= 10;
        }

        if(isNegative)
        {
            cStr[i++] = '-';
        }

        cStr[i] = '\0';

        Reverse(cStr, cStr + i - 1);
    }

    printf("%s",cStr);

    return;
}

void StrRevRecc(char* pcStr, int iStrat, int iEnd)
{
    if(iStrat >= iEnd)
    {
        return;
    }
    char cTemp = pcStr[iStrat];
    pcStr[iStrat] = pcStr[iEnd];
    pcStr[iEnd] = cTemp;

    StrRevRecc(pcStr, iStrat + 1, iEnd - 1);
}

void ReverseStrRecursiveley(void)
{
    char cStr[] = "Hello World";
    int iLen = strlen(cStr);
    StrRevRecc(cStr, 0, iLen - 1);

    printf("The reversed string is : %s\n",cStr);

    return;
}

void GetDuplicateElts(void)
{
    int iArr[6] = {1,2,4,2,4,1};
    int iCnt = 0;
    bool bVisited[6] = {false};

    for(int i = 0; i < 6; ++i)
    {
        if(!bVisited[i])
        {
            iCnt = 1;
            for(int j = i+1; j < 6; ++j)
            {
                if(iArr[i] == iArr[j])
                {
                    iCnt += 1;
                    bVisited[j] = true;
                }
            }
            if(iCnt > 1)
            {
                printf("%d ",iArr[i]);
            }
        }
    }
    printf("\n");

    return;
}

void GetNumOfSetBits(void)
{
    int iVal = 0x07;
    int iNoOfSetbits = GET_SET_BITS(iVal);

    printf(" The number of set bits are : %d",iNoOfSetbits);

    return;
}

void ReversePortionOfArray(void)
{
    int iArr[10] = {1,2,3,4,5,6,7,8,9,10};
    int iLen = 10;
    int i = 2, j =8;
    i--;
    j--;
    while(i < j)
    {
        int temp = iArr[i];
        iArr[i] = iArr[j];
        iArr[j] = temp;
        i += 1;
        j -= 1; 
    }

    printf("The array after a portion of reverse is : ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr[i]);
    }

    return;
}

void GetArrDuplicates(void)
{
    int arr[8] = {1, 2, 3, 4, 2, 5, 3, 6};
    int iLen = 8;
    int iIsProcessed = 0;

    for(int i = 0; i < iLen; ++i)
    {
        iIsProcessed = 0;

        for(int j = i+1; j < iLen; ++j)
        {
            
        }
    }
}

void IntroBuiltInPopCnt(void)
{
    int x = 16;
    int y = __builtin_popcount(x);
    printf("%d",y);

    return;
}

int main()
{
    IntroBuiltInPopCnt();
    return 0;
}