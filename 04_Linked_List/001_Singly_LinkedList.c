#include <stdio.h>
#include <stdlib.h>

typedef struct _Node_
{
    int iData;
    struct _Node_ * ptNext;
} Node;

Node * Head = NULL;
Node * Temp = NULL;

void InsertIntoLL(int iData)
{
    Node * NewNode = (Node*)(malloc(sizeof(Node)));

    if(NULL != NewNode)
    {
        NewNode->iData = iData;
        NewNode->ptNext = NULL;
    }
    if(Head == NULL)
    {
        Head = NewNode;
    }
    else
    {
        Temp = Head;
        while(Temp->ptNext != NULL)
        {
            Temp = Temp->ptNext;
        }

        Temp->ptNext = NewNode;
    }
    return;
}

void ReverseFromLeftToRight(void)
{
    int Left = 2, Right = 6;
    if (Head == NULL || Left >= Right)
        return;

    Node dummy;
    dummy.ptNext = Head;
    Node* prev = &dummy;

    // Move prev to node before Left
    for (int i = 1; i < Left; i++) {
        if (prev == NULL)
            return;
        prev = prev->ptNext;
    }

    Node* curr = prev->ptNext;
    Node* next = NULL;

    // Reverse nodes between Left and Right
    for (int i = 0; i < Right - Left; i++) {
        if (curr == NULL || curr->ptNext == NULL)
            break;
        next = curr->ptNext;
        curr->ptNext = next->ptNext;
        next->ptNext = prev->ptNext;
        prev->ptNext = next;
    }

    Head = dummy.ptNext;
    return;
}

void FindNthNodeFromEndofLL(void)
{
    int N = 2;
    Node* pTemp = Head;
    if (Head == NULL)
        return;

    // First, get the length of the list
    int Len = 1;
    int NthData = 0;

    while(pTemp->ptNext != NULL)
    {
        Len += 1;
        pTemp = pTemp->ptNext;
    }

    if (N > Len || N <= 0)
    {
        printf("N is out of range\n");
        return;
    }

    // Find (Len - N + 1)th node from start
    pTemp = Head;
    for (int i = 1; i < (Len - N + 1); i++)
    {
        pTemp = pTemp->ptNext;
    }
    printf("The %dth node from end is: %d\n", N, pTemp->iData);

    return;
}

void PrintLL(void)
{
    Temp = Head;
    while(Temp != NULL)
    {
        printf("%d",Temp->iData);
        if(Temp->ptNext != NULL)
        {
            printf("->");
        }
        Temp = Temp->ptNext;
    }
    printf("\n");

    return;
}

void RemoveDuplicatesFromLL(void)
{
    Node* curr1 = Head;

    while(curr1 != NULL)
    {
        Node* curr2 = curr1;

        while(curr2->ptNext != NULL)
        {
            if(curr2->ptNext->iData == curr1->iData)
            {
                Node* Duplicate = curr2->ptNext;
                curr2->ptNext = curr2->ptNext->ptNext;

                free(Duplicate);
            }
            else
            {
                curr2 = curr2->ptNext;
            }
        }
        curr1= curr1->ptNext;
    }

    return;
}

void RotateLlByKNode(int iKVal)
{
    if(Head == NULL || Head->ptNext == NULL || iKVal == 0)
        return;

    // Step 1: Find length of LL
    int iLlLen = 1;
    Node* Temp = Head;
    while(Temp->ptNext != NULL)
    {
        iLlLen++;
        Temp = Temp->ptNext;
    }

    // Step 2: Effective rotations
    iKVal = iKVal % iLlLen;
    if(iKVal == 0)
    {
        printf("Linked List after %d Rotation : ", iKVal);
        PrintLL();
        return;
    }

    // Step 3: Make the list circular
    Temp->ptNext = Head;

    // Step 4: Find new tail: (Length - K)th node
    int iRotVal = iLlLen - iKVal;
    Node* ptTemp = Head;
    for(int i = 1; i < iRotVal; i++)
    {
        ptTemp = ptTemp->ptNext;
    }

    // Step 5: Break the circle and set new head
    Head = ptTemp->ptNext;
    ptTemp->ptNext = NULL;

    printf("Linked List after %d Rotation : ", iKVal);
    PrintLL();
}

void DeleteNnodesAfterMnodes(int m, int n)
{
    Node* ptTemp = Head;
    Node* ptDel = NULL;
    int i;

    while (ptTemp != NULL)
    {
        // Skip m nodes
        for (i = 1; i < m && ptTemp != NULL; i++)
            ptTemp = ptTemp->ptNext;

        if (ptTemp == NULL)
            return;

        // Start deleting from next node
        ptDel = ptTemp->ptNext;

        // Delete next n nodes
        for (i = 0; i < n && ptDel != NULL; i++)
        {
            Node* ptNextDel = ptDel->ptNext;
            free(ptDel);
            ptDel = ptNextDel;
        }

        // Link the m-th node to the node after deleted ones
        ptTemp->ptNext = ptDel;

        // Move temp to next segment
        ptTemp = ptDel;
    }
}

