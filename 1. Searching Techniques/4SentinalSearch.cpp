#include<iostream>

using namespace std;

int sentinalSearch(int *arr, int n, int key)
{
    // Storing the last element of the array
    int last = arr[n-1];

    // Replacing the last element with the key
    arr[n-1] = key;

    int i=0;

    while(arr[i]!=key)
    {
        i++;
    }

    // Putting back the last element
    arr[n-1] = last;

    if((i<n-1) || (arr[n-1]==key))
    {
        return i;
    }
    else
    {
        return -1;
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

    int x;

    cout<<"Enter the element to search : ";
    cin>>x;

    int index = sentinalSearch(arr,n,x);

    if(index == -1)
    {
        cout<<"Element not present in the array.";
    }
    else
    {
        cout<<"Index of the element is : "<<index;
    }
}