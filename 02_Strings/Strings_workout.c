#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define TOGGLE_CASE_BIT(c) (c  ^ (1 << 5))

void HighestFreqOfChar(void)
{
    char cStr[] = "engineering";
    int iLen = strlen(cStr);
    int iCnt = 0,iMax = 0;
    char cRes;
    
    for(int i = 0; i < iLen; ++i)
    {
        iCnt = 1;
        for(int j = i+1; j < iLen; ++j)
        {
            if(cStr[i] == cStr[j])
            {
                iCnt += 1;
            }
        }
        
        if(iCnt > iMax)
        {
            iMax = iCnt;
            cRes = cStr[i];
        }
    }
    printf("%c Occurs %d Times\n",cRes,iMax);
    
    return;
}

void FindLowestFreqOfChar(void)
{
    char cStr[] = "engineering";
    int iLen = strlen(cStr);
    int iFreqCnt[256] = {0};
    int iMinFreq = INT_MAX;
    
    for(int i = 0; i < iLen; ++i)
    {
        iFreqCnt[(char)cStr[i]] += 1;
    }
    
    for(int i = 0; i < 256; ++i)
    {
        if(iFreqCnt[i] > 0 && iFreqCnt[i] < iMinFreq)
        {
            iMinFreq = iFreqCnt[i];
        }
    }
    
    printf("The Charecter with lowest frequencies\n");
    for(int i = 0; i < 256; ++i)
    {
        if(iFreqCnt[i] == iMinFreq)
        {
            printf("%c ",i);
        }
    }
    printf("\n");
    
    return;
}

void ReverseString(void)
{
    char cStr[] = "Salman Al Fariz";
    char* pcWordBegin = cStr;
    char* pcWordEnd = cStr;
    
    for(int i = 0; i < strlen(cStr)/2; ++i)
    {
        char cTemp = cStr[i];
        cStr[i] = cStr[strlen(cStr) - i - 1];
        cStr[strlen(cStr) - i - 1] = cTemp;
    }
    
    printf("%s",cStr);
    return;
}

void RemoveExtraBlankSpaces(void)
{
    char cStr[] = " This is ChatGpt ";
    printf("Length Before removing extra spaces %d\n", (int)strlen(cStr));
    
    if(cStr[0] == ' ')
    {
        for(int i = 0; i < strlen(cStr); ++i)
        {
            cStr[i] = cStr[i+1];
        }
    }
    if(cStr[strlen(cStr)-1] == ' ')
    {
        cStr[strlen(cStr)-1] = '\0';
    }
    printf("Length After removing extra spaces %d\n", (int)strlen(cStr));
    return;
}
void ReplaceAllOccurenceWithAnother(void)
{
    char cStr[] = "banana";
    char cFind = 'a';
    char cReplace = 'o';
    
    for(int i = 0; i < strlen(cStr); ++i)
    {
        if(cFind == cStr[i])
        {
            cStr[i] = cReplace;
        }
    }
    
    printf("String After replacing : %s\n",cStr);
    return;
}

void FindFreqOfEachChar(void)
{
    char cStr[] = "success";
    int iLen = strlen(cStr);
    int iFreqCnt[256] = {0};
    
    for(int i = 0; i < iLen; ++i)
    {
        iFreqCnt[(char)cStr[i]] += 1;
    }
    
    for(int i = 0; i < 256; ++i)
    {
        if(iFreqCnt[i] > 0)
        {
            printf("%c --> %d\n",i,iFreqCnt[i]);
        }
    }
    return;
}

void FindFirstOccurenceOfWordInStr(void)
{
    char cStr[] = "this is a test string";
    char cFindWord[] = "test";
    int iStartPosition = 0;
    int i,j,Flag;
    
    for(i = 0; cStr[i] != '\0'; i++)
	{
		if(cStr[i] == cFindWord[0])
		{
			Flag = 1;
			for(j = 0; cFindWord[j] != '\0'; j++)
			{
				if(cStr[i + j] != cFindWord[j])
				{
					Flag = 0;
					break;
				}
			}	
		}
		if(Flag == 1)
		{
			break;
		}	
	 
	}
	if(Flag == 0)
  	{
  		printf("\n Sorry!! We haven't found the Word '%s' ", cFindWord);
	}
	else
	{
		printf("\n We found '%s' at position %d ", cFindWord, i + 1);
	}
	
	return;
}

