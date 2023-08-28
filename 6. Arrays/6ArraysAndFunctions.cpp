#include<iostream>

using namespace std;

void printArray(int arr[], int size)
{
    cout << "The elements of the array are : ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60};

    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
}