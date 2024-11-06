#include <iostream>
using namespace std;
// Template function for selection sort
template <typename T>
void selectionSort(T arr[], int size)
{
    // Traverse through all array elements
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
// Function to print an array
template <typename T>
void printArray(const T arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // Integer array
    int intArr[] = {64, 25, 12, 22, 11};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Original integer array:\n";
    printArray(intArr, intSize);
    selectionSort(intArr, intSize);
    cout << "Sorted integer array:\n";
    printArray(intArr, intSize);
    // Float array
    float floatArr[] = {64.4f, 25.1f, 12.8f, 22.6f, 11.3f};
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);
    cout << "Original float array:\n";
    printArray(floatArr, floatSize);
    selectionSort(floatArr, floatSize);
    cout << "Sorted float array:\n";
    printArray(floatArr, floatSize);
    return 0;
}