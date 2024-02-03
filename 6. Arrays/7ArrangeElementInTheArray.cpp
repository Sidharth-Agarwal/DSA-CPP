// Coding Ninjas

#include<iostream>

using namespace std;

void arrange(int arr[], int n)
{
    int j=0;

    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            arr[j]=i;
            j++;
        }
    }

    for(int i=n;i>0;i--)
    {
        if(i%2==0)
        {
            arr[j]=i;
            j++;
        }
    }
}

int main()
{
    int n;

    cout<<"Enter the size of the array : ";
    cin>>n;

    int arr[n];

    cout<<"Enter the elements of the array : ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    arrange(arr,n);

    cout<<"The array is : ";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}