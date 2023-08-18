#include<iostream>
#include<climits>

using namespace std;

int secondSmallest(int *arr, int n)
{
    if(n<2)
    {
        return -1;
    }

    int smallest = INT_MAX;
    int smaller = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<smallest)
        {
            smaller=smallest;
            smallest=arr[i];
        }

        else if(arr[i]<smaller && arr[i]!=smallest)
        {
            smaller=arr[i];
        }
    }

    return smaller;
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

    int ans = secondSmallest(arr,n);

    cout<<"Second smallest element in the array is : "<<ans;
}