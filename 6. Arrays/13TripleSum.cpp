// Coding Ninjas

#include<iostream>

using namespace std;

int tripleSum(int *arr, int n, int x)
{
    int count = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k]==x)
                {
                    count++;
                }
            }
        }
    }
    
    return count;
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
    
    cout<<"Enter the sum element : ";
    cin>>x;

    int total = tripleSum(arr,n,x);

    cout<<"The number of triple sums in the array are : "<<total;
}