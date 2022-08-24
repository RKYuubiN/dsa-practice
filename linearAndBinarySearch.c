#include <stdio.h>

int linearSearch(int arr[], int size, int element);
int binarySearch(int arr[], int size, int element);
int main()
{
    int myArray[] = {43, 66, 12, 90, 66, 78, 34, 44, 35, 23, 14, 77, 66, 88, 99, 23, 14, 54, 23, 67, 59, 23, 14, 56, 23, 45, 7, 73, 24, 44, 32, 11};
    int myArray2[] = {3,7,9,12,16,20,28,34,41,56,66,78,87,89,91};
    int isFoundLinear, isFoundBinary;
    int size = sizeof(myArray) / sizeof(int);
    isFoundLinear = linearSearch(myArray, size, 11);
    isFoundBinary = binarySearch(myArray2, size,89);
    printf("Looped for %d\n", isFoundLinear);
    printf("Looped for %d\n", isFoundBinary);
}

int linearSearch(int arr[], int size, int element)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            printf("Element found in linear\n");
            return count;
        }
        count++;
    }
    return count;
}

int binarySearch(int arr[], int size, int element)
{
    int low = 0, mid, high = size-1;
    int count = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
        {
            printf("Element found in binary\n");
            return count;
        }

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        count++;
    }
    return count;
}