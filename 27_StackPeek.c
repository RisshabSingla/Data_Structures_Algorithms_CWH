#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
        return 1;
    else
        return 0;
}

void transversal(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("The stack is empty");
    }
    else
    {
        for (int i = 0; i <= ptr->top; i++)
        {
            printf("%d , ", ptr->arr[i]);
        }
        printf("\n");
    }
}

int pop(struct Stack *ptr)
{
    if (!isEmpty)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int d = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return d; // we will over-write on the element when re-writing
    }
}

void push(struct Stack *ptr, int d)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = d;
    }
}

int peak(struct Stack *ptr, int index)
{
    int arrayPos = ptr->top - index + 1;
    if (arrayPos < 0)
    {
        printf("Invalid Position\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrayPos];
    }
}

int main()
{

    struct Stack *S = (struct Stack *)malloc(sizeof(struct Stack));
    S->size = 80;
    S->top = -1;
    S->arr = (int *)malloc(S->size * sizeof(int));

    S->arr[(S->top + 1)] = 7;
    S->top++;

    push(S, 8);
    push(S, 6);
    push(S, 2);
    push(S, 4);
    push(S, 9);
    push(S, 31);
    push(S, 56);
    push(S, 98);
    push(S, 91);

    transversal(S);

    int last = pop(S);
    printf("%d \n", last);

    transversal(S);

    for (int i = 1; i <= S->top + 1; i++)
    {
        printf("The element at index %d is %d. \n", i, peak(S, i));
    }

    return 0;
}
