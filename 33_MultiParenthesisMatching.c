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
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *ptr, char ch)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = ch;
    }
}

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char ch = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return ch;
    }
}

int sameParenthesis(char a, char b)
{
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisBalanced(char *ptr)
{
    struct Stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == '(' || ptr[i] == '[' || ptr[i] == '{')
        {
            push(sp, ptr[i]);
        }
        else if (ptr[i] == ')' || ptr[i] == ']' || ptr[i] == '}')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            char popped_char = pop(sp);
            if (!sameParenthesis(popped_char, ptr[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // char *exp = "[[4-6]((8){(9-8])})";
    char *exp = "((8){(9-8)})";

    if (parenthesisBalanced(exp))
    {
        printf("The parenthesis is matching");
    }
    else
    {
        printf("The parenthesis is not matching");
    }

    return 0;
}
