#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int stackBottom(struct Node *ptr)
{
    struct Node *p = ptr;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p->data;
}

int stackTop(struct Node *ptr)
{
    return ptr->data;
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

    top->next = two;
    two->next = three;
    three->next = last;
    last->next = NULL;

    top->data = 3;
    two->data = 9;
    three->data = 12;
    last->data = 6;

    transversal(top);
    printf("\n");

    printf("The bottom of the stack is %d\n", stackBottom(top));
    printf("The top of the stack is %d\n", stackTop(top));

    return 0;
}
