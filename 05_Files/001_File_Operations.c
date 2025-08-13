#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CreateFile(void)
{
    FILE * fPtr;

    fPtr = fopen("demo_file.txt","w+");

    fprintf(fPtr,"%s","Welcome to C file Operations!");
    fclose(fPtr);

    return;
}

void readFileAndWriteToAnother(void)
{
    char c;
    char cRes[100] = {0};
    FILE * fptr;
    int i = 0;

    fptr = fopen("demo_file.txt","r");

    while((c = fgetc(fptr)) != EOF)
    {
        cRes[i++] = c;
    }
    cRes[i] = '\0';

    for(int i = 0; i < strlen(cRes)/2; ++i)
    {
        char temp = cRes[i];
        cRes[i] = cRes[strlen(cRes) - i - 1];
        cRes[strlen(cRes) - i - 1] = temp;
    }

    FILE * fptr2 = fopen("new_file.txt","w+");
    fprintf(fptr2,"%s",cRes);

    fclose(fptr);
    fclose(fptr2);

    return;

}

void GetTheNoOfLinesInFile(void)
{
    FILE * fptr = fopen("demo_file.txt","r");
    char c;
    int Lines = 0, HasCnt = 0;

    if (fptr == NULL)
    {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    while((c = fgetc(fptr)) != EOF)
    {
        HasCnt = 1;
        if(c == '\n')
        {
            Lines += 1;
        }
    }

    if(HasCnt)
    {
        Lines += 1;
    }

    fclose(fptr);

    printf("The number of lines is : %d",Lines);
    return;
}

int main()
{
    GetTheNoOfLinesInFile();
}