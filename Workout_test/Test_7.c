#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct _Preson_
{
    char cName[20];
    int iAge;
} Person;

typedef struct _Details_
{
    char Name[20];
    char PhoneNo[20];
    char Emial[20];
} Details;

typedef struct _Date_
{
    int day;
    int month;
    int year;
} Date;

void PrintOccurenceOfDigitInNo(void);
void SumFibanocciAtEvenIdx(void);
void Swap2ArraysUsingPtr(void);
void SearchEltInArrWithPtr(void);
void CheckSumof2PrimeNos(void);
void Access2dArrUsingPtr(void);
void LengthOfStrUsingPtr(void);
void DuplicateStrUsingDMA(void);
void ReverseArrUsingPtrDemo(void);
void CehckPalliandromeStrWithPtr(void);
void Concat2StrWithPtr(void);
void StrCmpDemo(void);
void SortArrUsingPtr(void);
void MultipleReturnWithPtrDemo(void);
void MatrixRot90DegClkWise(void);
void MatrixRot90DegAntiClkWise(void);
void RotateMatrixByKTimes(void);
void CheckSymmetricMatrixUsingPtr(void);
void SortPeopleByAge(void);
void ArrayOfPtrForStruct(void);
void DiffDateByDMA(void);
void PrintPattern(void);


int main()
{
    PrintPattern();
    return 0;
}



void PrintOccurenceOfDigitInNo(void)
{
    int No = 23436;
    int Digit = 3;
    int count = 0;
    int temp = No;

    while (temp > 0) {
        if (temp % 10 == Digit) {
            count++;
        }
        temp /= 10;
    }

    printf("Digit %d occurs %d times in number %d\n", Digit, count, No);

    return;
}

void SumFibanocciAtEvenIdx(void)
{
    int N = 20;
    int prev1 = 1;
    int prev2 = 0;
    int Sum = prev2;

    for(int i = 2; i < N; ++i)
    {
        int Curr = prev1 + prev2;
        if(i % 2 == 0)
        {
            Sum += Curr;
        }
        prev2 = prev1;
        prev1 = Curr;
    }

    printf("The fibanocci sum at even index is : %d\n",Sum);
    return;
}

void Swap(int* Val1, int* Val2)
{
    int temp = *Val1;
    *Val1 = *Val2;
    *Val2 = temp;

    return;
}

void Swap2ArraysUsingPtr(void)
{
    int Arr1[5] = {1,2,3,4,5};
    int Arr2[5] = {6,7,8,9,10};

    printf("Before Swapping Arr1 : ");
    for(int i = 0 ; i < 5; ++i)
    {
        printf("%d ",Arr1[i]);
    }

    printf("\nBefore Swapping Arr2 : ");
    for(int i = 0 ; i < 5; ++i)
    {
        printf("%d ",Arr2[i]);
    }
    printf("\n");

    for(int i = 0; i < 5; ++i)
    {
        Swap(Arr1+i, Arr2+i);
    }

    printf("After Swapping Arr1 : ");
    for(int i = 0 ; i < 5; ++i)
    {
        printf("%d ",Arr1[i]);
    }

    printf("\nAfter Swapping Arr2 : ");
    for(int i = 0 ; i < 5; ++i)
    {
        printf("%d ",Arr2[i]);
    }
    printf("\n");

    return;
}

void SearchEltInArrWithPtr(void)
{
    int Arr[10] = {1,34,235,678,45,23,67,108,980,654};
    int SearchElt = 108;
    int found = 0;

    for(int i = 0; i < 10; ++i)
    {
        if(*(Arr + i) == SearchElt)
        {
            found = 1;
            printf("%d is found at index %d\n",SearchElt,i);
        }
    }

    if(!found)
    {
        printf("%d is not fou d in the array\n");
    }
    return;
}

int checkPrime(int n)
{
  int i, isPrime = 1;

  // 0 and 1 are not prime numbers
  if (n == 0 || n == 1) 
  {
    isPrime = 0;
  }
  else 
  {
    for(i = 2; i <= n/2; ++i)
    {
      if(n % i == 0) 
      {
        isPrime = 0;
        break;
      }
    }
  }

  return isPrime;
}