void CntNoOfWordsInStr(void)
{
    char cStr[] = "C programming is fun";
    int iLen = strlen(cStr);
    int iWordCnt = 0;
    int i = 0;
    
    while(cStr[i] != '\0')
    {
        if(cStr[i] == ' ')
        {
            iWordCnt += 1;
        }
        i += 1;
    }
    
    printf("The Number of words in the given string is : %d\n",iWordCnt + 1);
    
    return;
}

void ToggleCaseOfChar(void)
{
    char cStr[] = "HeLLo";
    for(int i = 0; i < strlen(cStr); ++i)
    {
        cStr[i] = TOGGLE_CASE_BIT(cStr[i]);
    }
    
    printf("%s",cStr);
    
    return;
}

void removeLastOccurenceOfChar(void)
{
    char cStr[] = "mississippi";
    char cRemoveChar = 's';
    int iRemovePos = 0;
    
    for(int i = 0; i < strlen(cStr); ++i)
    {
        if(cStr[i] == cRemoveChar)
        {
            iRemovePos = i;
        }
    }
    
    for(int i = iRemovePos; i < strlen(cStr); ++i)
    {
        cStr[i] = cStr[i+1];
    }
    
    printf("String after last occuring char is : %s\n",cStr);
    
    return;
}

void CountOccurenceOfWord(void)
{
    char cStr[] = "hi hello hi hey hi";
    char cCntWord[]= "hi";
    int iWordCnt = 0;
    int Flag = 0;
    
    for(int i = 0; i < strlen(cStr); ++i)
    {
        Flag = 0;
        if(cStr[i] == cCntWord[0])
        {
            Flag = 1;
            for(int j = 0; cCntWord[j] != '\0'; ++j)
            {
                if(cStr[i + j] != cCntWord[j])
                {
                    Flag = 0;
                    break;
                }
            }
        }
        
        if(Flag == 1)
        {
            iWordCnt += 1;
        }
    }
    printf("The number of words is %d\n",iWordCnt);
    
    return;
}

void CheckIsPalliandrome(void)
{
    char cStr[] = "malayalam";
    bool bIsPalliandrome = true;
    
    for(int i = 0; i < strlen(cStr)/2; ++i)
    {
        if(cStr[i] != cStr[strlen(cStr) - i -1])
        {
            bIsPalliandrome = false;
            break;
        }
    }
    
    if(bIsPalliandrome)
    {
        printf("The Given string is palliandromic\n");
    }
    else
    {
        printf("The Given string is not palliandromic\n");
    }
    
    return;
}

void SwapStrWithoutTemp(void)
{
    char str1[] = "Hello"; 
    char str2[] = "World"; 
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len1 != len2) {
        printf("Strings must be of equal length to swap without temp buffer.\n");
        return;
    }
    
    printf("Before swap: %s %s\n", str1, str2);
    
    for (int i = 0; i < len1; i++) {
        str1[i] ^= str2[i];
        str2[i] ^= str1[i];
        str1[i] ^= str2[i];
    }
    
    printf("After swap: %s %s\n", str1, str2);
    
    return;
}

void SortArrayOfStrings(void)
{
    char ctStr[3][10] =  {"John", "Alice", "Bob"};
    int n = 3;
    char cTemp[10];
    
    printf("Array before sorting : ");
    for(int i = 0; i < n; ++i)
    {
        printf("%s ",ctStr[i]);
    }
    printf("\n");
    
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = 0; j < n-1; ++j)
        {
            if(strcmp(ctStr[j], ctStr[j + 1]) > 0)
            {
                strcpy(cTemp,ctStr[j]);
                strcpy(ctStr[j],ctStr[j+1]);
                strcpy(ctStr[j+1],cTemp);
            }
        }
    }
    
    printf("Array After sorting : ");
    for(int i = 0; i < n; ++i)
    {
        printf("%s ",ctStr[i]);
    }
    printf("\n");
    
    return;
}

void FindMostFreqChar(void)
{
    char cStr[] = "sample stttring";
    int iMostFreqCnt = 0;
    int iTempCnt = 0;
    char cIres;
    
    for(int i = 0; i < strlen(cStr); ++i)
    {
        iTempCnt = 1;
        for(int j = i+1; j < strlen(cStr); ++j)
        {
            if(cStr[i] == cStr[j])
            {
                iTempCnt += 1;
            }
        }
        
        if(iTempCnt > iMostFreqCnt)
        {
            iMostFreqCnt = iTempCnt;
            cIres = cStr[i];
        }
    }
    
    printf("The most appeared charecter is : %c\n",cIres);
    
    return;
}

