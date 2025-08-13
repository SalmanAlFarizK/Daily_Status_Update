#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct _Node_
{
    int iData;
    struct _Node_ * ptNext;
} Node;

Node* ptFront = NULL;
Node* ptRear = NULL;

/**********************************************************
 * Static functions
 *********************************************************/
static void Enque(int iVal);
static void Deque(void);
static void Display(void);

/**********************************************************
 * Public functions
 *********************************************************/
void GenerateNFIbanocciTerms(void);
void ConvertBinaryToDecimal(void);
void DeterminePerfectSquareOrNot(void);
void ExtractSubStrFromLargerStr(void);
void ConvertStrToInt(void);
void RightRotArrByKPos(void);
void LeftRotArrByKPos(void);
void FindArrCommonElts(void);
void Dynamic2DArr(void);
void FindMissingInArrXor(void);
void QueueUsingLL(void);

int main()
{
    QueueUsingLL();
    return 0;
}


void GenerateNFIbanocciTerms(void)
{
    int n = 10;
    int prev2 = 0;
    int prev1 = 1;
    int curr;

    printf("%d ", prev2);
    printf("%d ", prev1);

    for(int i = 2; i < n; ++i)
    {
        curr = prev1 + prev2;
        printf("%d ", curr);
        prev2 = prev1;
        prev1 = curr;
    }
    printf("\n");

    return;
}

void ConvertBinaryToDecimal(void)
{
    int binaryVal = 10101001;
    int base = 1;
    int decVal = 0;

    while(binaryVal)
    {
        int lastDigit = binaryVal % 10;
        binaryVal /= 10;

        decVal += lastDigit * base;

        base *= 2;
    }

    printf("%d\n",decVal);

    return;
}

void DeterminePerfectSquareOrNot(void)
{
    int num = 8;
    int sqrtVal = 0;

    sqrtVal = sqrt(num);
    if(sqrtVal * sqrtVal == num)
    {
        printf("%d is perfect square number\n",num);
    }
    else
    {
        printf("%d is not perfect square\n",num);
    }

    return;
}

void ExtractSubStrFromLargerStr(void)
{
    char cStr[] = "Hello C programing :)";
    char cSubStr[20];
    int startPos = 6;
    int length = 12;

    int i = 0;
    while(i < length)
    {
        cSubStr[i] = cStr[i+startPos];
        i++;
    }
    cSubStr[i] = '\0';

    printf("%s",cSubStr);

    return;
}

void ConvertStrToInt(void)
{
    char cStr[] = "1234";
    int iNum = 0;

    for(int i = 0; i < strlen(cStr); ++i)
    {
        iNum = (iNum * 10) + (cStr[i] - '0'); 
    }
    printf("%d",iNum);

    return;
}

void RightRotArrByKPos(void)
{
    int iArr[10] = {1,2,3,4,5,6,7,8,9,10};
    int iLen = 10;
    int iKpos = 2;

    for(int i = 0; i < iKpos; ++i)
    {
        int iLast = iArr[iLen - 1];
        for(int j = iLen - 1; j > 0; --j)
        {
            iArr[j] = iArr[j-1];
        }
        iArr[0] = iLast;
    }
    printf("After right rotaion by %d posintion: ",iKpos);
    for(int i = 0; i < iLen; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    return;
}

void LeftRotArrByKPos(void)
{
    int iArr[10] = {1,2,3,4,5,6,7,8,9,10};
    int iLen = 10;
    int iKpos = 2;

    for(int i = 0; i < iKpos; ++i)
    {
        int iFirst = iArr[0];
        for(int j = 0; j < iLen; ++j)
        {
            iArr[j] = iArr[j+1];
        }
        iArr[iLen - 1] = iFirst;
    }
    printf("After left rotaion by %d posintion: ",iKpos);
    for(int i = 0; i < iLen; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    return;
}

void FindArrCommonElts(void)
{
    int Arr1[6] = {1,2,3,4,5,6};
    int Arr2[6] = {4,5,6,7,6,4};
    int iLen1 = 6, iLen2 = 6;
    int resArr[iLen1];
    int CommonCnt = 0;

    for(int i = 0; i < iLen1; ++i)
    {
        int found = 0;
        // Check if Arr1[i] exists in Arr2
        for(int j = 0; j < iLen2; ++j)
        {
            if(Arr1[i] == Arr2[j])
            {
                found = 1;
                break;
            }
        }
        // Check if already added to resArr
        if(found)
        {
            int alreadyExist = 0;
            for(int k = 0; k < CommonCnt; ++k)
            {
                if(resArr[k] == Arr1[i])
                {
                    alreadyExist = 1;
                    break;
                }
            }
            if(!alreadyExist)
            {
                resArr[CommonCnt++] = Arr1[i];
            }
        }
    }

    printf("Common elements: ");
    for(int i = 0; i < CommonCnt; ++i)
    {
        printf("%d ", resArr[i]);
    }
    printf("\n");

    return;
}

void Dynamic2DArr(void)
{
    int iRows = 3, iCols = 4;
    int * ptr = NULL;

    ptr = (int*)malloc((iRows * iCols)* sizeof(int));

    if(NULL != ptr)
    {
        for(int i = 0; i < iRows * iCols; ++i)
        {
            ptr[i] = i+1;
        }

        for(int i = 0; i < iRows; ++i)
        {
            for(int j = 0; j < iCols; ++j)
            {
                printf("%d ",ptr[i*iCols+ j]);
            }
            printf("\n");
        }

        free(ptr);
    }

    return;
}

void FindMissingInArrXor(void)
{
    int iArr[10] = {1,2,3,4,5,7,8,9,10};
    int iArrXor = 0;
    int iNaturalXor = 0;

    for(int i = 0 ; i < 10; ++i)
    {
        iArrXor ^= iArr[i];
    }

    for(int i = 1; i <= 10; ++i)
    {
        iNaturalXor ^= i;
    }
    int iMssNo = iArrXor ^ iNaturalXor;
    printf("The missing number is : %d\n",iMssNo);

    return;
}

void QueueUsingLL(void)
{
    Enque(1);
    Enque(2);
    Enque(3);
    Enque(4);
    Enque(5);
    Display();
    Deque();
    Display();
}

static void Enque(int iVal)
{
    Node* ptNewNode;
    ptNewNode = (Node*)malloc(sizeof(Node));

    if(NULL != ptNewNode)
    {
        ptNewNode->iData = iVal;
        ptNewNode->ptNext = NULL;

        if(NULL == ptFront
        && NULL == ptRear)
        {
            ptFront = ptRear = ptNewNode;
        }
        else
        {
            ptRear->ptNext = ptNewNode;
            ptRear = ptNewNode;
        }
        printf("%d inserted into the queue\n",iVal);
    }
    else
    {
        printf("Memory allocation failure\n");
    }

    return;
}

static void Deque(void)
{
    int iDeletedData = 0;

    if(NULL == ptFront)
    {
        printf("Underflow occured\n");
    }
    else
    {
        Node* ptTemp = ptFront;
        iDeletedData = ptTemp->iData;
        ptFront = ptFront->ptNext;

        free(ptTemp);
        printf("Deleted %d\n",iDeletedData);
    }

    return;
}

static void Display(void)
{
    if(NULL == ptFront
    && NULL == ptRear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        Node* ptTemp = ptFront;
        while(ptTemp)
        {
            printf("%d",ptTemp->iData);
            if(ptTemp->ptNext != NULL)
            {
                printf("->");
            }
            ptTemp = ptTemp->ptNext;
        }
        printf("\n");
    }

    return;
}