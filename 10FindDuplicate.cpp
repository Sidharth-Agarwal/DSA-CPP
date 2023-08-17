// Coding Ninjas

#include<iostream>
#include<climits>

using namespace std;

int findDuplicate(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        int j;

        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(arr[i]==arr[j])
                {
                    return arr[i];
                }
            }
        }
    }
    
    return INT_MIN;
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

    int duplicate = findDuplicate(arr,n);

    if(duplicate == INT_MIN)
    {
        cout<<"Array doesn't consist a duplicate element";
    }
    else
    {
        cout<<"Duplicate element of the array is : "<<duplicate;
    }
}