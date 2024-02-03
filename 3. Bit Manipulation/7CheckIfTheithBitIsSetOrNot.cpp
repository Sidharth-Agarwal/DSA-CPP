// Bit Manipulation

#include<iostream>

using namespace std;

int main()
{
    int n;

    cout<<"Enter the number : ";
    cin>>n;

    int i;

    cout<<"Enter the value of i : ";
    cin>>i;

    int mask = 1<<i;

    bool set = (mask & n);

    if(set == 1)
    {
        cout<<"SET";
    }
    else
    {
        cout<<"NOT SET";
    }
}