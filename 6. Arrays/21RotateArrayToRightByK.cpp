#include<iostream>

using namespace std;

void reverse(int *arr, int start, int end)
{
    int i = start;
    int j = end;

    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateRight(int *arr, int n, int k)
{
    if(k>=n && n!=0)
    {
        k = k%n;
    }

    else if(n == 0)
    {
        return;
    }

    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-1);
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

    int k;

    cout<<"Enter the number of rotations : ";
    cin>>k;

    rotateRight(arr,n,k);

    cout<<"The output array is : ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}