#include "1.h"
#include <iostream>


void set(int value){
    std::cout << "set: " << g_a << std::endl;
    g_a = value;
    std::cout << "set: " << g_a << std::endl;
}