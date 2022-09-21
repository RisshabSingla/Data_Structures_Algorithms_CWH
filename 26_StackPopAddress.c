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
        printf("\n");
    }
}

int pop(struct Stack *ptr)
{
    if(!isEmpty)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int d = ptr->arr[ptr->top];
        ptr->top = ptr->top -1;
        return d;  // we will over-write on the element when re-writing
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
    int last = pop(&S);
    printf("%d \n", last);
    transversal(&S);

    return 0;
}
