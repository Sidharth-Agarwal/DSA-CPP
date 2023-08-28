#include<iostream>

using namespace std;

void moveZeroesToEnd(int *arr, int n)
{
    int j=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j++;
        }
    }
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

    moveZeroesToEnd(arr,n);

    cout<<"The output array is : ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}