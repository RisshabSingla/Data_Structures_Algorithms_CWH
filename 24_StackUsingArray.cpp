#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int size;
    int *arr;
};


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

int main()
{
    Stack *st = new Stack();
    st->top = -1;
    st->size = 10;
    st->arr = new int[st->size];

    st->arr[st->top+1] = 8;
    st->top++;

    st->arr[st->top+1] = 12;
    st->top++;
    st->arr[st->top+1] = 9;
    st->top++;
    st->arr[st->top+1] = 7;
    st->top++;
    st->arr[st->top+1] = 3;
    st->top++;

    transversal(st);
    
    return 0;
}
