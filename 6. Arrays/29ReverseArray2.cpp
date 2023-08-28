// Recursive approach

#include<iostream>

using namespace std;

void reverse(int *arr, int start, int end)
{
    if(start>=end)
    {
        return;
    }

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverse(arr,start+1,end-1);
}

void reverseArray(int *arr, int n)
{
    int start = 0;
    int end = n-1;

    reverse(arr,start,end);
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

    reverseArray(arr,n);

    cout<<"The reversed array is : ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}