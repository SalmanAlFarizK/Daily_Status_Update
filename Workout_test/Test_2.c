#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FindTransposeOfMatrix(void);
void SearchEltInArr(void);
void ReplaceOccurenceOfSubStr(void);
void SeperateOddAndEvenNo(void);
void NextPowOf2UsingBitManipulation(void);
void GetNoOfBitsTobeFlipped(void);
void DemoDynamic2DArray(void);
void PrintPattern(void);
void FindMaxByRecurssion(void);
void LeftRotStrByKPos(void);

int main()
{
    LeftRotStrByKPos();
    return 0;
}

void FindTransposeOfMatrix(void)
{
    int rows = 3, cols = 4;
    int iArr[3][4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int iTaransPoseArr[cols][rows];

    printf("Before transpose \n");
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            printf("%d ",iArr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < cols; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            iTaransPoseArr[i][j] = iArr[j][i];
        }
    }

    printf("After transpose \n");
    for(int i = 0; i < cols; ++i)
    {
        for(int j = 0; j < rows; ++j)
        {
            printf("%d ",iTaransPoseArr[i][j]);
        }
        printf("\n");
    }

    return;
}

void SearchEltInArr(void)
{
    int iArr[10] = {1,23,45,6,5,78,24,69,100,678};
    int iSearchElt = 0,iFound = 0;
    printf("Enter the search element : ");
    scanf("%d",&iSearchElt);
    printf("\n");
    for(int i = 0; i < 10; ++i)
    {
        if(iArr[i] == iSearchElt)
        {
            printf("%d is found at %d\n",iSearchElt,i);
            iFound = 1;
            break;
        }
    }

    if(!iFound)
    {
        printf("%d is not found in the array\n",iSearchElt);
    }

    return;
}

void ReplaceOccurenceOfSubStr(void)
{
    const char* text = "the cat sat on the cat mat";
    const char* oldWord = "cat";
    const char* newWord = "dog";
    char buffer[256];
    int i = 0, j = 0;
    int oldLen = strlen(oldWord);

    while (text[i] != '\0') {
        // Check if oldWord matches at position i
        if (strncmp(&text[i], oldWord, oldLen) == 0) {
            // Copy newWord to buffer
            strcpy(&buffer[j], newWord);
            j += strlen(newWord);
            i += oldLen;
        } else {
            buffer[j++] = text[i++];
        }
    }
    buffer[j] = '\0';

    printf("Original: %s\n", text);
    printf("Modified: %s\n", buffer);

    return;
}

void SeperateOddAndEvenNo(void)
{
    int iArr[10] = {1,23,4,6,78,24,9,31,56,71};
    int iOddNo[20] = {0};
    int iEvenNo[20] = {0};
    int iOddNoCnt = 0, iEvenNoCnt = 0;

    for(int i = 0; i < 10; ++i)
    {
        if(iArr[i]%2 == 0)
        {
            iEvenNo[iEvenNoCnt++] = iArr[i];
        }
        else
        {
            iOddNo[iOddNoCnt++] = iArr[i];
        }
    }

    printf("Even Numbers: ");
    for(int i = 0; i < iEvenNoCnt; ++i)
    {
        printf("%d ",iEvenNo[i]);
    }
    printf("\n");

    printf("Odd Numbers: ");
    for(int i = 0; i < iOddNoCnt; ++i)
    {
        printf("%d ",iOddNo[i]);
    }
    printf("\n");

    return;
}

void NextPowOf2UsingBitManipulation(void)
{
    unsigned int n = 10;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;

    printf("%d\n",n);
    return;
}

void GetNoOfBitsTobeFlipped(void)
{
    int x = 0x07;
    int y = 0x03;
    int iFlips = 0;

    int xor = x ^ y;

    while(xor)
    {
        if(xor & 1)
        {
            iFlips += 1;
        }
        xor >>= 1;
    }

    printf("%d \n",iFlips);

    return;
}

void Allocate2DArray(int ***arr, int rows, int cols) {
    *arr = (int **)malloc(rows * sizeof(int *));
    if (*arr == NULL) return;
    for (int i = 0; i < rows; ++i) {
        (*arr)[i] = (int *)malloc(cols * sizeof(int));
        if ((*arr)[i] == NULL) {
            // Free previously allocated rows on failure
            for (int j = 0; j < i; ++j) free((*arr)[j]);
            free(*arr);
            *arr = NULL;
            return;
        }
    }
}

void Free2DArray(int **arr, int rows) {
    if (arr == NULL) return;
    for (int i = 0; i < rows; ++i) {
        free(arr[i]);
    }
    free(arr);
}

// Example usage
void DemoDynamic2DArray(void) {
    int **matrix = NULL;
    int rows = 3, cols = 4;
    Allocate2DArray(&matrix, rows, cols);
    if (matrix == NULL) {
        printf("Allocation failed\n");
        return;
    }
    // Fill and print
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    Free2DArray(matrix, rows);
}

void PrintPattern(void)
{
    int n = 10;
    
    // Print the first line
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Print the middle lines
    for (int i = 2; i <= n-1; i++) {
        printf("%d", i);
        
        // Print spaces
        for (int j = 1; j <= 2*(n-i)-1; j++) {
            printf(" ");
        }
        
        // Print the last number
        printf("%d\n", n);
    }
    
    // Print the last line
    printf("%d\n", n);
    
    return;
}

int FindMaxRecc(int Arr[], int Len)
{
    if(Len == 1)
    {
        return Arr[0];
    }
    int Max = FindMaxRecc(Arr, Len - 1);

    return (Arr[Len-1] > Max) ? Arr[Len-1] : Max;
}

void FindMaxByRecurssion(void)
{
    int iArr[10] = {25,67,2400,23,467,894,43,345,990,1234};

    int Max = FindMaxRecc(iArr, 10);

    printf("The maximum element of the array is : %d\n",Max);

    return;
}

void LeftRotStrByKPos(void)
{
    char cStr[] = "hello World, How are you:)";
    int iLen = strlen(cStr);
    int iKpos = 3;

    for(int i = 0; i < iKpos; ++i)
    {
        char cLast = cStr[0];
        for(int j = 0; j < iLen; ++j)
        {
            cStr[j] = cStr[j+1];
        }
        cStr[iLen-1] = cLast;
    }
    printf("%s",cStr);

    return;
}