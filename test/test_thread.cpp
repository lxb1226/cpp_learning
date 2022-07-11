#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

using namespace std;

constexpr int N = 10;

mutex mtx;
condition_variable fullBuffers;
condition_variable emptyBuffers;

void consumer(){
    while(true){
        
    }
}