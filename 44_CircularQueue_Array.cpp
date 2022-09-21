#include <iostream>
using namespace std;

class Circular_Queue
{
public:
    int size;
    int first_index;
    int back_index;
    int *arr;
};

int isFull(Circular_Queue *q)
{
    if (((q->back_index+1)%q->size) == (q->first_index))
    {
        return 1;
    }
    return 0;
}

int isEmpty(Circular_Queue *q)
{
    if (q->back_index == q->first_index)
    {
        return 1;
    }
    return 0;
}

int dequeue(Circular_Queue *q)
{
    if (isEmpty(q))
    {
        cout << ("Queue Underflow \n");
        return -1;
    }

    q->first_index = ((q->first_index + 1)%q->size);
    int val = q->arr[q->first_index];
    return val;
}

void enqueue(Circular_Queue *q, int val)
{
    if (isFull(q))
    {
        cout << ("Queue overflow\n");
    }
    else
    {
        q->back_index = q->back_index + 1;
        q->arr[q->back_index] = val;
    }
}

int main()
{
    Circular_Queue *q = new Circular_Queue();
    q->size = 10;
    q->first_index = 0;
    q->back_index = 0;
    q->arr = new int[q->size];

    dequeue(q);
    if (isEmpty(q))
    {
        cout << ("Queue is empty\n");
    }
    else
    {
        cout << ("Queue not empty\n");
    }

    if (isFull(q))
    {
        cout << ("Queue is full\n");
    }
    else
    {
        cout << ("Queue is not full\n");
    }

    enqueue(q, 10);
    enqueue(q, 65);
    enqueue(q, 54);

    cout << "The dequeued element is " << dequeue(q) << endl;
    cout << "The dequeued element is " << dequeue(q) << endl;
    cout << "The dequeued element is " << dequeue(q) << endl;
    cout << "The dequeued element is " << dequeue(q) << endl;

    return 0;
}
