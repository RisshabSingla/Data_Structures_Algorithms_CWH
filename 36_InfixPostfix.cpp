#include <iostream>
#include <string>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    int *arr;
};

int stackTop(Stack *);
int isEmpty(Stack *);
void transversal(Stack *);
int isFull(Stack *);
int pop(Stack *);
void push(Stack *, int);
int precedence(char);
int isOperator(char);

int stackTop(Stack *ptr)
{
    return ptr->arr[ptr->top];
}

void push(Stack *ptr, int a)
{
    if (isFull(ptr))
    {
        cout << "Stack full, Insertion Failed" << endl;
    }
    else
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = a;
    }
}

int pop(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "The stack is empty" << endl;
        return -1;
    }
    else
    {
        int temp = ptr->top;
        ptr->top = ptr->top - 1;
        return ptr->arr[temp];
    }
}

int isFull(Stack *ptr)
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

int isEmpty(Stack *ptr)
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

void transversal(Stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        for (int i = 0; i <= ptr->top; i++)
        {
            cout << ptr->arr[i] << " ";
        }
        cout << endl;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

string infixToPostfix(string infix)
{
    Stack *st = new Stack();
    st->top = -1;
    st->size = 10;
    st->arr = new int[st->size];

    string postfix = "";
    int index = 0;
    while (index < infix.length())
    {
        char c = infix[index];
        if (!isOperator(c))
        {
            postfix += c;
            index++;
        }
        else
        {
            if (precedence(infix[index]) > precedence(stackTop(st)))
            {
                push(st, infix[index]);
                index++;
            }
            else
            {
                postfix += pop(st);
            }
        }
    }
    while (!isEmpty(st))
    {
        char a = pop(st);
        postfix += a;
    }
    return postfix;
}

int main()
{
    string exp = "x-y/z-k*d";
    cout << "The postfix is " << infixToPostfix(exp);

    return 0;
}
