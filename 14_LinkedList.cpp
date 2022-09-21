#include <iostream>
using namespace std;

class Linked
{
public:
    int data;
    Linked *next;
};

void LinkedTransversal( Linked* ptr)
{
    while(ptr != NULL)
    {
        cout<<"The element is "<<ptr->data<<endl;
        ptr = ptr->next;
    }
}

int main()
{
    Linked* head;
    Linked* one;
    Linked* two;
    Linked* three;
    Linked* last;

    head = new Linked();
    one = new Linked();
    two = new Linked();
    three = new Linked();
    last = new Linked();

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


    return 0;
}
