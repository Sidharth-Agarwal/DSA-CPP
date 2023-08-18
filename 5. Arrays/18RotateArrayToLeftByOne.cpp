#include<iostream>

using namespace std;

void rotateLeftByOne(int *arr, int n)
{
    int temp = arr[0];

    for(int i=0;i<n-1;i++)
    {
        arr[i] = arr[i+1];
    }

    arr[n-1] = temp;
}

int main()
{
    int n;

    cout<<"Enter the size of the array : ";
    cin>>n;

    int *arr = new int[n];

    cout<<"Enter the elements of the array : ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    rotateLeftByOne(arr,n);

    cout<<"The output array is : ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}