#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Student_
{
    int id;
    char Name[20];
} Student;

void CalcXPowNByRecc(void);
void MoveZerosToEnd(void);
void FindLongestWordInStr(void);
void ReverseWordOrders(void);
void GetMaxConsecOnes(void);
void AvgOfIntUsingPtr(void);
void ArrOfPtrToFunc(void);
void ArrOfPtrToStruct(void);
void StructToFuncByRefDemo(void);
void OutPutSourceCode(void);
void DMAforStructDemo(void);
void CallBackFuncDemo(void);
void CalculateLCMandGCD(void);
void Convert1DArrTo2DArr(void);
void CalcPivotIdxOfArr(void);
void GetLongestCntIncrsngSubSeqnce(void);
void InsertionSort(void);
void QuickSortDemo(void);
void PrintPattern1(void);
void PrintPattern2(void);

int main()
{
    PrintPattern2();
    return 0;
}

int PowByRecc(int x, int n)
{
    if(n == 0)
    {
        return 1;
    }

    return x*PowByRecc(x,n-1);
}

void CalcXPowNByRecc(void)
{
    int x = 10;
    int n = 3;
    
    int res = PowByRecc(x,n);
    printf("%d Power %d is : %d\n",x,n,res);
    return;
}

void MoveZerosToEnd(void)
{
    int iArr[10] = {0,1,0,0,5,0,8,0,12,9};
    int iLen = 10;
    int Cnt = 0;

    printf("Before moving zeros to end: ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    for(int i = 0; i < iLen; ++i)
    {
        if(iArr[i] != 0)
        {
            iArr[Cnt++] = iArr[i];
        }
    }

    while(Cnt < iLen)
    {
        iArr[Cnt++] = 0;
    }


    printf("After moving zeros to end: ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");
}

void FindLongestWordInStr(void)
{
    char cStr[] = "Find the Longeeest happpppieeeest word in this string";
    int iMaxLen = 0;
    char * pcTemp = cStr;
    int iTempLen = 0;
    char* pcLongestBegin = NULL;
    char cRes[100];

    while (*pcTemp) {
        if (*pcTemp != ' ')
        {
            iTempLen++;
        } 
        else
        {
            // End of word
         if (iTempLen > iMaxLen) 
         {
            iMaxLen = iTempLen;
            pcLongestBegin = pcTemp - iTempLen; // because we are at space, so the word ends at pcTemp-1, starts at pcTemp - iTempLen
         }
            iTempLen = 0; // reset for next word
        }
            pcTemp++;
        }
        // After loop, check the last word
        if (iTempLen > iMaxLen)
         {
            iMaxLen = iTempLen;
            pcLongestBegin = pcTemp - iTempLen;
        }
    strncpy(cRes,pcLongestBegin,iMaxLen);
    cRes[iMaxLen] = '\0';
    printf("%s",cRes);

    return;
}

void ReverseStr(char* pcWordBegin, char* pcWordEnd)
{
    while(pcWordBegin < pcWordEnd)
    {
        char cTemp = *pcWordBegin;
        *pcWordBegin++ = *pcWordEnd;
        *pcWordEnd-- = cTemp;
    }

    return;
}

void ReverseWordOrders(void)
{
    char cStr[] = "This word is getting reversed";
    int iLen = strlen(cStr);
    char* pcWordBegin = cStr;
    char* pcTemp = cStr;


    printf("Before Reversal: %s\n",cStr);

    while(*pcTemp)
    {
        pcTemp++;
        if(*pcTemp == ' ')
        {
            ReverseStr(pcWordBegin, pcTemp - 1);
            pcWordBegin = pcTemp + 1;
        }

        if(*pcTemp == '\0')
        {
            ReverseStr(pcWordBegin, pcTemp - 1);
        }
    }
    ReverseStr(cStr,pcTemp-1);
    printf("After Reversal: %s\n",cStr);

    return;
}

void GetMaxConsecOnes(void)
{
    int iArr[15] = {0,1,1,1,1,0,0,1,0,1,1,1,1,1,1};
    int iLen = 15;
    int iMaxOneCnt = 0;
    int tempCnt = 0;

    for(int i = 0; i < iLen; ++i)
    {
        if(1 == iArr[i])
        {
            tempCnt += 1;
            if(tempCnt > iMaxOneCnt)
            {
                iMaxOneCnt = tempCnt;
            }
        }
        else
        {
            tempCnt = 0;
        }
    }
    printf("The maximum ones count is %d\n",iMaxOneCnt);

    return;
}

void AvgOfIntUsingPtr(void)
{
    int x = 10,y = 20,z = 30;
    int* ptrArr[3] = {&x,&y,&z};
    float iAvg = 0;

    for(int i = 0; i < 3; ++i)
    {
        iAvg += *ptrArr[i];
    }
    iAvg /= 3;

    printf("The average value is : %.2f\n",iAvg);

    return;
}

void Func1(void)
{
    printf("Func1 is called\n");
}

void Func2(void)
{
    printf("Func2 is called\n");
}

void Func3(void)
{
    printf("Func3 is called\n");
}

void ArrOfPtrToFunc(void)
{
    void (*pFuncArr[3])(void) = {Func1,Func2,Func3};

    for(int i = 0; i < 3; ++i)
    {
        pFuncArr[i]();
    }
}

void ArrOfPtrToStruct(void)
{
    Student s1 = {10,"Salman"};
    Student s2 = {11,"Akshay"};
    Student s3 = {12,"Aswin"};
    Student s4 = {13,"Juliet"};
    Student s5 = {14,"Rezin"};

    Student* ptArr[5] = {&s1, &s2, &s3, &s4, &s5};

    for(int i = 0; i < 5; ++i)
    {
        printf("Id : %d, Name : %s\n",ptArr[i]->id,ptArr[i]->Name);
    }

    return;
}
void PrintStudentDetails(Student* ptStudent)
{
    if(NULL != ptStudent)
    {
        printf("Name: %s, Id: %d\n",ptStudent->Name,ptStudent->id);
    }
}

void StructToFuncByRefDemo(void)
{
    Student s1 = {10,"Salman"};
    PrintStudentDetails(&s1);

    return;
}

void OutPutSourceCode(void)
{
    FILE* fPtr;
    char ch;

    fPtr = fopen("Test_9.c","r");

    if(fPtr != NULL)
    {
        while((ch = fgetc(fPtr)) != EOF)
        {
            printf("%c",ch);
        }
        printf("\n");
    }
    else
    {
        printf("Memory allocation failed\n");
    }
}

void DMAforStructDemo(void)
{
    Student * s1;

    s1 = (Student*)malloc(sizeof(Student));

    if(NULL != s1)
    {
        s1->id = 10;
        strcpy(s1->Name,"Salman");

        printf("Name: %s, Id: %d\n",s1->Name,s1->id);

        free(s1);
    }
    else
    {
        printf("Memory allocation failure\n");
    }

    return;
}

int GetSquare(int n)
{
    return(n*n);
}

void PerformCallBAck(int(*Func)(int),int val)
{
    if(NULL != Func)
    {
        int Sq = Func(val);

        printf("The square of the number is : %d\n",Sq);
    }
    else
    {
        printf("Invalid parameters\n");
    }

    return;
}

void CallBackFuncDemo(void)
{
    int(*FunPtr)(int) = GetSquare;
    int val = 2;
    PerformCallBAck(FunPtr,val);

    return;
}

// Function to calculate GCD using Euclidean algorithm
int calculateGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM using GCD
int calculateLCM(int a, int b) {
    return (a * b) / calculateGCD(a, b);
}

void CalculateLCMandGCD(void)
{
    int x = 48, y = 18;
    printf("The GCD of %d and %d is %d\n",x,y,calculateGCD(x,y));
    printf("The LCM of %d and %d is %d\n",x,y,calculateLCM(x,y));

    return;
}

void Convert1DArrTo2DArr(void)
{
    int i1DArr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int i1DArrSize = 12;
    int iCols = 4;
    int iRows = 3;
    int i2DArr[iRows][iCols];
    int k = 0;

    if(i1DArrSize != (iCols* iRows))
    {
        printf("Not possible, due to dimension mismatch\n");
    }
    else
    {
        for(int i = 0; i < iRows; ++i)
        {
            for(int j = 0; j < iCols; ++j)
            {
                i2DArr[i][j] = i1DArr[k];
                k += 1;
            }
        }

        printf("The 2D Array is\n");

        for(int i = 0; i < iRows; ++i)
        {
            for(int j = 0; j < iCols; ++j)
            {
                printf("%d ",i2DArr[i][j]);
            }
            printf("\n");
        }
    }

    return;
}

void CalcPivotIdxOfArr(void)
{
    int iArr[6] = {1, 7, 3, 6, 5, 6};
    int iTotSum = 0;
    int iLeftSum = 0;
    int iRightSum = 0;

    for(int i = 0; i < 6; ++i)
    {
        iTotSum += iArr[i];
    }

    for(int i = 0; i < 6; ++i)
    {
        iRightSum = iTotSum - iLeftSum - iArr[i];

        if(iRightSum == iLeftSum)
        {
            printf("The pivot element is %d and the pivot index is %d\n",iArr[i],i);
            break;
        }
        iLeftSum += iArr[i];
    }

    return;
}

void GetLongestCntIncrsngSubSeqnce(void)
{
    int iArr[10] = {67,89,1,2,3,4,5,6,0,1};
    int maxLen = 1;  // At least one element is always there
    int currLen = 1;

    for (int i = 1; i < 10; i++) {
        if (iArr[i] > iArr[i - 1]) {
            currLen++;
            if (currLen > maxLen)
                maxLen = currLen;
        } else {
            currLen = 1; // reset when sequence breaks
        }
    }
    printf("The maximum continous increasing sub sequence length is %d\n",maxLen);

    return;
}

void InsertionSort(void)
{
    int iArr[10] = {4,1,3,8,90,-1,7,12,0,-78};
    int iKey = 0;
    int j = 0;

    printf("Array Before insertion sort : ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    for(int i = 1; i < 10; ++i)
    {
        j = i - 1;
        iKey = iArr[i];

        while(j >= 0
        && iArr[j] > iKey)
        {
            iArr[j + 1] = iArr[j];
            j -= 1;
        }

        iArr[j+1] = iKey;
    }

    printf("Array Before insertion sort : ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    return;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // choosing last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // sort left side
        quickSort(arr, pi + 1, high); // sort right side
    }
}

void QuickSortDemo(void)
{
    int iArr[10] = {4,1,3,8,90,-1,7,12,0,-78};

    printf("Array Before Quick sort : ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");
    quickSort(iArr,0, 10);

    printf("Array After Quick sort : ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    return;
}

void PrintPattern1(void)
{
    int n = 5; // Number of rows
    for(int i = 1; i <= n; i++) 
    {
        int start;
        if (i % 2 == 1) {
            // Odd row: Increasing order
            start = (i * (i - 1)) / 2 + 1;
            for(int j = 0; j < i; j++) {
                printf("%d ", start + j);
            }
        } else {
            // Even row: Decreasing order
            start = (i * (i + 1)) / 2;
            for(int j = 0; j < i; j++) {
                printf("%d ", start - j);
            }
        }
        printf("\n");
    }
    return;
}

void PrintPattern2(void)
{
    int n = 9; // Total number of rows

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || j == n - i - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