void RemoveDuplicateChar(void)
{
    char cStr[] = "programming";
    int iLen = strlen(cStr);
    char cUniqueStr[iLen];
    int iUniqueCnt = 0;
    
    for(int i = 0; i < iLen; ++i)
    {
        bool bFound = false;
        
        for(int j = 0; j < iUniqueCnt; ++j)
        {
            if(cStr[i] == cUniqueStr[j])
            {
                bFound = true;
                break;
            }
        }
        
        if(!bFound)
        {
            cUniqueStr[iUniqueCnt] = cStr[i];
            iUniqueCnt += 1;
        }
    }
    
    cUniqueStr[iUniqueCnt] = '\0';
    printf("%s",cUniqueStr);
    
    return;
}

void CharMoreThanOnce(void)
{
    char cStr[] = "programming";
    int iFreqCnt[256] = {0};
    
    for(int i = 0; i < strlen(cStr); ++i)
    {
        iFreqCnt[(char)cStr[i]] += 1;
    }
    
    for(int i = 0; i < 256; ++i)
    {
        if(iFreqCnt[i] > 1)
        {
        printf("%c ",i);
        }
    }
    printf("\n");
    
    return;
}

void RemoveSecStrCharFromFirst(void)
{
    char cStr1[] = "hello world";
    char cStr2[] = "low";
    int len1 = strlen(cStr1);
    int len2 = strlen(cStr2);
    
    for(int i = 0; i < len2; ++i)
    {
        for(int j = 0; j < len1;)
        {
            if(cStr2[i] == cStr1[j])
            {
                for(int k = j; k < len1; ++k)
                {
                    cStr1[k] = cStr1[k+1];
                }
                j -= 1;
            }
            else
            {
                j += 1;
            }
        }
    }
    
    printf("%s",cStr1);
    
    return;
}

void CheckForRoatation(void)
{
    char cStr1[] = "abcd";
    char cStr2[] = "cdab";
    int iItr = 0;
    int iYes = 0;
    
    while(iItr < strlen(cStr1))
    {
        char cLast = cStr1[0];
        for(int i = 0; i < strlen(cStr1)-1; ++i)
        {
            cStr1[i] = cStr1[i+1];
        }
        cStr1[strlen(cStr1)-1] = cLast;
        
        if(!strcmp(cStr1,cStr2))
        {
            iYes = 1;
            break;
        }
        
        iItr += 1;
    }
    
    if(iYes)
    {
        printf("Yes with %d Number of rotations.\n",iItr+1);
    }
    else
    {
        printf("No\n");
    }
    
    return;
}

void ReverseRecursively(char *str, int start, int end)
{
    if (start >= end)
        return;

    // Swap characters
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursive call
    ReverseRecursively(str, start + 1, end - 1);
}

void StringReversalRecursion(void)
{
    char cStr[] = "Hello World";
    int len = strlen(cStr);

    ReverseRecursively(cStr, 0, len - 1);

    printf("Reversed String: %s\n", cStr);
}

void FindNonRepeatingChar(void)
{
    char cStr[] = "swiss";
    int iFreqCnt[256] = {0};
    
    for(int i = 0; i < strlen(cStr); ++i)
    {
        iFreqCnt[(char)cStr[i]] += 1;
    }
    
    for(int i = 0; i < 256; ++i)
    {
        if(iFreqCnt[i] == 1)
        {
            printf("%c appears 1 time\n",i);
        }
    }
    
    return;
}

void FindFirstNonRepeatingChe(void)
{
    char cStr[] = "swiss";
    for(int i = 0; i < strlen(cStr); ++i)
    {
        int cnt = 1;
        
        for(int j = i+1; j < strlen(cStr); ++j)
        {
            if(cStr[i] == cStr[j])
            {
                cnt += 1;
            }
        }
        
        if(cnt == 1)
        {
            printf("%c",cStr[i]);
            break;
        }
    }
    
    return;
}

void PrintWordContainChar(void)
{
    char cWord[] = "act";
    char cStrList[4][10] = {"cat", "tac", "act", "dog"};
    
    for(int i = 0; i < 4; ++i)
    {
        
    }
}

void Reverse(char* pcStart, char* pcEnd)
{
    while(pcStart < pcEnd)
    {
        char cTemp = *pcStart;
        *pcStart++ = *pcEnd;
        *pcEnd-- = cTemp;
    }
    
    return;
}

