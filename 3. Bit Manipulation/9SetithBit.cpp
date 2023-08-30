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

    int ans = (n|mask);
}