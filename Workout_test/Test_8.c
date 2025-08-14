#include<stdio.h>
#include<string.h>
#include <ctype.h>


#define TOGGLE_NTH_BIT(num,n)   (num ^ (1 << n))
#define FLIP_BITS(num)          (~(num))
#define COUNT_BITS(num,zeros,ones)  do{\
    zeros = 0;\
    ones = 0;\
    unsigned int n = (unsigned)num;\
    while(n > 0)\
    {\
        if(n & 1)\
        {\
            ones++;\
        }\
        else\
        {\
            zeros++;\
        }\
        n >>= 1;\
    }\
}while(0)
#define CHECK_CASE_IS_LOWER(c)  ((c & ( 1 << 5)) ? 1 : 0)
#define SWAP(num1,num2) do{\
    num1 = num1 ^ num2; \
    num2 = num1 ^ num2; \
    num1 = num1 ^ num2; \
}while(0)

typedef struct _StudentMarks_
{
    int iMarkterm1;
    int iMarkterm2;
    int iMarkterm3;
    int iMarkterm4;
} StudentMarks;

typedef struct _Student_
{
    int id;
    char Name[20];
} Student;

typedef struct _PersonDetails_
{
    char cName[20];
    char cPhNo[20];
    struct _Location_
    {
        char cCity[20];
        char cCountry[20];
    } Location;
} PersonDetails;

typedef struct _Arithametics_
{
    int (*Sum)(int,int);
    int (*Diff)(int,int);
    int (*Product)(int,int);
    float (*Divide)(float,float);
} Arithametics;

typedef struct _Date_
{
    int Day : 8;
    int Month : 8;
    int Year : 16;
} Date;

void CntNoOfZeroAndOnesInBinary(void);
void FindFerqOfDigitInInt(void);
void ToggleCaseOfChar(void);
void  StringSort(void);
void ArrayOfPtrsExample(void);
void StudentMarkAvg(void);
void SwapCntntsOfStructWithPtr(void);
void DisplayPersonDetails(void);
void PerformArithametics(void);
void StructBitFiledDemo(void);
void StructFnOperationsDemo(void);
void StructurePtrDemo(void);
void ToggleNthBitDemo(void);
void FlipBitsDemo(void);
void CountOnesAndZeroBitsDemo(void);
void CheckCaseDemo(void);
void SwapMacroDemo(void);
void PrintPattern1(void);
void PrintPattern2(void);


