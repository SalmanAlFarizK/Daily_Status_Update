#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

// Peniding  22
void FindNthTermOfFibanocci(void);
void ConvertToUpperCase(void);
void ConvertToLowerCase(void);
void CalcHexOfDec(void);
void Concat2StrUsingRecc(void);
void PrintRevOfNumUsingRecc(void);
void DelDuplicateValsOfArr(void);
void SortDynamic2ArrOfStr(void);
void RevLast3DigOf6Dig(void);
void RemoveDuplicatesFromSortedArr(void);
void FindLargestEltInArr(void);
void SwapIntBitwise(void);
void PrintBitBwPos(void);
void CheckPerfectNo(void);
void FunPtrDemo(void);
void DmaArrDemo(void);
void PrintPattern1(void);
void PrintPattern2(void);
void PrintPattern3(void);
void CheckArmstrongNumber(void);
void MatrixMultiplication(void);
void PrintBoundaryELtsOfMatrix(void);
void Swap2Words(void);

int main()
{
    Swap2Words();
    return 0;
}

void FindNthTermOfFibanocci(void)
{
    int n = 10;
    int Prev1 = 1;
    int Prev2 = 0;
    int Curr = 0;

    for(int i = 0; i <= n; ++i)
    {
        Curr = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = Curr;
    }

    printf("The %d th term of fibanocci is %d\n",n,Curr);

    return;
}

void ConvertToUpperCase(void)
{
    char cStr[] = "hello every one :)";

    printf("Before Converting: %s\n",cStr);

    for(int i = 0; i < strlen(cStr); ++i)
    {
        if(cStr[i] >= 'a' && cStr[i] <= 'z')
        {
            cStr[i] &= ~(1 << 5);
        }
    }

    printf("After Converting: %s\n",cStr);

    return;
}

void ConvertToLowerCase(void)
{
    char cStr[] = "HELLO EVERY ONE :)";

    printf("Before Converting: %s\n",cStr);

    for(int i = 0; i < strlen(cStr); ++i)
    {
        if(cStr[i] >= 'A' && cStr[i] <= 'Z')
        {
            cStr[i] |= (1 << 5);
        }
    }

    printf("After Converting: %s\n",cStr);

    return;
}

void CalcHexOfDec(void)
{
    int iDec;
    char hex[32];  // to store hex digits
    int index = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &iDec);

    if (iDec == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    int num = iDec;
    while (num > 0)
    {
        int rem = num % 16;
        if (rem < 10)
        {
            hex[index++] = rem + '0';  // 0-9
        }
        else
        {
            hex[index++] = rem - 10 + 'A'; // A-F
        }

        num /= 16;
    }

    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
    printf("\n");

    return;
}

void concatRecursive(char *dest, const char *src) 
{
    // Move to end of dest first
    if (*dest != '\0') {
        concatRecursive(dest + 1, src);
    } else {
        // Now copy src into dest
        if (*src != '\0') {
            *dest = *src;
            *(dest + 1) = '\0'; // keep null terminator updated
            concatRecursive(dest + 1, src + 1);
        }
    }
}

void Concat2StrUsingRecc(void)
{
    char cStr1[50] = "hello ";
    char cStr2[] = "world";

    concatRecursive(cStr1,cStr2);
    printf("%s",cStr1);

    return;
}

void Printrevrecc(int num)
{
    if(num > 0)
    {
        printf("%d",num % 10);
        Printrevrecc(num/10);
    }
    return;
}

void PrintRevOfNumUsingRecc(void)
{
    int iNum = 1234;

    Printrevrecc(iNum);

    return;
}

void DelDuplicateValsOfArr(void)
{
    int iArr[10] = {1,2,1,3,2,4,5,4,6,7};
    int iUniqArr[10] = {0};
    int iUniqCnt = 0;
    bool bIsDuplicate = false;

    for(int i = 0; i < 10; ++i)
    {
        bIsDuplicate = false;

        for(int j = 0; j < iUniqCnt; ++j)
        {
            if(iArr[i] == iUniqArr[j])
            {
                bIsDuplicate = true;
                break;
            }
        }

        if(!bIsDuplicate)
        {
            iUniqArr[iUniqCnt++] = iArr[i];
        }
    }
    printf("The unique array is : ");
    for(int i = 0; i < iUniqCnt; ++i)
    {
        printf("%d ",iUniqArr[i]);
    }
    printf("\n");

    return;
}


