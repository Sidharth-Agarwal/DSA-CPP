// Bit Manipulation

#include<iostream>

using namespace std;

int main()
{
    cout<<"Enter the first number : ";
    
    int a;
    cin>>a;

    cout<<"Enter the second number : ";

    int b;
    cin>>b;

    cout<<"Initially the numbers are : "<<a<<" "<<b<<endl;

    a = a^b;
    b = a^b;
    a = a^b;

    cout<<"After swapping the numbers are : "<<a<<" "<<b;
}