void ReverseLLSpiralOrder(void)
{
    if (!Head || !Head->ptNext) return;

    // Find the middle using slow and fast pointers
    Node* slow = Head;
    Node* fast = Head;
    Node* prev = NULL;
    
    while (fast && fast->ptNext) {
        prev = slow;
        slow = slow->ptNext;
        fast = fast->ptNext->ptNext;
    }
    
    // Split the list
    Node* second_half = slow;
    if (prev) prev->ptNext = NULL;
    
    // Reverse the second half
    Node* prev_node = NULL;
    Node* current = second_half;
    while (current) {
        Node* next = current->ptNext;
        current->ptNext = prev_node;
        prev_node = current;
        current = next;
    }
    second_half = prev_node;
    
    // Merge alternately
    Node dummy;
    Node* tail = &dummy;
    Node* first = Head;
    
    while (first && second_half) {
        tail->ptNext = first;
        first = first->ptNext;
        tail = tail->ptNext;
        
        tail->ptNext = second_half;
        second_half = second_half->ptNext;
        tail = tail->ptNext;
    }
    
    if (first) tail->ptNext = first;
    if (second_half) tail->ptNext = second_half;
    
    Head = dummy.ptNext;
}

void DeleteNodeFromMiddle(void)
{
    if (Head == NULL || Head->ptNext == NULL)
        return;

    Node *ptTemp = Head;
    int iLen = 1;
    while (ptTemp->ptNext != NULL)
    {
        iLen += 1;
        ptTemp = ptTemp->ptNext;
    }

    int mid = iLen / 2;
    ptTemp = Head;
    Node *prev = NULL;
    for (int i = 0; i < mid; ++i)
    {
        prev = ptTemp;
        ptTemp = ptTemp->ptNext;
    }

    if (prev && ptTemp)
    {
        prev->ptNext = ptTemp->ptNext;
        free(ptTemp);
    }
}

void ReverseLinkedList(void)
{
    Node* Curr = Head, *Prev = NULL, *Next;

    while(Curr != NULL)
    {
        Next = Curr->ptNext;
        Curr->ptNext = Prev;
        Prev = Curr;
        Curr = Next;
    }
    Head = Prev;

    return;
}

Node* RevLLUsingRecc(Node* ptHead)
{
    if(ptHead == NULL ||
       ptHead->ptNext == NULL)
    {
        return ptHead;
    }
    
    Node* revHead = RevLLUsingRecc(ptHead->ptNext);

    // Make the current head's next node point back to the current head.
    // This effectively reverses the link between head and head->next.
    ptHead->ptNext->ptNext = ptHead;

    // Set the current head's next pointer to NULL, as it will become the new tail
    // of the reversed sublist (or the entire list if it's the original head).
    ptHead->ptNext = NULL;

    // Return the new head of the reversed list.
    return revHead;
}

void ReverseLLUsingRecc(void)
{
    Head = RevLLUsingRecc(Head);
    return;
}

void ReverseKNodeInLL(void)
{
    Node *Curr = Head, *Prev = NULL, *Next = NULL;
    Node *Tail = Head;  // after reversal, Tail will be the last node of the reversed segment
    int count = 0;
    int K = 5;

    // Reverse first K nodes
    while (Curr != NULL && count < K) {
        Next = Curr->ptNext;
        Curr->ptNext = Prev;
        Prev = Curr;
        Curr = Next;
        count++;
    }

    // Connect the tail of reversed segment to the rest of the list
    if (Tail != NULL) {
        Tail->ptNext = Curr;
    }

    // Update head to the new first node
    Head = Prev;
}

int main()
{
    InsertIntoLL(1);
    InsertIntoLL(2);
    InsertIntoLL(3);
    InsertIntoLL(4);
    InsertIntoLL(1);
    InsertIntoLL(5);
    InsertIntoLL(1);
    InsertIntoLL(6);
    InsertIntoLL(7);
    InsertIntoLL(4);
    InsertIntoLL(8);
    PrintLL();
    ReverseLLUsingRecc();
    PrintLL();
    ReverseLinkedList();
    PrintLL();
    // ReverseFromLeftToRight();
    // PrintLL();
    // RemoveDuplicatesFromLL();
    // PrintLL();
    // ReverseLinkedList();
    // PrintLL();

    return 0;
}