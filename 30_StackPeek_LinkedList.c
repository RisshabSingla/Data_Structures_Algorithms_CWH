#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int peek(struct Node *ptr, int pos)
{
    struct Node* p = ptr;
    int i = 1;
    for (i = 1; i < pos && p != NULL; i++)
    {
        p = p->next;
    }
    if (p == NULL)
        return -1;
    else
        return p->data;
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

    int data = peek(top, 3);
    printf("The element at pos 3 is %d\n",data);

    return 0;
}
