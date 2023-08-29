#include<iostream>

using namespace std;

int main()
{
    int n;

    cout<<"Enter the number : ";
    cin>>n;

    if(n%4 == 0)
    {
        cout<<"Output is : "<<n;
    }

    else if(n%4 == 1)
    {
        cout<<"Output is : "<<1;
    }

    else if(n%4 == 2)
    {
        cout<<"Output is : "<<n+1;
    }

    else
    {
        cout<<"Output is : "<<0;
    }
}