#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// Define a structure
typedef struct
{
    int id;
    char name[20];
} Student;


void StructDemo(void);
void StructDMADemo(void);
void MatrixDMADemo(void);
void StrDMADemo(void);
void MallocReAllocDemo(void);


int main()
{
    MallocReAllocDemo();

    return 0;
}

Student updateStudent(Student s)
{
    s.id += 1; // increment ID
    strcat(s.name, " Updated"); // modify name
    return s;  // returning updated structure
}

void InitStruct(Student* s)
{
    s->id = 100;
    strcpy(s->name,"salman");
}

void  StructDemo(void)
{
    Student s1 = {101, "Alice"};
    
    printf("Before Update: ID = %d, Name = %s\n", s1.id, s1.name);

    // Pass structure and receive updated structure
    Student s2 = updateStudent(s1);

    printf("After Update: ID = %d, Name = %s\n", s2.id, s2.name);

    Student s3;
    InitStruct(&s3);
    printf("%s %d\n",s3.name,s3.id);

    return;
}

void StructDMADemo(void)
{
    Student* S = (Student*)malloc(sizeof(Student));

    if(NULL != S)
    {
        S->id = 250;
        strcpy(S->name, "Akshay");

        printf("Id : %d, Name : %s\n",S->id,S->name);

        free(S);
    }
    else
    {
        printf("Error in memory allocation\n");
    }
}

void MatrixDMADemo(void)
{
    int n, i, j;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    // Dynamic allocation of 2D array
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    for (i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed\n");
            // Free previously allocated rows
            for (j = 0; j < i; j++)
                free(matrix[j]);
            free(matrix);
            return;
        }
    }

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int diagSum = 0;
    int maxElem = matrix[0][0];
    for (i = 0; i < n; i++) {
        diagSum += matrix[i][i]; // main diagonal
        for (j = 0; j < n; j++) {
            if (matrix[i][j] > maxElem)
                maxElem = matrix[i][j];
        }
    }

    printf("Sum of diagonal elements: %d\n", diagSum);
    printf("Largest element in the matrix: %d\n", maxElem);

    // Free memory
    for (i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

void StrDMADemo(void)
{
    char * s;
    s = (char*)malloc(sizeof(char)*100);

    if(NULL != s)
    {
        printf("Enter a string : ");
        scanf("%s",s);
        printf("The string enetered is : %s\n",s);
        for(int i = 0; i < strlen(s)/2; ++i)
        {
            char temp = s[i];
            s[i] = s[strlen(s)-i-1];
            s[strlen(s)-i-1] = temp;
        }
        printf("The revesred string is : %s\n",s);
        free(s);
    }
    else
    {
        printf("memory allocation failed\n");
    }
    return;
}

void MallocReAllocDemo(void)
{
    int* Arr;
    int* NewArr;

    Arr = (int*)malloc(sizeof(int)*5);
    if(NULL != Arr)
    {
        for(int i = 0; i < 5; ++i)
        {
            Arr[i] = i+1;
        }
        NewArr = (int*)realloc(Arr,sizeof(int)*8);
        for(int i = 5; i < 8; ++i)
        {
            NewArr[i] = i+1;
        }

        printf("The array elements are : ");
        for(int i = 0; i < 8; ++i)
        {
            printf("%d ",NewArr[i]);
        }
        printf("\n");
        free(NewArr);
    }
    else
    {
        printf("Memory allocation failed\n");
    }

    return;
}
