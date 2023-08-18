#include<iostream>

using namespace std;

void rotateRightByOne(int *arr, int n)
{
    int temp = arr[n-1];

    for(int i=n-1;i>0;i--)
    {
        arr[i] = arr[i-1];
    }

    arr[0] = temp;
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

    rotateRightByOne(arr,n);

    cout<<"The output array is : ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}