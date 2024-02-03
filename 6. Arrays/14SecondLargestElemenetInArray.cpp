#include<iostream>
#include<climits>

using namespace std;

int secondLargest(int *arr, int n)
{
    if(n<2)
    {
        return -1;
    }

    int largest = INT_MIN;
    int larger = INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest)
        {
            larger=largest;
            largest=arr[i];
        }

        else if(arr[i]>larger && arr[i]!=largest)
        {
            larger=arr[i];
        }
    }

    return larger;
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

    int ans = secondLargest(arr,n);

    cout<<"Second largest element in the array is : "<<ans;
}