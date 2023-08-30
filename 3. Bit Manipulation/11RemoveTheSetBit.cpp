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

    int ans = (n&(n-1));

    cout<<"The output is : "<<ans;
}