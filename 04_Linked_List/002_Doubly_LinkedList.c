#include <stdio.h>
#include <stdlib.h>

typedef struct _Node_
{
    int iData;
    struct _Node_* ptNext;
    struct _Node_* ptPrev;
} Node;

Node* CreateNode(int iData);
void InsertAtEnd(int iData);
void DuoblyLLFwdTraversal(Node* ptHead);
void DuoblyLLBckWdTraversal(Node* ptTail);
void InsetNodeAtBegining(int iData);
void InsertNodeAtPos(int iData,int iPos);
void DeleteAtBeginOfDll(void);
void DeleteAtEndOfDll(void);
void DelAtSpecificPos(int iPos);

Node* Head = NULL;
Node* Temp = NULL;

int main()
{
    InsertAtEnd(1);
    InsertAtEnd(2);
    InsertAtEnd(3);
    InsertAtEnd(4);
    InsertAtEnd(5);
    InsertAtEnd(6);
    InsertAtEnd(7);
    InsertAtEnd(90);

    DuoblyLLFwdTraversal(Head);
    DuoblyLLBckWdTraversal(Temp);
    InsetNodeAtBegining(95);
    DuoblyLLFwdTraversal(Head);
    InsertNodeAtPos(750,2);
    DuoblyLLFwdTraversal(Head);
    DeleteAtBeginOfDll();
    DuoblyLLFwdTraversal(Head);
    DeleteAtBeginOfDll();
    DuoblyLLFwdTraversal(Head);
    DeleteAtEndOfDll();
    DuoblyLLFwdTraversal(Head);
    DelAtSpecificPos(2);
    DuoblyLLFwdTraversal(Head);
    DelAtSpecificPos(4);
    DuoblyLLFwdTraversal(Head);

    return 0;
}

Node* CreateNode(int iData)
{
    Node* ptNewNode = (Node*)malloc(sizeof(Node));

    if(ptNewNode != NULL)
    {
        ptNewNode->iData = iData;
        ptNewNode->ptNext = NULL;
        ptNewNode->ptPrev = NULL;
    }
    return ptNewNode;
}

void InsertAtEnd(int iData)
{
    Node* NewNode = CreateNode(iData);

    if(Head == NULL)
    {
        Head = Temp = NewNode;
    }
    else
    {
        Temp->ptNext = NewNode;
        NewNode->ptPrev = Temp;
        Temp = NewNode;
    }
}

void DuoblyLLFwdTraversal(Node* ptHead)
{
    Node* ptCurr = ptHead;

    printf("Forward traversal: ");
    while(ptCurr != NULL)
    {
        printf("%d", ptCurr->iData);
        if(ptCurr->ptNext != NULL)
        {
            printf("->");
        }
        ptCurr = ptCurr->ptNext;  // move once
    }
    printf("\n");
}

void DuoblyLLBckWdTraversal(Node* ptTail)
{
    Node* Curr = ptTail;

    printf("Backward traversal: ");
    while(Curr != NULL)
    {
        printf("%d",Curr->iData);
        if(Curr->ptPrev != NULL)
        {
            printf("->");
        }
        Curr = Curr->ptPrev;
    }
    printf("\n");
}

void InsetNodeAtBegining(int iData)
{
    Node* BeginingNode = CreateNode(iData);

    Head->ptPrev = BeginingNode;
    BeginingNode->ptNext = Head;
    Head = BeginingNode;

    return;
}

void InsertNodeAtPos(int iData,int iPos)
{
    Node* ptTemp = Head;
    Node* posNode = CreateNode(iData);

    for(int i = 0; i < iPos; ++i)
    {
        ptTemp = ptTemp->ptNext;
    }

    // Case 2: Insert in middle or end
    posNode->ptNext = ptTemp->ptNext;
    posNode->ptPrev = ptTemp;

    if (ptTemp->ptNext != NULL)
        ptTemp->ptNext->ptPrev = posNode;

    ptTemp->ptNext = posNode;

    return;
}

void DeleteAtBeginOfDll(void)
{
    Node* ptDelNode = Head;
    Head = ptDelNode->ptNext;
    Head->ptPrev = NULL;

    free(ptDelNode);

    return;
}

void DeleteAtEndOfDll(void)
{
    Node* ptLastNode = Temp;
    Temp = ptLastNode->ptPrev;
    Temp->ptNext = NULL;

    free(ptLastNode);
    
    return;
}

void DelAtSpecificPos(int iPos)
{
    if (Head == NULL || iPos < 0) {
        return; // empty list or invalid position
    }

    Node* Curr = Head;

    // Traverse to iPos
    for (int i = 0; i < iPos && Curr != NULL; ++i) {
        Curr = Curr->ptNext;
    }

    // If position is out of bounds
    if (Curr == NULL) {
        return;
    }

    // If deleting head
    if (Curr->ptPrev == NULL) {
        Head = Curr->ptNext;
        if (Head != NULL) {
            Head->ptPrev = NULL;
        }
    }
    else {
        Curr->ptPrev->ptNext = Curr->ptNext;
    }

    // If deleting last node
    if (Curr->ptNext != NULL) {
        Curr->ptNext->ptPrev = Curr->ptPrev;
    }

    free(Curr);
}