void SortDynamic2ArrOfStr(void) 
{
    int rows = 3;
    int cols = 20;

    char **arr = malloc(rows * sizeof(char*));  // array of char pointers
    if (arr == NULL) return;

    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(cols * sizeof(char)); // each string
        if (arr[i] == NULL) return;
    }

    strcpy(arr[0], "Bob");
    strcpy(arr[1], "Charlie");
    strcpy(arr[2], "Alize");

    printf("Before sort:\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", arr[i]);
    }

    // Sort alphabetically (simple bubble sort)
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                char temp[20];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    printf("\nAfter sort:\n");
    for (int i = 0; i < rows; i++) {
        printf("%s\n", arr[i]);
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return;
}

void RevLast3DigOf6Dig(void)
{
    int iNum = 123456;
    int iFirstThreeDigit = 0;
    int iLastThreeDigit = 0;
    int iRevLastThreeDig = 0;
    int iTempRevLastThreeDig = 0;

    iFirstThreeDigit = iNum / 1000;
    iLastThreeDigit = iNum % 1000;

    iTempRevLastThreeDig = iLastThreeDigit;
    while(iTempRevLastThreeDig > 0)
    {
        int iDig = iTempRevLastThreeDig % 10;
        iRevLastThreeDig = iRevLastThreeDig * 10 + iDig;
        iTempRevLastThreeDig /= 10;
    }

    iRevLastThreeDig += (iFirstThreeDigit * 1000);
    printf("Before reversal : %d, After Reversal : %d\n",iNum,iRevLastThreeDig);

    return;
}

void RemoveDuplicatesFromSortedArr(void)
{
    int iArr[10] = {1,1,1,2,2,3,3,3,9,10};
    int iUniqeCnt = 0;

    for(int i = 0; i < 10; ++i)
    {
        if(iArr[i] != iArr[i+1])
        {
            iArr[iUniqeCnt] = iArr[i];
            iUniqeCnt += 1;
        }
    }

    printf("After removal of duplicates: ");
    for(int i = 0; i < iUniqeCnt; ++i)
    {
        printf("%d ",iArr[i]);
    }

    return;
}

void FindLargestEltInArr(void)
{
    int iArr[10] = {21,56,8,234,78,12,98,65,49,10};
    int iLargestElt = iArr[0];

    for(int i = 0; i < 10; ++i)
    {
        if(iArr[i] > iLargestElt)
        {
            iLargestElt = iArr[i];
        }
    }
    
    printf("The largest element of the array is : %d\n",iLargestElt);

    return;
}

void SwapIntBitwise(void)
{
    int iVal1 = 345;
    int iVal2 = 678;

    printf("Before Swapping a: %d, b: %d\n",iVal1,iVal2);

    iVal1 = iVal1 ^ iVal2;
    iVal2 = iVal1 ^ iVal2;
    iVal1 = iVal1 ^ iVal2;

    printf("After Swapping a: %d, b: %d\n",iVal1,iVal2);

    return;
}

void PrintBitBwPos(void)
{
    uint8_t uiVal = 0xF0;
    int Pos1 = 1, Pos2 = 6;

    while (Pos2 >= Pos1)
    {
        int Res = (uiVal >> Pos2) & 1;  // shift and mask -> gives 0 or 1
        printf("%d ", Res);
        Pos2--;
    }

    return;
}

void CheckPerfectNo(void)
{
    int iNo = 0;
    int iDivisorSum = 0;

    printf("Enter a number: ");
    scanf("%d",&iNo);

    for(int i = 1; i < iNo; ++i)
    {
        if(iNo % i == 0)
        {
            iDivisorSum += i;
        }
    }

    if(iDivisorSum == iNo)
    {
        printf("%d is a perfect number\n",iNo);
    }
    else
    {
        printf("%d is not a perfect number\n",iNo);
    }

    return;
}

void Foo(void)
{
    printf("Foo Function is called\n");

    return;
}

void FunPtrDemo(void)
{
    void(*FunPtr)(void) = Foo;

    FunPtr();

    return;
}

