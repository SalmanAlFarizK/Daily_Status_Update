#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/********************************************************
 * Structure declaration.
 ********************************************************/
typedef struct _Node_
{
    int iData;
    struct _Node_* ptNext;
} Node;

/********************************************************
 * Enum declaration.
 ********************************************************/
typedef enum _eLinkedListOp_
{
    eInsert = 1,
    eDelete,
    eDisplay,
    eReverse,
    eExit
} eLinkedListOp;

typedef enum _eLinkedListInsertOp_
{
    eInserAtEnd = 1,
    eInsertAtBegin,
    eInsertAtSpecificPos
} eLinkedListInsertOp;

typedef enum _eLinkedListDeleteOp_
{
    eDelFromEnd = 1,
    eDelFromBegin,
    eDelFromSpecificPos
} eLinkedListDeleteOp;

typedef enum _eLinkedListRevOp_
{
    eRevEntireLL = 1,
    eRevSpecificPos,
    eRevEveryNNodes
} eLinkedListRevOp;

typedef enum _eLinkedListDispOp_
{
    eDispFwdTraversal = 1,
    eDispBckwdTraversal
} eLinkedListDispOp;

/********************************************************
 * Function declaration.
 ********************************************************/
void OperationSelector(int iOpertion, Node** Head);
void LinkedListInsetOperation(Node** Head);
void LinkedListDeleteOperation(Node** Head);
void LinkedListReverseOperation(Node** Head);
void LinkedListDisplayOperation(Node* Head);

/********************************************************
 * Static function declaration.
 ********************************************************/
static Node* CreateNode(int iData);
static Node* InsertAtEndOfLinkedList(Node* Head);
static Node* InsertAtBeginOfLinkedList(Node* Head);
static Node* InsertAtSpecificPosOfLinkedList(Node* Head);

static Node* DeleteFromEndOfLinkedList(Node* Head);
static Node* DeleteFromBeginOfLinkedList(Node* Head);
static Node* DeleteFromSpecificPosOfLinkedList(Node* Head);

static Node* ReverseEntireLinkedList(Node* Head);
static Node* ReverseFromSpecificPosOfLinkedList(Node* Head);
static Node* ReverseEveryNNodesOfLinkedList(Node* Head);

static void DisplayLinkedListFwdTraversal(Node* Head);
static void DisplayLinkedListBckWdTraversal(Node* Head);

/********************************************************
 * Main Function.
 ********************************************************/
int main()
{
    int iChoice;
    Node* Head = NULL;

    do
    {
        printf("\nEnter a linked list operation to be done:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Reverse\n");
        printf("5. Exit\n");

        scanf("%d", &iChoice);

        OperationSelector(iChoice, &Head);

    } while(iChoice != eExit);

    return 0;
}

/********************************************************
 * Function definition.
 ********************************************************/
void OperationSelector(int iOpertion, Node** Head)
{
    switch(iOpertion)
    {
        case eInsert:
            LinkedListInsetOperation(Head);
            break;

        case eDelete:
            LinkedListDeleteOperation(Head);
            break;

        case eDisplay:
            LinkedListDisplayOperation(*Head);
            break;

        case eReverse:
            LinkedListReverseOperation(Head);
            break;

        case eExit:
            printf(".....Exiting.....\n");
            break;

        default:
            printf("Enter a valid option\n");
    }
}

void LinkedListInsetOperation(Node** Head)
{
    int iChoice;
    printf("Enter type of insert operation\n");
    printf("1. Insert at end\n");
    printf("2. Insert at beginning\n");
    printf("3. Insert at specific position\n");

    scanf("%d", &iChoice);

    switch(iChoice)
    {
        case eInserAtEnd:
            *Head = InsertAtEndOfLinkedList(*Head);
            break;

        case eInsertAtBegin:
            *Head = InsertAtBeginOfLinkedList(*Head);
            break;

        case eInsertAtSpecificPos:
            *Head = InsertAtSpecificPosOfLinkedList(*Head);
            break;

        default:
            printf("Enter a valid insert operation\n");
    }
}

void LinkedListDeleteOperation(Node** Head)
{
    int iChoice;
    printf("Enter type of delete operation\n");
    printf("1. Delete from end\n");
    printf("2. Delete from beginning\n");
    printf("3. Delete from specific position\n");

    scanf("%d", &iChoice);

    switch(iChoice)
    {
        case eDelFromEnd:
            *Head = DeleteFromEndOfLinkedList(*Head);
            break;

        case eDelFromBegin:
            *Head = DeleteFromBeginOfLinkedList(*Head);
            break;

        case eDelFromSpecificPos:
            *Head = DeleteFromSpecificPosOfLinkedList(*Head);
            break;

        default:
            printf("Enter a valid delete operation\n");
    }
}

