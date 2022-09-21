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

void deleteEnd(Linked *head)
{
    Linked *ptr = head->next;
    Linked *ptr2 = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }

    ptr2->next = NULL;
    delete ptr;
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
    (*last).next = NULL;

    LinkedTransversal(head);
    cout << endl;

    deleteEnd(head);

    LinkedTransversal(head);

    return 0;
}
