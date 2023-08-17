// Coding Ninjas

#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

void printIntersection(int *arr1, int *arr2, int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr1[i]==arr2[j])
            {
                cout<<arr1[i]<<" ";
                arr2[j]=INT_MIN;
                break;
            }
        }
    }
}

int main()
{
    int n;

    cout<<"Enter the size of the first array : ";
    cin>>n;

    int *arr1 = new int[n];

    cout<<"Enter the elements of the first array : ";

    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }

    int m;

    cout<<"Enter the size of the second array : ";
    cin>>m;

    int *arr2 = new int[m];

    cout<<"Enter the elements of the second array : ";

    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    printIntersection(arr1,arr2,n,m);
}