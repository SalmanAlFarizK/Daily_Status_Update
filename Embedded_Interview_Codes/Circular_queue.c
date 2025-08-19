/*
* Program to implement Circular queue without modulo (%) operator.
*/
#include <stdio.h>
#include <stdbool.h>

#define SIZE 8   // Keep as power of 2 for mask optimization

typedef struct {
    int data[SIZE];
    int head;
    int tail;
} CircularQueue;

// Utility: advance index without modulo
static inline int next_index(int i) {
    return (i + 1 == SIZE) ? 0 : (i + 1);
}

// Initialize queue
void initQueue(CircularQueue* q) {
    q->head = 0;
    q->tail = 0;
}

// Check if queue is empty
bool isEmpty(CircularQueue* q) {
    return (q->head == q->tail);
}

// Check if queue is full
bool isFull(CircularQueue* q) {
    return (next_index(q->head) == q->tail);
}

// Enqueue
bool enqueue(CircularQueue* q, int val) {
    if (isFull(q)) {
        return false; // Queue full
    }
    q->data[q->head] = val;
    q->head = next_index(q->head);
    return true;
}

// Dequeue
bool dequeue(CircularQueue* q, int* val) {
    if (isEmpty(q)) {
        return false; // Queue empty
    }
    *val = q->data[q->tail];
    q->tail = next_index(q->tail);
    return true;
}
int main() {
    CircularQueue q;
    initQueue(&q);

    // Enqueue some values
    for (int i = 1; i <= 7; i++) {
        enqueue(&q, i);
    }

    // Try enqueueing to a full queue
    if (!enqueue(&q, 99)) {
        printf("Queue Full!\n");
    }

    // Dequeue all values
    int val;
    while (dequeue(&q, &val)) {
        printf("%d ", val);
    }
    printf("\n");

    return 0;
}
