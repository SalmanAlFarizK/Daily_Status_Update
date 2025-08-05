/*****************************************************************************
 * Gobal Includes
 ****************************************************************************/
#include<stdio.h>
#include<stdint.h>
#include<string.h>

/*****************************************************************************
 * Function Declarations
 ****************************************************************************/
void PrintElementsOfArray(void);
void SumAllEltsOfArray(void);
void FindMaxAndMinOfArray(void);
void CountEvenAndOddNum(void);
void CopyArrayFromOneToAnother(void);
void CountNegativeEltsOfArray(void);
void FindForAnElementInArray(void);
void InsertElementAtPosition(void);
void DeleteElementAtPosition(void);
void ReverseArry(void);

/*****************************************************************************
 * Enum Declarations
 ****************************************************************************/
typedef enum _eOperationType_
{
    ePrintElementsOfArray = 1,
    eSumAllEltsOfArray,
    eFindMaxAndMinOfArray,
    eCountEvenAndOddNum,
    eCopyArrayFromOneToAnother,
    eCountNegativeEltsOfArray,
    eFindForAnElementInArray,
    eInsertElementAtPosition,
    eDeleteElementAtPosition,
    eReverseArray,
    eExit
} eOperationType;

/*****************************************************************************
 * Main Function
 ****************************************************************************/
int main() 
{
    int choice;

    do
    {
        printf("Choose an option:\n");
        printf("1. Print elements of an array\n");
        printf("2. Sum all elements of an array\n");
        printf("3. Find maximum and minimum of an array\n");
        printf("4. Count even and odd numbers in an array\n");
        printf("5. Copy array from one to another\n");
        printf("6. Count negative elements of an array\n");
        printf("7. Find for an element in array\n");
        printf("8. Insert an element at a specific position in the array\n");
        printf("9. Delete an element at a specific position in the array\n");
        printf("10. Reverse the array\n");
        printf("11. Exit\n");
        scanf("%d", &choice);   
        switch(choice)
        {
            case ePrintElementsOfArray:
                PrintElementsOfArray();
                break;
            case eSumAllEltsOfArray:
                SumAllEltsOfArray();
                break;
            case eFindMaxAndMinOfArray:
                FindMaxAndMinOfArray();
                break;
            case eCountEvenAndOddNum:
                CountEvenAndOddNum();
                break;
            case eCopyArrayFromOneToAnother:
                CopyArrayFromOneToAnother();
                break;
            case eCountNegativeEltsOfArray:
                CountNegativeEltsOfArray();
                break;
            case eFindForAnElementInArray:
                FindForAnElementInArray();
                break;
            case eInsertElementAtPosition:
                InsertElementAtPosition();
                break;
            case eDeleteElementAtPosition:
                DeleteElementAtPosition();
                break;
            case eReverseArray:
                ReverseArry();
                break;
            case eExit:
                printf("Exiting the program.\n");
                break;   
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != eExit);
    
    return 0;
}

/*****************************************************************************
 * Function Definitions
 ****************************************************************************/
void PrintElementsOfArray(void)
{
    int size = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if(size <= 0)
    {
        printf("Invalid size\n");
        return;
    }
    int arr[size];
    printf("Enter %d elements of the array:\n", size);
    for(int i = 0; i< size; ++i)
    {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are:\n");
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void SumAllEltsOfArray(void)
{
    int size = 0;
    int sum = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if(size <= 0)
    {
        printf("Invalid size\n");
        return;
    }
    int arr[size];
    printf("Enter %d elements of the array:\n", size);
    for(int i = 0; i< size; ++i)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    printf("The sum of all elements in the array is: %d\n", sum);
    return;
}

void FindMaxAndMinOfArray(void)
{
    int arr[5] = {8,3,15,6,2};
    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < 5; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return;
}

void CountEvenAndOddNum(void)
{
    int Arr[5] = {4,7,9,10,22};
    int evenCount = 0, oddCount = 0;
    
    for(int i = 0; i < 5; ++i)
    {
        if(Arr[i] %2 == 0)
        {
            evenCount += 1;
        }
        else
        {
            oddCount += 1;
        }
    }
    printf("Even numbers count: %d\n", evenCount);
    printf("Odd numbers count: %d\n", oddCount);

    return;
}


void CopyArrayFromOneToAnother(void)
{
    int originalArr[5] = {1, 2, 3, 4, 5};
    int copiedArr[5] = {0};

    memcpy(copiedArr, originalArr, sizeof(originalArr));

    printf("Copied Array: ");
    for(int i = 0; i < 5; ++i)
    {
        printf("%d ", copiedArr[i]);
    }
    printf("\n");
    return;
}

void CountNegativeEltsOfArray(void)
{
    int Arr[6] = {-1,3,-4,5,0,-7};
    int negativeCount = 0;

    for(int i = 0; i < 6; ++i)
    {
        if(Arr[i] < 0)
        {
            negativeCount += 1;
        }
    }
    printf("Negative numbers count: %d\n", negativeCount);
    return;
}

void FindForAnElementInArray(void)
{
    int Arr[5] = {10,20,30,40,50};
    int element = 0, found = 0;
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    for(int i = 0; i < 5; ++i)
    {
        if(Arr[i] == element)
        {
            printf("Element %d found at index %d\n", element, i);
            found = 1;
            break;
        }
    }
    if(!found)
    {
        printf("Element %d not found in the array\n", element);
    }

    return;
}

void InsertElementAtPosition(void)
{
    int Arr[5] = {10,20,30,40};
    int element = 0, position = 0;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert the element (0-4): ");
    scanf("%d", &position);
    if(position < 0 || position > 4)
    {
        printf("Invalid position\n");
    }
    else
    {
        for(int i = 4; i > position; --i)
        {
            Arr[i] = Arr[i-1];
        }
        Arr[position] = element;
        printf("Array after insertion: ");
        for(int i = 0; i < 5; ++i)
        {
            printf("%d ", Arr[i]);
        }
        printf("\n");
    }

    return;
}

void DeleteElementAtPosition(void)
{
    int Arr[4] = {10,20,30,40};
    int position = 0;
    printf("Enter the position to delete the element (0-3): ");
    scanf("%d", &position);
    if(position < 0 || position > 3)
    {
        printf("Invalid position\n");
    }
    else
    {
        for(int i = position; i < 3; ++i)
        {
            Arr[i] = Arr[i+1];
        }
        Arr[3] = 0;
        printf("Array after deletion: ");
        for(int i = 0; i < 3; ++i)
        {
            printf("%d ", Arr[i]);
        }
        printf("\n");
    }
    return;
}

void ReverseArry(void)
{
    int Arr[5] = {10,20,30,40,50};
    int start = 0, end = 4;

    while(start < end)
    {
        int temp = Arr[start];
        Arr[start] = Arr[end];
        Arr[end] = temp;
        start += 1;
        end -= 1;
    }
    printf("Reversed Array: ");
    for(int i = 0; i < 5; ++i)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
    return;
}