int main()
{
    PrintPattern2();
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

void ArrayOfPtrsExample(void)
{
    int iArr[5] = {1,2,3,4,5};
    int (*ArrPtr)[5] = &iArr;

    for(int i = 0; i < 5; ++i)
    {
        printf("%d ", (*ArrPtr)[i]);
    }
    printf("\n");
    return;
}

void StudentMarkAvg(void)
{
    StudentMarks tMarks[5] = 
    {
        {45,76,65,32},
        {74,78,95,82},
        {45,32,75,62},
        {94,76,75,42},
        {64,79,55,92},
    };
    int iNoOfTerms = 4;
    float iAvgMarks = 0;

    for(int i = 0; i < 5; ++i)
    {
        iAvgMarks = (tMarks[i].iMarkterm1 + tMarks[i].iMarkterm2 + tMarks[i].iMarkterm3 + tMarks[i].iMarkterm4);
        iAvgMarks /= (float)iNoOfTerms;

        printf("The Average mark of student %d is %.2f\n",i+1, iAvgMarks);
    }
    return;
}

void SwapStudent(Student* s1, Student* s2)
{
    Student temp = *s1;
    *s1 = *s2;
    *s2 = temp;

    return;
}

void SwapCntntsOfStructWithPtr(void)
{
    Student s1 = {10,"salman"};
    Student s2 = {11,"akshay"};
    
    printf("Before swapping\n");
    printf("Student 1 : Id: %d, Name: %s\n",s1.id, s1.Name);
    printf("Student 2 : Id: %d, Name: %s\n",s2.id, s2.Name);

    SwapStudent(&s1, &s2);

    printf("After swapping\n");
    printf("Student 1 : Id: %d, Name: %s\n",s1.id, s1.Name);
    printf("Student 2 : Id: %d, Name: %s\n",s2.id, s2.Name);

    return;
}

void DisplayPersonDetails(void)
{
    PersonDetails Persons[3] = 
    {
        {"Salman","1234567891",{"Ksd","India"}},
        {"Akshay","9876543210",{"Knr","India"}},
        {"Salih","3456789012",{"Tsr","India"}},
    };

    for(int i = 0; i < 3; ++i)
    {
        printf("Name : %s, PhNo: %s, City: %s, Country: %s\n",Persons[i].cName,
             Persons[i].cPhNo,Persons[i].Location.cCity,Persons[i].Location.cCountry);
    }
    return;
}

int Add(int x, int y)
{
    return(x+y);
}

int Sub(int x, int y)
{
    return(x-y);
}

int Mul(int x, int y)
{
    return(x*y);
}

float Div(float x, float y)
{
    return(x/y);
}

void PerformArithametics(void)
{
    Arithametics tArOpns = {Add, Sub, Mul, Div};
    int x, y;
    printf("Enter 2 numbers\n");
    scanf("%d %d",&x,&y);

    printf("The Sum of two numbers is : %d\n",tArOpns.Sum(x,y));
    printf("The difference of two numbers is : %d\n",tArOpns.Diff(x,y));
    printf("The product of two numbers is : %d\n",tArOpns.Product(x,y));
    printf("The Division of two numbers is : %f\n",tArOpns.Divide(x,y));

    return;
}

void StructBitFiledDemo(void)
{
    Date today = {14,8,2025};

    printf("Todays date is : %d/%d/%d\n",today.Day,today.Month,today.Year);
    return;
}

Student GetStructAndReturnStruct(Student s)
{
    printf("The received structre is Name : %s, Id : %d\n",s.Name,s.id);

    s.id = 11;
    strcpy(s.Name, "Akshay");

    return s;
}

void StructFnOperationsDemo(void)
{
    Student s1 = {10, "Salman"};

    s1 = GetStructAndReturnStruct(s1);
    printf("The modified structre is Name : %s, Id : %d\n",s1.Name,s1.id);
    return;
}

void StructurePtrDemo(void)
{
    Student s1 = {21,"Akshay"};
    Student* ptS1 = &s1;

    printf("Name : %s, Id: %d\n",ptS1->Name, ptS1->id);

    return;
}

void ToggleNthBitDemo(void)
{
    unsigned int num = 12;
    int iToggle = 2;
    num = TOGGLE_NTH_BIT(12,2);
    printf("After toggling %d\n",num);
    return;
}

void FlipBitsDemo(void)
{
    unsigned int num = 12;
    printf("Before bit flips: %u\n",num);
    num = FLIP_BITS(num);
    printf("After bit flips: %u\n",num);

    return;
}

void CountOnesAndZeroBitsDemo(void)
{
    int x = 10;
    int zeros = 0, ones = 0;
    COUNT_BITS(10,zeros,ones);
    printf("The number of ones is : %d, zeros is : %d\n",ones,zeros);

    return;
}

void CheckCaseDemo(void)
{
    char cStr[] = "HeLlO";
    for(int i = 0; i < strlen(cStr); ++i)
    {
        if(CHECK_CASE_IS_LOWER(cStr[i]))
        {
            printf("Lower case : %c\n",cStr[i]);
        }
        else
        {
            printf("Upper case : %c\n",cStr[i]);
        }
    }

    return;
}

void SwapMacroDemo(void)
{
    int a = 10, b = 20;
    printf("Before swapping a: %d, b: %d\n",a,b);
    SWAP(a,b);
    printf("After swapping a: %d, b: %d\n",a,b);
    return;
}

void PrintPattern1(void) {
    int n = 5; // total lines
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            // Even row: 2, 4, 6, ... up to 2*i
            for (int j = 1; j <= i; j++) {
                printf("%d", 2*j);
            }
        } else {
            // Odd row: 1, 3, 5, ... up to 2*i - 1
            for (int j = 1; j <= i; j++) {
                printf("%d", 2*j-1);
            }
        }
        printf("\n"); // move to next line after each row
    }
}

void PrintPattern2(void)
{
    int n = 5;
    for (int i = 1; i <= n; i++) {
        // First part: increasing from i to n
        for (int j = i; j <= n; j++) {
            printf("%d", j);
        }
        // Second part: decreasing from (i-1) down to 1
        for (int j = i-1; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
}