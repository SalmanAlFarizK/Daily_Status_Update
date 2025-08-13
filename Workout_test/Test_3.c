#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

static bool IsPerfectSquares(int N);

void CharToAscii(void);
void AsciiToChar(void);
void GetDateDifference(void);
void CheckLeapOrNot(void);
void DispAsciiCharecters(void);
void CountTheNoOfSpecificCharInStr(void);
void PrintPrimeNos(void);
void ConvertDecimalToBinary(void);
void SumOfPerfectNaturalNos(void);
void FindHighestPow2LessThanGivenN(void);
void PrintPattern(void);

int main()
{
    PrintPattern();
    return 0;
}

void CharToAscii(void)
{
    char c = 'A';
    printf("The Ascci val of %c is %d\n",c,c);
    return;
}

void AsciiToChar(void)
{
    int AsciiVal = 65;
    printf("The Char val of %d is %c\n",AsciiVal,AsciiVal);
    return;
}

void GetDateDifference(void)
{
    int d1, m1, y1, d2, m2, y2;
    printf("Enter first date (dd mm yyyy): ");
    scanf("%d %d %d", &d1, &m1, &y1);
    printf("Enter second date (dd mm yyyy): ");
    scanf("%d %d %d", &d2, &m2, &y2);

    // Convert both dates to days
    int days1 = y1 * 365 + m1 * 30 + d1;
    int days2 = y2 * 365 + m2 * 30 + d2;

    int diff = abs(days1 - days2);

    printf("Difference between dates is %d days\n", diff);

    return;
}

void CheckLeapOrNot(void)
{
    int iYear = 2000;
    if(iYear % 400 == 0)
    {
        printf("Leap year\n");
    }
    else if(iYear % 100 == 0)
    {
        printf("Not a leap year\n");
    }
    else if(iYear % 4 == 0)
    {
        printf("Leap year\n");
    }
    else
    {
        printf("Not a leap year\n");
    }

    return;
}

void DispAsciiCharecters(void)
{
    int ascii;
    printf("Enter ASCII code (0-127): ");
    scanf("%d", &ascii);

    if (ascii < 0 || ascii > 127) {
        printf("Invalid ASCII code!\n");
        return;
    }

    switch (ascii) {
        // Digits '0' to '9'
        case 48 ... 57:
            printf("Character: '%c'\n", ascii);
            printf("Type: Digit\n");
            break;

        // Uppercase letters 'A' to 'Z'
        case 65 ... 90:
            printf("Character: '%c'\n", ascii);
            printf("Type: Uppercase Letter\n");
            break;

        // Lowercase letters 'a' to 'z'
        case 97 ... 122:
            printf("Character: '%c'\n", ascii);
            printf("Type: Lowercase Letter\n");
            break;

        // Everything else is special character
        default:
            printf("Character: '%c'\n", ascii);
            printf("Type: Special Character\n");
            break;
    }
    return;

}

void CountTheNoOfSpecificCharInStr(void)
{
    char cStr[] = "space is always the science of wonder :)";
    int iLen = strlen(cStr);
    char c = 's';
    int iCharCnt = 0;

    for(int i = 0; i < iLen; ++i)
    {
        if(cStr[i] == c)
        {
            iCharCnt += 1;
        }
    }
    if(iCharCnt > 0)
    {
        printf("The charecter : %c occurs %d times\n",c,iCharCnt);
    }
    else
    {
        printf("The charecter : %c does not occurs in the string\n");
    }

    return;
}

void PrintPrimeNos(void)
{
    int N = 25;
    if(N < 2)
    {
        printf("No prime numbers\n");
    }
    else
    {
        for(int i = 2; i < N; ++i)
        {
            int isPrime = 1;
            for(int j = 2; j*j <= i; ++j)
            {
                if(i % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }

            if(isPrime)
            {
                printf("%d ",i);
            }
        }
    }

    return;
}

void ConvertDecimalToBinary(void)
{
    int iDec = 10;
    int iBinNum[32] = {0};
    int i = 0;

    while(iDec > 0)
    {
        iBinNum[i] = iDec % 2;
        iDec /= 2;
        i++;
    }
    printf("Binary: ");
    for(int j = i - 1; j >= 0; --j)
    {
        printf("%d",iBinNum[j]);
    }
    printf("\n");

    return;
}

static bool IsPerfectSquares(int N)
{
    int iSqrt = 0;
    iSqrt = sqrt(N);

    return (iSqrt * iSqrt == N) ? true : false;
}

void SumOfPerfectNaturalNos(void)
{
    int N = 20;
    int iSum = 0;

    for(int i = 0; i <= N; ++i)
    {
        if(IsPerfectSquares(i))
        {
            iSum += i;
        }
    }

    printf("The Sum is : %d \n",iSum);

    return;
}

void FindHighestPow2LessThanGivenN(void)
{
    int n = 77;
    int res = 1;
    while (res * 2 < n) {
        res *= 2;
    }
    printf("Highest power of 2 less than %d is %d\n", n, res);
}

void PrintPattern(void)
{
    for (int i = 1; i <= 5; i++) {
    // Print leading spaces
    for (int s = 1; s < i; s++) {
        printf(" ");
    }
    // Print first number
    printf("%d", i);

    // Print spaces between numbers
    int midSpaces = 2 * (5 - i);
    for (int s = 1; s <= midSpaces; s++) {
        printf(" ");
    }

        // Print second number if not the middle line
        if (i != 5) {
            printf("%d", 10 - i);
        }
        printf("\n");
    }

}