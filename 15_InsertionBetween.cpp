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

void insertBetween(Linked *head, int d, int index)
{
    Linked *Between = new Linked();
    Linked *ptr = head;
    int i = 0;

    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    Between->data = d;
    Between->next = ptr->next;
    ptr->next = Between;
    // return head;
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
    int data = 66;
    int index = 3;

    insertBetween(head, data, index);

    LinkedTransversal(head);

    return 0;
}
