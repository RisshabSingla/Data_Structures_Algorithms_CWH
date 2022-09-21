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

void insertNode(Linked *prevNode, int d)
{
    Linked *End = new Linked();
    End->data = d;
    End->next = prevNode->next;
    prevNode->next = End;
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

    insertNode(three, 65);

    LinkedTransversal(head);

    return 0;
}
