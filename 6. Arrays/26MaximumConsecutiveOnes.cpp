#include<iostream>

using namespace std;

int maximumConsecutiveOnes(int *arr, int n)
{
    int ones = 0;
    int maxCount = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i] == 1)
        {
            ones++;
        }
        else
        {
            ones = 0;
        }

        maxCount = max(ones,maxCount);
    }

    return maxCount;
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

    int maxOnes = maximumConsecutiveOnes(arr,n);

    cout<<"Maximum consecutive ones in the array are : "<<maxOnes;
}