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

Linked* insertBegin(Linked *head, int d)
{
    Linked* Begin = new Linked();
    Begin->data= d;
    Begin->next= head;
    return Begin;
}

int main()
{
    Linked *head= new Linked();
    Linked *one= new Linked();
    Linked *two= new Linked();
    Linked *three= new Linked();
    Linked *last= new Linked();

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

    int data = 66; // value to be inserted at the beginning
    head = insertBegin(head, data);

    LinkedTransversal(head);
    
    return 0;
}