void LinkedListReverseOperation(Node** Head)
{
    int iChoice;
    printf("Enter type of reverse operation\n");
    printf("1. Reverse entire linked list\n");
    printf("2. Reverse linked list from specific positions\n");
    printf("3. Reverse every N nodes of a linked list\n");

    scanf("%d", &iChoice);

    switch(iChoice)
    {
        case eRevEntireLL:
            *Head = ReverseEntireLinkedList(*Head);
            break;

        case eRevSpecificPos:
            *Head = ReverseFromSpecificPosOfLinkedList(*Head);
            break;

        case eRevEveryNNodes:
            *Head = ReverseEveryNNodesOfLinkedList(*Head);
            break;

        default:
            printf("Enter a valid reverse operation\n");
    }
}

void LinkedListDisplayOperation(Node* Head)
{
    int iChoice;
    printf("Enter type of display operation\n");
    printf("1. Display from starting to ending\n");
    printf("2. Display from ending to starting\n");

    scanf("%d", &iChoice);

    switch(iChoice)
    {
        case eDispFwdTraversal:
            DisplayLinkedListFwdTraversal(Head);
            break;

        case eDispBckwdTraversal:
            DisplayLinkedListBckWdTraversal(Head);
            break;

        default:
            printf("Enter a valid display operation\n");
    }
}

/********************************************************
 * Node Creation
 ********************************************************/
static Node* CreateNode(int iData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    if (NewNode != NULL)
    {
        NewNode->iData = iData;
        NewNode->ptNext = NULL;
    }

    return NewNode;
}

/********************************************************
 * Insert operations
 ********************************************************/
static Node* InsertAtEndOfLinkedList(Node* Head)
{
    int iData;
    printf("Enter the data to be inserted at end\n");
    scanf("%d", &iData);

    Node* EndNode = CreateNode(iData);

    if (Head == NULL)
    {
        return EndNode;
    }

    Node* Temp = Head;
    while (Temp->ptNext != NULL)
    {
        Temp = Temp->ptNext;
    }
    Temp->ptNext = EndNode;

    return Head;
}

static Node* InsertAtBeginOfLinkedList(Node* Head)
{
    int iData;
    printf("Enter the data to be inserted at beginning\n");
    scanf("%d", &iData);

    Node* BeginNode = CreateNode(iData);
    BeginNode->ptNext = Head;

    return BeginNode;
}

static Node* InsertAtSpecificPosOfLinkedList(Node* Head)
{
    int iPos, iData;
    printf("Enter the position (0-based) to insert in the linked list:\n");
    scanf("%d", &iPos);

    printf("Enter the data to be inserted at position %d:\n", iPos);
    scanf("%d", &iData);

    Node* SpecificNode = CreateNode(iData);

    if (iPos == 0)
    {
        SpecificNode->ptNext = Head;
        return SpecificNode;
    }

    Node* Temp = Head;
    for (int i = 0; i < iPos - 1 && Temp != NULL; ++i)
    {
        Temp = Temp->ptNext;
    }

    if (Temp == NULL)
    {
        printf("Invalid position!\n");
        free(SpecificNode);
        return Head;
    }

    SpecificNode->ptNext = Temp->ptNext;
    Temp->ptNext = SpecificNode;

    return Head;
}

/********************************************************
 * Delete operations
 ********************************************************/
static Node* DeleteFromEndOfLinkedList(Node* Head)
{
    if (Head == NULL)
    {
        printf("Empty linked list\n");
        return NULL;
    }

    if (Head->ptNext == NULL)
    {
        printf("Deleted %d from linked list\n", Head->iData);
        free(Head);
        return NULL;
    }

    Node* Temp = Head;
    Node* Prev = NULL;

    while (Temp->ptNext != NULL)
    {
        Prev = Temp;
        Temp = Temp->ptNext;
    }

    Prev->ptNext = NULL;
    printf("Deleted %d from linked list\n", Temp->iData);
    free(Temp);

    return Head;
}

static Node* DeleteFromBeginOfLinkedList(Node* Head)
{
    if (Head == NULL)
    {
        printf("Empty linked list\n");
        return NULL;
    }

    Node* Temp = Head;
    Head = Temp->ptNext;

    printf("Deleted %d from linked list\n", Temp->iData);
    free(Temp);

    return Head;
}

