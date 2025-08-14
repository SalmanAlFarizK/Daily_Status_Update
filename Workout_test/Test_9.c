#include <stdio.h>
#include <string.h>

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

int main()
{
    StructToFuncByRefDemo();
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