#include <stdio.h>
#include <stdlib.h>


void fun1(){
    int b = 1;
    static int a;
    printf("%d\n", a);
    a++;
}


int main(){
    fun1();
    fun1();
}