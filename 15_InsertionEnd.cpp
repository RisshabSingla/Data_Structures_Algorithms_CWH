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
    while (ptr != NULL)
    {
        cout << "The element is " << ptr->data << endl;
        ptr = ptr->next;
    }
}

void insertEnd(Linked *head, int d)
{
    Linked *End = new Linked();
    Linked *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    End->data = d;
    ptr->next = End;
    End->next = NULL;
}

int main()
{
    Linked *head = new Linked();
    Linked *one = new Linked();
    Linked *two = new Linked();
    Linked *three = new Linked();
    Linked *last = new Linked();

    Linked *end = new Linked();

    (*head).data = 5;
    head->next = one;

    (*one).data = 7;
    (*one).next = two;

    (*two).data = 3;
    (*two).next = three;

    (*three).data = 9;
    (*three).next = last;

    (*last).data = 1;
    (*last).next = NULL;

    LinkedTransversal(head);
    cout << endl;

    insertEnd(head, 65);

    LinkedTransversal(head);

    return 0;
}
