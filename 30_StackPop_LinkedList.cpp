#include <iostream>
using namespace std;

class Stack
{
public:
    int data;
    Stack *next;
};

int isFull(Stack *);
int isEmpty(Stack *);
void transversal(Stack *);
Stack* pop(Stack *);

int isFull(Stack *ptr)
{
    Stack *n = new Stack();
    if (n == NULL)
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
    if (ptr == NULL)
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
        while (ptr!= NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

Stack* pop(Stack* ptr)
{
    Stack* n = new Stack();
    n = ptr;
    ptr = ptr->next;
    delete(n);
    return ptr;
}

int main()
{
    Stack *head = new Stack();
    Stack *one = new Stack();
    Stack *two = new Stack();
    Stack *three = new Stack();
    Stack *last = new Stack();

    head->next = one;
    head->data = 9;
    one->next = two;
    one->data = 3;
    two->next = three;
    two->data = 6;
    three->next = last;
    three->data = 5;
    last->next = NULL;
    last->data = 0;

    transversal(head);
    head = pop(head);
    // cout<<"The popped element is "<<a<<endl;
    transversal(head);

    return 0;
}
