#include <iostream>
using namespace std;

class Linked
{
public:
    int data;
    Linked *next;
    Linked *prev;
};

void LinkedTransversal(Linked *ptr)
{
    while (ptr != NULL)
    {
        cout << "The element is " << ptr->data << endl;
        ptr = ptr->next;
    }
}

void LinkedTransversalRev(Linked *ptr)
{
    while (ptr != NULL)
    {
        cout << "The element is " << ptr->data << endl;
        ptr = ptr->prev;
    }
}

int main()
{
    Linked *head = new Linked();
    Linked *one = new Linked();
    Linked *two = new Linked();
    Linked *three = new Linked();
    Linked *last = new Linked();

    (*head).data = 5;
    head->next = one;
    head->prev = NULL;

    (*one).data = 7;
    (*one).next = two;
    one->prev = head;

    (*two).data = 3;
    (*two).next = three;
    two->prev = one;

    (*three).data = 9;
    (*three).next = last;
    three->prev = two;

    (*last).data = 1;
    (*last).next = NULL;
    last->prev = three;

    LinkedTransversal(head);

    cout << endl;
    LinkedTransversalRev(last);

    return 0;
}
