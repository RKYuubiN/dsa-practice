#include <stdio.h>

// Traversal
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d]=>%d\n", i, arr[i]);
    }
}
// Insertion
int indexedInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

// Deletion
void indexedDeletion(int arr[],int index,int size)
{
    // Using size-1 also works for it is not good since it is one extra loop. Using size-1 since you are deleting 1 element. size = 5; after deleting size = 4. so loop runs till 3 i.e. < size-1
    for(int i=index;i<size-1;i++){
        arr[i] = arr[i+1];
    }
}

int main()
{
    int returnValue;
    int arr[100] = {54, 14, 34, 12, 51};
    int size = 5, element = 45, index = 3;
    printf("Displaying array for the first time\n");
    displayArray(arr, size);
    returnValue = indexedInsertion(arr, size, element, 100, index);
    // if(returnValue == -1){
    //     return -1;
    // }
    size+=1;
    printf("Displaying array after insertion\n");
    displayArray(arr,size);
    indexedDeletion(arr,3,size);
    size-=1;
    printf("Displaying array after deletion\n");
    displayArray(arr,size);
}