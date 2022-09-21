#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

int isFull(struct Node *ptr)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if(new == NULL)
    return 1;
    else
    return 0;
}

void transversal(struct Node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("The element at pos %d is %d\n", i, ptr->data);
        i++;
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *top = (struct Node *)malloc(sizeof(struct Node));
    struct Node *two = (struct Node *)malloc(sizeof(struct Node));
    struct Node *three = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = (struct Node *)malloc(sizeof(struct Node));

    // top = NULL;

    if (isEmpty(top))
        printf("Stack is empty\n");
    else
        printf("Stack has elements\n");

    top->next = two;
    two->next = three;
    three->next = last;
    last->next = NULL;

    top->data = 3;
    two->data = 9;
    three->data = 12;
    last->data = 6;

    transversal(top);

    if (isFull(top))
        printf("Stack is full\n");
    else
        printf("Stack is not full\n");

    return 0;
}
