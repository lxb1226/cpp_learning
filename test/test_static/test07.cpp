#include <iostream>
#include "1.h"

int main(){
    std::cout << g_a << std::endl;
    set(1);
    std::cout << g_a << std::endl;
    g_a += 2;
    std::cout << g_a << std::endl;
    return 0;
    
}