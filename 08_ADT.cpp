#include <iostream>
using namespace std;

class MyArray
{
public:
    int total_size; // total memory of the array
    int used_size;  // used memory of the array
    int *ptr;       // pointer of the first element

    void createArray(int, int);
    void show();
    void setVal();
};

void MyArray ::createArray(int tSize, int uSize)
{
    total_size = tSize;
    used_size = uSize;
    ptr = new int[tSize];

}

void MyArray::show()
{
    for (int i = 0; i < used_size; i++)
    {
        printf("%d\n", (ptr)[i]);
    }
}
void MyArray::setVal()
{
    int n;
    for (int i = 0; i < used_size; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &n);
        ptr[i] = n;
    }
}

int main()
{
    MyArray arr;
    arr.createArray(10,2);
    // cout<<arr.total_size <<endl;
    // cout<<arr.used_size <<endl;

    cout<<"We are running setVal now: \n";
    arr.setVal();
    cout<<"We are running show now: \n";
    arr.show();

    return 0;
}
