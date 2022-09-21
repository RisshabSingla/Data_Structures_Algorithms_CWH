#include <iostream>
using namespace std;

class Linked
{
public:
    int data;
    Linked *next;
};

void LinkedTransversal(Linked *ptr)
{
    Linked *p = ptr;
    do
    {
        cout << "The element is " << p->data << endl;
        p = p->next;
    } while (p != ptr);
}

Linked *insertBegin(Linked *head, int d)
{
    Linked *ptr = new Linked();
    Linked *p = new Linked();
    // ptr->data = d;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    p->data = d;
    ptr->next = p;
    p->next = head;
    head = p;
    return head;
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

    (*one).data = 7;
    (*one).next = two;

    (*two).data = 3;
    (*two).next = three;

    (*three).data = 9;
    (*three).next = last;

    (*last).data = 1;
    (*last).next = head;

    LinkedTransversal(head);
    cout << endl;

    int data = 66; // value to be inserted at the beginning
    head = insertBegin(head, data);

    LinkedTransversal(head);

    return 0;
}
