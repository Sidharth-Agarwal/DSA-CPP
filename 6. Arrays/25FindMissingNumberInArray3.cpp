#include<iostream>

using namespace std;

int missingNumber(int *arr, int n)
{
    int sum1 = ((n)*(n+1))/2;

    int sum2 = 0;

    for(int i=0;i<n;i++)
    {
        sum2 += arr[i];
    }

    return sum1-sum2;
}

int main()
{
    int n;
    
    cout<<"Enter the size of the array : ";
    cin>>n;

    int *arr = new int[n];

    cout<<"Enter the element of the array : ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int missing = missingNumber(arr,n);

    cout<<"The missing number is : "<<missing;   
}