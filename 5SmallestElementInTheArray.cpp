// Coding Ninjas

#include<iostream>
#include<climits>

using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};

    int size = sizeof(arr) / sizeof(arr[0]);

    int smallest = INT_MAX;

    for (int i = 0; i < size;i++)
    {
        if(arr[i]<smallest)
        {
            smallest = arr[i];
        }
    }

    cout << "Smallest element in the array is : " << smallest;
}