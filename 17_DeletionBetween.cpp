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

void deleteBetween(Linked *head, int index)
{
    Linked *ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    Linked *ptr2 = ptr->next;
    ptr->next = ptr2->next;
    delete ptr2;
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

    deleteBetween(head, 2);

    LinkedTransversal(head);

    return 0;
}