void DmaArrDemo(void)
{
    int size = 0;
    int* piArr = NULL;
    int iSum = 0;

    printf("Enter the size of the array: ");
    scanf("%d",&size);

    piArr = (int*)malloc(sizeof(int) * size);

    if(NULL != piArr)
    {
        printf("\nEnter the elements to the array\n");
        for(int i = 0; i < size; ++i)
        {
            scanf("%d",&piArr[i]);
        }

        printf("The array elements are : ");
        for(int i = 0; i < size; ++i)
        {
            printf("%d ",piArr[i]);
            iSum += piArr[i];
        }
        printf("\n The sum is : %d\n",iSum);

        free(piArr);
    }
    else
    {
        printf("Memory allocation failure\n");
    }

    return;
}

void PrintPattern1(void)
{
    int rows = 13; // number of levels (middle row has n stars)
    int i,j;

    // Upper half (including middle row)
    for (i = 1; i <= rows; i++) {
        if (i % 2 == 1) {
            // Odd row: stars start at column 1
            for (j = 1; j <= i; j++) {
                if (j % 2 == 1)
                    printf("*");
                else
                    printf("       "); // 7 spaces between stars
            }
        } else {
            // Even row: shift by 4 spaces first
            printf("    "); // 4 leading spaces
            for (j = 1; j <= i; j++) {
                if (j % 2 == 1)
                    printf("*");
                else
                    printf("       ");
            }
        }
        printf("\n");
    }

    // Lower half
    for (i = rows - 1; i >= 1; i--) {
        if (i % 2 == 1) {
            for (j = 1; j <= i; j++) {
                if (j % 2 == 1)
                    printf("*");
                else
                    printf("       ");
            }
        } else {
            printf("    ");
            for (j = 1; j <= i; j++) {
                if (j % 2 == 1)
                    printf("*");
                else
                    printf("       ");
            }
        }
        printf("\n");
    }
}

void PrintPattern2(void)
{
    int a = 0, b = 1;
    int Curr = 0;
    int N = 4;

    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            Curr = a+b;
            printf("%d ",b);
            a = b;
            b = Curr;
        }
        printf("\n");
    }

    return;
}

void PrintPattern3(void)
{
    int n = 4;  // maximum number at the middle row
    int i, j;

    // Upper half including middle
    for (i = 1; i <= n; i++) {
        // spaces
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // descending numbers
        for (j = i; j >= 1; j--) {
            printf("%d", j);
        }
        // ascending numbers (skip 1 because already printed)
        for (j = 2; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    // Lower half
    for (i = n - 1; i >= 1; i--) {
        // spaces
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // descending numbers
        for (j = i; j >= 1; j--) {
            printf("%d", j);
        }
        // ascending numbers
        for (j = 2; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    return;
}

void CheckArmstrongNumber(void) {
    int num = 0, iDigitCnt = 0, iTemp = 0;
    long long iSum = 0;

    // Input prompt and validation
    printf("Enter a non-negative number: ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Invalid input. Please enter a non-negative integer.\n");
        return;
    }

    // Count number of digits
    iTemp = num;
    while (iTemp != 0) {
        iTemp /= 10;
        iDigitCnt++;
    }

    // Calculate sum of digits raised to the power of digit count
    iTemp = num;
    while (iTemp != 0) {
        int digit = iTemp % 10;
        iSum += (long long)(pow(digit, iDigitCnt) + 0.5); // Round to nearest integer
        iTemp /= 10;
    }

    // Check if the number is an Armstrong number
    if (iSum == num) {
        printf("%d is an Armstrong number (sum = %lld)\n", num, iSum);
    } else {
        printf("%d is not an Armstrong number (sum = %lld)\n", num, iSum);
    }
}

void MatrixMultiplication(void)
{
    int m1[2][2] = {{1,2},{3,4}};
    int m2[2][2] = {{5,6},{7,8}};
    int Res[2][2] = {0};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++) 
        {
            for (int k = 0; k < 2; k++)
            {
                Res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            printf("%d ",Res[i][j]);
        }
        printf("\n");
    }

    return;
}

void PrintBoundaryELtsOfMatrix(void)
{
    int iArr[4][4] = 
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int row = 4, col = 4;

    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            if((i == 0) || (i == (row -1)) || (j == 0) || (j == col - 1))
            {
                printf("%d ",iArr[i][j]);
            }
        }
    }
    printf("\n");

    return;
}

void Swap2Words(void)
{
    uint16_t uhWord = 0xABCD;

    printf("Before Swapping words: 0x%X\n",uhWord);

    uhWord = (uhWord >> 8) | (uhWord << 8);

    printf("After Swapping words: 0x%X\n",uhWord);

    return;
}