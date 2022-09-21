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
int parenthesisMatch(string);
int isEmpty(Stack *);
void transversal(Stack *);
int isFull(Stack *);
int pop(Stack *);
void push(Stack *, int);

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

int parenthesisMatch(string s)
{
    Stack *st = new Stack();
    st->top = -1;
    st->size = 10;
    st->arr = new int[st->size];

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            push(st, s[i]);
        else if (s[i] == ')')
        {
            if (isEmpty(st))
                return 0;
            else
                pop(st);
        }
    }
    if (isEmpty(st))
        return 1;
    else
        return 0;
}

int main()
{
    string exp = "((8)(*--$$9))";

    if (parenthesisMatch(exp))
    {
        cout << "The parenthesis match" << endl;
    }
    else
    {
        cout << "The parenthesis don't match" << endl;
    }
    return 0;
}
