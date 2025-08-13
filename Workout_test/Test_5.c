#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONCAT_STR(str1,str2) str1 str2

typedef void (*CallbackFunc)(int);

void CpyArrCntntsFromOneToAnotherUsingPtr(void);
void RemoveDuplicatesUsingPtr(void);
void ConcatStrUsingPtr(void);
void ReverseWorsInStr(void);
void FnPtrDemo(void);
void MultBy10Bitwise(void);
void Substract2NosBitwise(void);
void ConcatStrUsingMacro(void);

int main()
{
    ConcatStrUsingMacro();
    return 0;
}

void CpyArrCntntsFromOneToAnotherUsingPtr(void)
{
    int iArr1[10] = {1,2,3,4,15,6,7,8,9,10};
    int iArr2[10] = {0};

    int* piSrc = iArr1;
    int* piDest = iArr2;

    for(int i = 0; i < 10; ++i)
    {
        *(piDest + i) = *(piSrc + i);
    }

    printf("The array elemenets are : ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr2[i]);
    }
    printf("\n");
    return;
}

void RemoveDuplicatesUsingPtr(void)
{
    int iArr[10] = {1,2,34,2,56,1,56,8,9,10};
    int iRes[10] = {0};

    int* piSrc = iArr;
    int* piDest = iRes;
    int cnt = 0;

    for(int i = 0; i < 10; ++i)
    {
        int found = 0;
        for(int j = 0; j < cnt; ++j)
        {
            if(*(piSrc + i) == *(piDest + j))
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            *(piDest + cnt) = *(piSrc + i);
            cnt += 1; 
        }
    }
    printf("After removing duplicates : ");
    for(int i = 0; i < cnt; ++i)
    {
        printf("%d ",iRes[i]);
    }
    printf("\n");

    return;
}

void ConcatStrUsingPtr(void)
{
    char cStr1[50] = "Hello ";
    char cStr2[] = "World!";
    char *p1 = cStr1;
    char *p2 = cStr2;

    // Move p1 to the end of cStr1
    while (*p1)
        p1++;

    // Copy cStr2 to the end of cStr1
    while (*p2)
        *p1++ = *p2++;

    *p1 = '\0';

    printf("Concatenated string: %s\n", cStr1);
    return;
}

void Reverse(char* pcWordBegin, char* pcWordEnd)
{
    while(pcWordBegin < pcWordEnd)
    {
        char cTemp = *pcWordBegin;
        *pcWordBegin++ = *pcWordEnd;
        *pcWordEnd-- = cTemp;
    }

    return;
}

void ReverseWorsInStr(void)
{
    char cStr[] = "Hello World, How are You !";
    int iLen = strlen(cStr);

    char* pcWorBegin = cStr;
    char* pcTemp = cStr;

    while(*pcTemp)
    {
        pcTemp++;
        if(*pcTemp == ' ')
        {
            Reverse(pcWorBegin, pcTemp - 1);
            pcWorBegin = pcTemp + 1;
        }

        if(*pcTemp == '\0')
        {
            Reverse(pcWorBegin,pcTemp - 1);
        }
    }

    printf("After Reversal : %s\n",cStr);

    return;
}

void PrintSquare(int n)
{
    printf("Square of %d is %d\n", n, n * n);
}

void PrintCube(int n)
{
    printf("Cube of %d is %d\n", n, n * n * n);
}

void PrintDouble(int n)
{
    printf("Double of %d is %d\n", n, 2 * n);
}

// A generic executor function that takes a callback
void ExecuteCallback(int value, CallbackFunc func)
{
    printf("Executing callback...\n");
    func(value);  // Call the passed function
}


void FnPtrDemo(void)
{
    int number = 5;
    // Pass different functions as callbacks
    ExecuteCallback(number, PrintSquare);
    ExecuteCallback(number, PrintCube);
    ExecuteCallback(number, PrintDouble);
}

void MultBy10Bitwise(void)
{
    int iVal = 10;
    int iRes = (iVal << 3) + (iVal << 1);

    printf("%d\n",iRes);
}

void Substract2NosBitwise(void)
{
    int a = 15;
    int b = 7;
    int result = a + (~b + 1); // Subtract b from a using bitwise operations

    printf("Subtraction of %d and %d using bitwise is: %d\n", a, b, result);
    return;
}

void ConcatStrUsingMacro(void)
{

    char * newStr = CONCAT_STR("hello","world");
    printf("%s",newStr);
}