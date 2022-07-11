#include <stdio.h>
#include <stdlib.h>

void init_array()
{
    int arr[10];
    printf("%p\n", arr);
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = i;
    }
}

void print_array()
{
    int arr[10];
    printf("%p\n", arr);
    for (int i = 0; i < 10; ++i)
    {
        printf("%ld\t", arr[i]);
    }
}

int main()
{
    init_array();
    print_array();
}