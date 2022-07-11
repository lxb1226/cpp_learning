#include <stdio.h>
#include <stdlib.h>

void bar(){
    printf("This is bar!\n");
}

void foo(){
    printf("This is foo!\n");
    long arr[2] = {1, 2, 3};
    arr[5] = bar;
}


int main(){
    // long foo = 10;
    // long arr[2] = {1, 2};
    // arr[-1] = 20;
    // printf("foo is %ld", foo);

    foo();
    return 0;
}