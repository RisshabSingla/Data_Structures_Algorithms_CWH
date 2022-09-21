#include <stdio.h>
#include <stdlib.h>

struct Circular_Queue
{
    int size;
    int first_index;
    int back_index;
    int *arr;
};

int isFull(struct Circular_Queue *q)
{
    if (((q->back_index+1)%q->size) == (q->first_index))
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Circular_Queue *q)
{
    if (q->back_index == q->first_index)
    {
        return 1;
    }
    return 0;
}

int dequeue(struct Circular_Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow \n");
        return -1;
    }

    q->first_index = ((q->first_index + 1)%q->size);
    int val = q->arr[q->first_index];
    return val;
}

void enqueue(struct Circular_Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->back_index = ((q->back_index + 1)%q->size);
        q->arr[q->back_index] = val;
    }
}

int main()
{
    struct Circular_Queue *q = (struct Circular_Queue *)malloc(sizeof(struct Circular_Queue));
    q->size = 10;
    q->first_index = -1;
    q->back_index = -1;
    q->arr = (int *)malloc(sizeof(int) * q->size);

    dequeue(q);
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue not empty\n");
    }

    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is not full\n");
    }

    enqueue(q, 10);
    enqueue(q, 65);
    enqueue(q, 54);

    printf("The dequeued element is %d\n", dequeue(q));
    printf("The dequeued element is %d\n", dequeue(q));
    printf("The dequeued element is %d\n", dequeue(q));
    printf("The dequeued element is %d\n", dequeue(q));
}
