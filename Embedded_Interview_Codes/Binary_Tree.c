#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node_
{
    int iData;
    struct _Node_* ptLeft;
    struct _Node_* ptRight;
} Node;

Node* CreateNode(int iData);
void PreOrderTraversal(Node* ptNode);
void InOrderTraversal(Node* ptNode);
void InorderIterative(Node* root);
void PostOrderTraversal(Node* ptNode);

int main()
{
    Node* ptRoot = CreateNode(1);
    ptRoot->ptLeft = CreateNode(2);
    ptRoot->ptRight = CreateNode(3);
    ptRoot->ptLeft->ptLeft = CreateNode(4);
    ptRoot->ptLeft->ptRight = CreateNode(5);
    ptRoot->ptRight->ptRight = CreateNode(6);

    printf("Pre-Order Traversal: ");
    PreOrderTraversal(ptRoot);
    printf("\n");

    printf("In-Order Traversal: ");
    InOrderTraversal(ptRoot);
    printf("\n");

    printf("In-Order Iterative Traversal: ");
    InorderIterative(ptRoot);
    printf("\n");

    printf("Post-Order Iterative Traversal: ");
    PostOrderTraversal(ptRoot);
    printf("\n");

    return 0;
}

Node* CreateNode(int iData)
{
    Node* ptNewNode = NULL;

    ptNewNode = (Node*)malloc(sizeof(Node));
    if(NULL != ptNewNode)
    {
        ptNewNode->iData = iData;
        ptNewNode->ptLeft = NULL;
        ptNewNode->ptRight = NULL;
    }

    return ptNewNode;
}

void PreOrderTraversal(Node* ptNode)
{
    if(NULL != ptNode)
    {
        printf("%d ",ptNode->iData);
        PreOrderTraversal(ptNode->ptLeft);
        PreOrderTraversal(ptNode->ptRight);
    }
    else if(ptNode == NULL)
    {
        return;
    }
    return;
}

void InOrderTraversal(Node* ptNode)
{
    if(NULL != ptNode)
    {
        InOrderTraversal(ptNode->ptLeft);
        printf("%d ",ptNode->iData);
        InOrderTraversal(ptNode->ptRight);
    }
    else
    {
        return;
    }
}

// Iterative Inorder Traversal
void InorderIterative(Node* root) 
{
    Node* stack[100]; // fixed size stack
    int top = -1;

    Node* curr = root;

    while (curr != NULL || top != -1) {
        // Reach the leftmost node
        while (curr != NULL) {
            stack[++top] = curr;   // push
            curr = curr->ptLeft;
        }

        // curr is NULL → pop from stack
        curr = stack[top--];
        printf("%d ", curr->iData);  // visit node

        // Move to right subtree
        curr = curr->ptRight;
    }
}

void PostOrderTraversal(Node* ptNode)
{
    if(NULL != ptNode)
    {
        PostOrderTraversal(ptNode->ptLeft);
        PostOrderTraversal(ptNode->ptRight);
        printf("%d ",ptNode->iData);
    }

    return;
}