static Node* DeleteFromSpecificPosOfLinkedList(Node* Head)
{
    int iPos;
    printf("Enter the position (0-based) to delete in the linked list:\n");
    scanf("%d", &iPos);

    if (Head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    if (iPos == 0)
    {
        Node* NodeToDelete = Head;
        Head = Head->ptNext;
        printf("Deleted %d from linked list\n", NodeToDelete->iData);
        free(NodeToDelete);
        return Head;
    }

    Node* Temp = Head;
    for (int i = 0; i < iPos - 1 && Temp != NULL; ++i)
    {
        Temp = Temp->ptNext;
    }

    if (Temp == NULL || Temp->ptNext == NULL)
    {
        printf("Invalid position!\n");
        return Head;
    }

    Node* NodeToDelete = Temp->ptNext;
    Temp->ptNext = NodeToDelete->ptNext;
    printf("Deleted %d from linked list\n", NodeToDelete->iData);
    free(NodeToDelete);

    return Head;
}

/********************************************************
 * Reverse operations
 ********************************************************/
static Node* ReverseEntireLinkedList(Node* Head)
{
    Node* Prev = NULL;
    Node* Curr = Head;
    Node* Next = NULL;

    while (Curr != NULL)
    {
        Next = Curr->ptNext;
        Curr->ptNext = Prev;
        Prev = Curr;
        Curr = Next;
    }

    printf("Reversed Entire linked list\n");
    return Prev;
}

static Node* ReverseFromSpecificPosOfLinkedList(Node* Head)
{
    int iStartPos, iEndPos;
    printf("Enter start and end position from where the linked list should be reversed\n");
    scanf("%d", &iStartPos);
    scanf("%d", &iEndPos);

    if (Head == NULL || iStartPos >= iEndPos)
    {
        printf("Invalid input!\n");
        return Head;
    }

    Node Dummy = {0, Head};
    Node* Prev = &Dummy;

    for (int i = 0; i < iStartPos && Prev->ptNext != NULL; i++)
    {
        Prev = Prev->ptNext;
    }

    Node* Curr = Prev->ptNext;
    if (Curr == NULL)
    {
        printf("Start position out of range!\n");
        return Head;
    }

    Node* Tail = Curr;
    Node* Next = NULL;
    Node* RevPrev = NULL;

    for (int i = iStartPos; i <= iEndPos && Curr != NULL; i++)
    {
        Next = Curr->ptNext;
        Curr->ptNext = RevPrev;
        RevPrev = Curr;
        Curr = Next;
    }

    Prev->ptNext = RevPrev;
    Tail->ptNext = Curr;

    printf("Reverse Operation done\n");
    return Dummy.ptNext;
}

static Node* ReverseEveryNNodesOfLinkedList(Node* Head)
{
    int N;
    printf("Enter the number of nodes to reversed\n");
    scanf("%d", &N);

    if (Head == NULL || N <= 1)
    {
        printf("Empty list or No reversal possible\n");
        return Head;
    }

    Node Dummy = {0, Head};
    Node* PrevGroupEnd = &Dummy;
    Node* Curr = Head;

    while (1)
    {
        Node* Temp = Curr;
        int count = 0;
        while (Temp != NULL && count < N)
        {
            Temp = Temp->ptNext;
            count++;
        }
        if (count < N)
        {
            break;
        }

        Node* GroupStart = Curr;
        Node* Prev = NULL;
        Node* Next = NULL;
        for (int i = 0; i < N; i++)
        {
            Next = Curr->ptNext;
            Curr->ptNext = Prev;
            Prev = Curr;
            Curr = Next;
        }

        PrevGroupEnd->ptNext = Prev;
        GroupStart->ptNext = Curr;
        PrevGroupEnd = GroupStart;
    }

    printf("Reverse N node operation completed\n");
    return Dummy.ptNext;
}

/********************************************************
 * Display operations
 ********************************************************/
static void DisplayLinkedListFwdTraversal(Node* Head)
{
    if (Head == NULL)
    {
        printf("Empty linked list\n");
        return;
    }

    printf("The fwd traversal of linked list is : ");
    Node* Temp = Head;
    while (Temp != NULL)
    {
        printf("%d", Temp->iData);
        if (Temp->ptNext != NULL)
        {
            printf("->");
        }
        Temp = Temp->ptNext;
    }
    printf("\n");
}

static void RecurssiveReverseDisplay(Node* ptNode)
{
    if (ptNode == NULL)
    {
        return;
    }

    RecurssiveReverseDisplay(ptNode->ptNext);

    if (ptNode->ptNext == NULL)
        printf("%d", ptNode->iData);
    else
        printf("->%d", ptNode->iData);
}

static void DisplayLinkedListBckWdTraversal(Node* Head)
{
    if (Head == NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    printf("The backward traversal of the linked list is : ");
    RecurssiveReverseDisplay(Head);
    printf("\n");
}
