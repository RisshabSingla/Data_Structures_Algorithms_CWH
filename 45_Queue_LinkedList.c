
#include <stdio.h>
#include <stdlib.h>

struct Node *front = NULL;
struct Node *rear = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void transversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        int val = front->data;
        n = front;
        front = front->next;
        free(n);
        return val;
    }
}

int main()
{
    transversal(front);

    enqueue(56);
    enqueue(76);
    enqueue(98);
    enqueue(23);

    transversal(front);

    printf("The dequeued element is %d\n", dequeue());
    printf("The dequeued element is %d\n", dequeue());
    printf("The dequeued element is %d\n", dequeue());
    printf("The dequeued element is %d\n", dequeue());
    printf("The dequeued element is %d\n", dequeue());

    return 0;
}
