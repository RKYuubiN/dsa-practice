#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *base_address;
};

void createArray(struct myArray *arr, int totalSize, int usedSize);
int max(struct myArray arr);
void show(struct myArray *arr);
// int get(struct myArray arr);
void set(struct myArray *arr);

int main()
{
    struct myArray arr1;
    createArray(&arr1, 100, 2);
    printf("Settin values for array now\n");
    set(&arr1);
    printf("Printing values for array now\n");
    show(&arr1);
    return 0;
}

void createArray(struct myArray *arr, int totalSize, int usedSize)
{
    arr->total_size = totalSize;
    arr->used_size = usedSize;
    arr->base_address = (int *)malloc(totalSize * sizeof(int));
}

void show(struct myArray *arr)
{
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d\n", (arr->base_address)[i]);
    }
}

void set(struct myArray *arr)
{
    int n;
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Enter your value %d ", i);
        scanf("%d", &n);
        (arr->base_address)[i] = n;
    }
}

int max(struct myArray arr)
{
    return arr.total_size;
}
