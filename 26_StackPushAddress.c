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

int main()
{
    struct Stack S;
    S.size = 80;
    S.top = -1;
    S.arr = (int *)malloc(S.size * sizeof(int));

    S.arr[(S.top + 1)] = 7;
    S.top++;

    S.arr[(S.top + 1)] = 9;
    S.top++;

    S.arr[(S.top + 1)] = 14;
    S.top++;

    S.arr[(S.top + 1)] = 11;
    S.top++;

    S.arr[(S.top + 1)] = 8;
    S.top++;

    transversal(&S);
    push(&S, 56);
    transversal(&S);

    return 0;
}
