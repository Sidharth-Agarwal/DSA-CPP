// Coding Ninjas

#include<iostream>
#include<climits>

using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};

    int size = sizeof(arr) / sizeof(arr[0]);

    int largest = INT_MIN;

    for (int i = 0; i < size;i++)
    {
        if(arr[i]>largest)
        {
            largest = arr[i];
        }
    }

    cout << "Largest element in the array is : " << largest;
}