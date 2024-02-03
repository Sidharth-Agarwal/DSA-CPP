// Bit manipulation

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

    int mask = ~(1<<i);
    n = (n & mask);

    cout<<"The output is : "<<n;
}