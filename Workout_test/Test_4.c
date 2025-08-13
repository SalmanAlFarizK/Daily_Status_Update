#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void GeneraterandomNumber(void);
void PrintNFibanocciSeq(void);
void BinarySearch(void);
void CheckForPalliandromeArr(void);
void MergeSortedArrays(void);
void CountAndPrintNoOfConsecutiveElts(void);
void GetStartIdxOfSubStrInStr(void);
void FindLongestPalliandromicSubstrWithinStr(void);

int main()
{
    FindLongestPalliandromicSubstrWithinStr();
    return 0;
}

void GeneraterandomNumber(void)
{
    int iRandNo = rand();
    printf("The random number generated is %d\n",rand);
    return;
}

void PrintNFibanocciSeq(void)
{
    int N = 20;
    int Prev2 = 0, Prev1 = 1;
    int Curr = 0;

    printf("%d ",Prev2);
    printf("%d ",Prev1);

    for(int i = 2; i < N; ++i)
    {
        Curr = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = Curr;
        printf("%d ",Curr);
    }
    printf("\n");

    return;
}

void BinarySearch(void)
{
    int iArr[10] = {1,2,3,4,5,6,7,8,9,10};
    int iSearchElt = 7;
    int iLen = 10;
    int left = 0, right = iLen - 1, mid;
    int found = 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (iArr[mid] == iSearchElt) {
            printf("Element %d found at index %d\n", iSearchElt, mid);
            found = 1;
            break;
        } else if (iArr[mid] < iSearchElt) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Element %d not found in array\n", iSearchElt);
    }
}

void CheckForPalliandromeArr(void)
{
    int iArr[9] = {1,2,3,4,5,4,3,2,1};
    int iLen = 9;

    int isPalliandrome = 1;

    for(int i = 0; i < iLen/2; ++i)
    {
        if(iArr[i] != iArr[iLen-i-1])
        {
            isPalliandrome = 0;
            break;
        }
    }

    if(isPalliandrome)
    {
        printf("The Array is palliandromic\n");
    }
    else
    {
        printf("The array is not palliandromic\n");
    }

    return;
}

void MergeSortedArrays(void)
{
    int iArr1[5] = {1,3,5,7,9};
    int iArr2[5] = {2,4,6,8,10};
    int Len1 = 5, Len2 = 5;
    int iresLen = Len1 + Len2;
    int iRes[iresLen];
    int i = 0, j = 0;
    int k = 0;

    while(i < Len1
       && j < Len2)
    {
        if(iArr1[i] <= iArr2[j])
        {
            iRes[k++] = iArr1[i++];
        }
        else
        {
            iRes[k++] = iArr2[j++];
        }
    }

    while(i < Len1)
    {
        iRes[k++] = iArr1[i++];
    }

    while(j < Len2)
    {
        iRes[k++] = iArr2[j++];
    }
    printf("The sorted array is : ");
    for(int p = 0; p < k; ++p)
    {
        printf("%d ",iRes[p]);
    }
    printf("\n");

    return;
}

void CountAndPrintNoOfConsecutiveElts(void)
{
    int Arr[5] = {10, 8, 9, 12, 11};
    int iCnsecCnt = 0;

    for(int i = 0; i < 5; ++i)
    {
        if(Arr[i+1] - Arr[i] == 1 || Arr[i] - Arr[i+1] == 1)
        {
            iCnsecCnt += 1;
            printf("Consecutive elements found (%d,%d)\n",Arr[i],Arr[i+1]);
        }
    }

    printf("Total number of consecutive pairs: %d\n", iCnsecCnt);

    return;
}

void GetStartIdxOfSubStrInStr(void)
{
    char cStr[] = "cat is at mat of rat :)";
    char cSubStr[] = "at";

    for(int i = 0; i < strlen(cStr); ++i)
    {
        int Flag = 0;
        if(cStr[i] == cSubStr[0])
        {
            Flag = 1;
            for(int j = 0; cSubStr[j] != '\0'; ++j)
            {
                if(cStr[i + j] != cSubStr[j])
                {
                    Flag = 0;
                    break;
                }
            }
        }
        
        if(Flag == 1)
        {
            printf("Substring '%s' is found at index %d \n",cSubStr,i);
        }
    }

    return;
}

void FindLongestPalliandromicSubstrWithinStr(void)
{
    char str[] = "Hello";
    char result[100];
    int n = strlen(str);
    int maxLength = 1, start = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int flag = 1;

            // Check palindrome
            for (int k = 0; k < (j - i + 1) / 2; k++) {
                if (str[i + k] != str[j - k]) {
                    flag = 0;
                    break;
                }
            }

            // If palindrome and longer than current max
            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    // Copy the longest palindromic substring to result
    strncpy(result, str + start, maxLength);
    result[maxLength] = '\0'; // Null-terminate the string

    printf("%s",result);

    return;
}

