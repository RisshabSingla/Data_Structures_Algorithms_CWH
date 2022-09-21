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
        for(int i = 0; i<=ptr->top; i++ )
        {
            printf("%d , ", ptr->arr[i]);
        }
    }
}

int main()
{
    // struct Stack p;
    struct Stack S;
    S.size = 80;
    S.top = -1;
    S.arr = (int *)malloc(S.size * sizeof(int));

    // Check if stack is empty
    if (isEmpty(&S))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

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

    if (isEmpty(&S))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

    if (isFull(&S))
    {
        printf("The stack is full\n");
    }
    else
    {
        printf("The stack is not full\n");
    }

    transversal(&S);

    return 0;
}
