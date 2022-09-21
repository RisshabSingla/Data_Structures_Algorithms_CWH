#include <iostream>
using namespace std;

class Queue
{
public:
    int data;
    Queue *next;
};

Queue *front = NULL;
Queue *rear = NULL;

void transversal(Queue *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is " << ptr->data;
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    Queue *n = new Queue();
    if (n == NULL)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    Queue *n = new Queue();
    int val = front->data;
    n = front;
    front = front->next;
    delete (n);
    return val;
}

int main()
{
    enqueue(54);
    cout<<"The dequeued element is "<<dequeue()<<endl;
    cout<<"The dequeued element is "<<dequeue()<<endl;

    return 0;
}
