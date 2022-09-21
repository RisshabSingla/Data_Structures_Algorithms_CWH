#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
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

void push(struct Stack *ptr, char ch)
{
    if (isFull(ptr))
        printf("Stack Overflow\n");
    else
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = ch;
    }
}

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
        printf("Stack Underflow");
    else
    {
        char ch = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return ch;
    }
}

int parenthesisMatch(char *ptr)
{
    struct Stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == '(')
            push(sp, ptr[i]);
        else if (ptr[i] == ')')
        {
            if (isEmpty(sp))
                return 0;
            pop(sp);
        }
    }

    if (isEmpty(sp))
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "((8)(*--$$9))";

    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }

    return 0;
}