void CheckSumof2PrimeNos(void)
{
  int n = 500, i, flag = 0;

  for (i = 2; i <= n / 2; ++i) {
    // condition for i to be a prime number
    if (checkPrime(i) == 1) {
      // condition for n-i to be a prime number
      if (checkPrime(n - i) == 1) {
        printf("%d = %d + %d\n", n, i, n - i);
        flag = 1;
      }
    }
  }

  if (flag == 0)
  { 
    printf("%d cannot be expressed as the sum of two prime numbers.", n);
  }

  return;
}

void Access2dArrUsingPtr(void)
{
    int Arr[4][4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16},
    };
    int cols = 4, rows = 4;

    int * ptr = &Arr[0][0];
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            printf("%d ",*(ptr + i * cols + j));
        }
        printf("\n");
    }
    return;
}

void LengthOfStrUsingPtr(void)
{
    char cStr[] = "Hello world , How are you !";
    int iLen = 0;
    char* ptr = cStr;

    while(*ptr != '\0')
    {
        iLen += 1;
        ptr += 1;
    }

    printf("The length is %d\n",iLen);

    return;
}

char* Duplicate(char* Str)
{
    if(NULL != Str)
    {
        char * pcDuplicate = (char*)malloc(sizeof(char) * strlen(Str) + 1);
        if(NULL != pcDuplicate)
        {
            strcpy(pcDuplicate, Str);

            return pcDuplicate;
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}

void DuplicateStrUsingDMA(void)
{
    char cStr[] = "Salman Al Fariz K";
    char* pcDuplicate = NULL;

    pcDuplicate = Duplicate(cStr);

    if(NULL != pcDuplicate)
    {
        printf("Successfully duplicated : %s\n",pcDuplicate);
        free(pcDuplicate);
    }
    else
    {
        printf("Error occured in duplucation\n");
    }

    return;
}

void reverseArr(int* Arr, int Size)
{
    for(int i = 0; i < Size/2; ++i)
    {
        int temp = *(Arr + i);
        *(Arr + i) = *(Arr + Size - i -1);
        *(Arr + Size - i -1) = temp; 
    }

    return;
}

void ReverseArrUsingPtrDemo(void)
{
    int Arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int Size = 10;

    printf("Before reversal : ");
    for(int i = 0; i < Size; ++i)
    {
        printf("%d ",Arr[i]);
    }

    reverseArr(Arr, 10);

    printf("After reversal : ");
    for(int i = 0; i < Size; ++i)
    {
        printf("%d ",Arr[i]);
    }

}

void CehckPalliandromeStrWithPtr(void)
{
    char cStr[] = "madam, in eden, i'm adam";
    int left = 0, right = strlen(cStr) - 1;
    int isPalliandrome = 1;

    while(left < right)
    {
        if(!isalnum(*(cStr + left)))
        {
            left += 1;
            continue;
        }

        if(!isalnum(*(cStr + right)))
        {
            right -= 1;
            continue;
        }

        if(*(cStr + left) != *(cStr + right))
        {
            isPalliandrome = 0;
            break;
        }
        left += 1;
        right -= 1;
    }
    if(isPalliandrome)
    {
        printf("The string is palliandromic\n");
    }
    else
    {
        printf("The string is not palliandromic\n");
    }
    return;
}

void Concat2StrWithPtr(void)
{
    char cStr1[100] = "Hello";
    char cStr2[] = "World";

    char* cPtr1 = cStr1;
    char* cPtr2 = cStr2;

    while(*cPtr1)
    {
        cPtr1 += 1;
    }

    while(*cPtr2)
    {
        *cPtr1 = *cPtr2;
        cPtr1 += 1;
        cPtr2 += 1;
    }

    printf("The concatenated string is : %s\n",cStr1);

    return;
}

int strCmp(char* s1, char* s2)
{
    while(*s1 &&
          (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    return(*s1 - *s2);
}

void StrCmpDemo(void)
{
    char cStr1[] = "salman";
    char cStr2[] = "fariz";

    int res = strCmp(cStr1, cStr2);

    if(res < 0)
    {
        printf("%s lexicographically smaller than %s \n",cStr1,cStr2);
    }
    else if(res > 0)
    {
        printf("%s lexicographically greater than %s \n",cStr1,cStr2);
    }
    else
    {
        printf("%s lexicographically equal to %s \n",cStr1,cStr2);
    }
    return;
}

void SortArrUsingPtr(void)
{
    int iArr[10] = {67,4,23,7,-1,20,34,89,12,600};

    printf("Before sorting : ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    for(int i = 0 ; i < 10; ++i)
    {
        for(int j = i+1; j < 10; ++j)
        {
            if(*(iArr + i) > *(iArr + j))
            {
                int temp = *(iArr + i);
                *(iArr + i) = *(iArr +j);
                *(iArr + j) = temp;
            }
        }
    }
    printf("After sorting : ");
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ",iArr[i]);
    }
    printf("\n");

    return;
}

void GetSumAndProduct(int num1, int num2,int* Sum, int* Product)
{
    if(NULL != Sum
    && NULL != Product)
    {
        *Sum = num1 + num2;
        *Product = num1 * num2;
    }

    return;
}

void MultipleReturnWithPtrDemo(void)
{
    int x = 10;
    int y = 20;
    int Sum = 0, Product = 0;
    GetSumAndProduct(x,y,&Sum,&Product);
    printf("The sum is : %d, The product is : %d \n",Sum,Product);

    return;
}

void MatrixRot90DegClkWise(void)
{
    int n = 3;
    int Matrix[3][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    //1. step1 : Transpose of matrix
    for(int i = 0; i < 3; ++i)
    {
        for(int j = i+1; j < 3; ++j)
        {
            int temp = Matrix[i][j];
            Matrix[i][j] = Matrix[j][i];
            Matrix[j][i] = temp;
        }
    }

    //2. reverse each row
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < n/2; ++j)
        {
            int temp = Matrix[i][j];
            Matrix[i][j] = Matrix[i][n-1-j];
            Matrix[i][n-1-j] = temp;
        }
    }
    printf("The 90 degree clockwise rotation is : \n");
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

void MatrixRot90DegAntiClkWise(void)
{
    int n = 3;
    int Matrix[3][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    //1. step1 : Transpose of matrix
    for(int i = 0; i < 3; ++i)
    {
        for(int j = i+1; j < 3; ++j)
        {
            int temp = Matrix[i][j];
            Matrix[i][j] = Matrix[j][i];
            Matrix[j][i] = temp;
        }
    }

    //2. reverse each coloumn
    for(int j = 0; j < 3; ++j)
    {
        for(int i = 0; i < n/2; ++i)
        {
            int temp = Matrix[i][j];
            Matrix[i][j] = Matrix[n-i-1][j];
            Matrix[n-i-1][j] = temp;
        }
    }
    printf("The 90 degree Anti - clockwise rotation is : \n");
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }
    return;
}

void RotateMatrixByKTimes(void)
{
    int n = 3,m = 3,k = 2;
    int Matrix[3][3] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
  
  // temporary array of size M
  int temp[m];

  // within the size of matrix
  k = k % m;

  for (int i = 0; i < n; i++)
   {

    // copy first M-k elements to temporary array
    for (int t = 0; t < m - k; t++)
      temp[t] = Matrix[i][t];

    // copy the elements from k to end to starting
    for (int j = m - k; j < m; j++)
      Matrix[i][j - m + k] = Matrix[i][j];

    // copy elements from temporary array to end
    for (int j = k; j < m; j++)
      Matrix[i][j] = temp[j - k];
  }
  printf("the rotated matrix is : \n");
  for(int i = 0; i < n; ++i)
  {
    for(int j = 0; j < m; ++j)
    {
        printf("%d ",Matrix[i][j]);
    }
    printf("\n");
  }

  return;
}

void CheckSymmetricMatrixUsingPtr(void)
{
    int Matrix[3][3] = 
    {
        {1,4,7},
        {4,5,6},
        {7,6,9}
    };
    
    int rows = 3, cols = 3;
    bool isSymmetric = true;

    int *pMat = &Matrix[0][0]; // pointer to first element

    for (int i = 0; i < rows && isSymmetric; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // *(pMat + i*cols + j) → element at (i,j)
            // *(pMat + j*cols + i) → element at (j,i)
            if (*(pMat + i*cols + j) != *(pMat + j*cols + i))
            {
                isSymmetric = false;
                break;
            }
        }
    }

    if (isSymmetric)
    {
        printf("Matrix is Symmetric\n");
    }
    else
    {
        printf("Matrix is NOT Symmetric\n");
    }

    return;
}

void SortPeopleByAge(void)
{
    Person peoples[5] = 
    {
        {"Salman",26},
        {"Akshay",25},
        {"Ria",20},
        {"Prajin",38},
        {"Anuragh",50}
    };

    Person* Ptr = peoples;
    printf("Before sorting :\n");
    for(int i = 0; i < 5; ++i)
    {
        printf("Name : %s Age: %d\n",Ptr->cName, Ptr->iAge);
        Ptr += 1;
    }

    Ptr = peoples;

    for(int i = 0; i < 5; ++i)
    {
        for(int j = i+1; j < 5; ++j)
        {
            if((Ptr + i)->iAge > (Ptr +j)->iAge)
            {
                Person temp = *(Ptr + i);
                *(Ptr + i) = *(Ptr + j);
                *(Ptr + j) = temp; 
            }
        }
    }
    printf("After sorting :\n");
    for(int i = 0; i < 5; ++i)
    {
        printf("Name : %s Age: %d\n",Ptr->cName, Ptr->iAge);
        Ptr += 1;
    }
}

void ArrayOfPtrForStruct(void)
{
    Details details[5] = 
    {
        {"Salman","1234567891","abc@gmail.com"},
        {"Akshay","9875347891","aks@gmail.com"},
        {"Aswin","4567893214","asw@gmail.com"},
        {"Prajin","8906542347","prj@gmail.com"},
        {"Raju","3458906542","raj@gmail.com"},
    };

    char cSearchName[] = "Salman";

    Details* Ptr = details;
    for(int i = 0; i < 5; ++i)
    {
        printf("Name: %s, Email: %s, Phone: %s\n",(Ptr +i)->Name,(Ptr +i)->Emial,(Ptr +i)->PhoneNo);
    }
    printf("\n");
    int found = 0;
    for(int i = 0; i < 5; ++i)
    {
        if(strcmp(cSearchName,(Ptr +i)->Name) == 0)
        {
            found = 1;
            printf("Details Found\n");
            printf("Name: %s, Email: %s, Phone: %s\n",(Ptr +i)->Name,(Ptr +i)->Emial,(Ptr +i)->PhoneNo);
            break;
        }
    }

    if(!found)
    {
        printf("Details not present in the directory\n");
    }

    return;
}

void DiffDateByDMA(void)
{
    Date* date1 = NULL;
    Date* date2 = NULL;

    date1 = (Date *)malloc(sizeof(Date));
    date2 = (Date *)malloc(sizeof(Date));
    int TotalNosDaysDate1 = 0;
    int TotalNosDaysDate2 = 0;

    if(NULL != date1
    && NULL != date2)
    {
        date1->day = 22;
        date1->month = 07;
        date1->year = 1999;
        
        date2->day = 21;
        date2->month = 07;
        date2->year = 1999;

        TotalNosDaysDate1 = (date1->year * 365) + (date1->month * 30) + date1->day;
        TotalNosDaysDate2 = (date2->year * 365) + (date2->month * 30) + date2->day;

        printf("The difference between 2 dates is : %d \n",TotalNosDaysDate1 - TotalNosDaysDate2);
    }
    else
    {
        printf("Memory allocation failure\n");
    }
}

void PrintPattern(void)
{
    int rows = 5; // Number of rows in the pattern
    int i, j, k;
    
    for (i = 1; i <= rows; i++) {
        // Print left half of the row
        for (j = i; j <= 2*i-1; j++) {
            printf("%d", j);
        }
        
        // Print right half of the row (in reverse)
        for (k = 2*i-2; k >= i; k--) {
            printf("%d", k);
        }
        
        printf("\n"); // Move to the next line
    }
    return;
}