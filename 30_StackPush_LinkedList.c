#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* push(struct Node *ptr, int data)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = data;
    new->next = ptr;

    ptr= new;
    return ptr;
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

    top = push(top, 8);
    transversal(top);
    printf("\n");


    top = push(top, 18);
    transversal(top);

    return 0;
}