void ReverseTheOrderOfWords(void)
{
    char cStr[] = "Hello world";
    char* cWordBegin = cStr;
    char* cWordEnd = cStr;
    char* ctemp = cStr;
    
    while(*ctemp)
    {
        ctemp++;
        if(*ctemp == ' ')
        {
            Reverse(cWordBegin, ctemp-1);
            cWordBegin = ctemp + 1;
        }
        
        if(*ctemp == '\0')
        {
            Reverse(cWordBegin, ctemp-1);
        }
    }
    
    Reverse(cStr, ctemp-1);
    
    printf("%s",cStr);
    
    return;
}

void CompressString(void)
{
    char input[] = "aaabbcc";
    int len = strlen(input);
    char compressed[100] = {0}; // Adjust size as needed
    int compIndex = 0;

    for (int i = 0; i < len; )
    {
        char currentChar = input[i];
        int count = 1;

        while (i + 1 < len && input[i] == input[i + 1])
        {
            count++;
            i++;
        }

        // Append char and count to compressed string
        compressed[compIndex++] = currentChar;
        compIndex += sprintf(&compressed[compIndex], "%d", count);

        i++;
    }

    // If compressed string is shorter, print it
    if (strlen(compressed) < len)
        printf("Compressed: %s\n", compressed);
    else
        printf("Compressed: %s\n", input); // Return original if not shorter
}

void FindOccurenceOfPattern(void)
{
    char cText[] = "Hello World";
    char cPattern[] = "lo";

    int lenText = strlen(cText);
    int lenPattern = strlen(cPattern);
    int found = 0;

    for(int i = 0; i <= lenText - lenPattern; ++i)
    {
        int j;
        for(j = 0; j < lenPattern; ++j)
        {
            if(cText[i + j] != cPattern[j])
                break;
        }

        if(j == lenPattern)
        {
            printf("Pattern found at index: %d\n", i);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Pattern not found.\n");
    }
}

void CheckForAnagrams(void)
{
    char cStr1[] = "salm";
    char cStr2[] = "mlsa";
    int iLen1 = strlen(cStr1);
    int iLen2 = strlen(cStr2);
    int iFreqCnt[256] = {0};
    int iSAnagram = 0;
    
    if(iLen2 != iLen1)
    {
        iSAnagram = 0;
    }
    else
    {
        iSAnagram = 1;
        for(int i = 0; i < iLen1; ++i)
        {
            iFreqCnt[(char)cStr1[i]] += 1;
        }
        
        for(int i = 0; i < iLen1; ++i)
        {
            iFreqCnt[(char)cStr2[i]] -= 1;
        }
        
        for(int i = 0; i < 256; ++i)
        {
            if(iFreqCnt[i] != 0)
            {
                iSAnagram = 0;
                break;
            }
        }
    }
    
    if(iSAnagram)
    {
        printf("Anagram Strings \n");
    }
    else
    {
        printf("Not an anagram string\n");
    }
}

void DivideStrIntoNEqualParts(void)
{
    char cStr[] = "abcdefgh";
    int N = 4;
    int iLen = strlen(cStr);
    int iPartSize = 0;
    
    if(iLen % N != 0)
    {
        printf("Dividing by %d is not possible \n",N);
    }
    else
    {
        iPartSize = iLen/N;
        for(int i = 0; i < strlen(cStr); ++i)
        {
            if(i % iPartSize == 0 && i != 0)
            {
                printf("\n");
            }
            printf("%c",cStr[i]);
        }
    }
    
    return;
}

void FindFirstNonRepeatingChar(void)
{
    char cStr[] = "swiss";
    int iLen = strlen(cStr);
    int cnt;
    
    for(int i = 0; i < iLen; ++i)
    {
        int cnt = 1;
        for(int j = i+1; j < iLen; ++j)
        {
            if(cStr[i] == cStr[j])
            {
                cnt += 1;
            }
        }
        
        if(cnt == 1)
        {
            printf("%c",cStr[i]);
            break;
        }
    }
    return;
}

void EncodeStrings(void)
{
    char cStr[] = "aaabbcc";
    int iLen = strlen(cStr);
    char cRes[iLen];
    int iResCnt = 0;
    int iPos = 0;
    
    for(int i = 0; i < iLen; ++i)
    {
        iResCnt = 1;
        
        while(i < iLen - 1 && cStr[i] == cStr[i+1])
        {
            i += 1;
            iResCnt += 1;
        }
        
        iPos += sprintf(cRes + iPos,"%c%d",cStr[i],iResCnt);
    }
    
    printf("%s",cRes);
    
    return;
    
}


int main()
{
    StringReversalRecursion();

    return 0;
}