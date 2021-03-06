// lock_guard构造函数

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print_thread_id(int id){
    mtx.lock();
    std::lock_guard<std::mutex> lck(mtx, std::adopt_lock);
    std::cout << "thread #" << id << "\n";
}

int main(){
    std::thread threads[10];
    for(int i = 0; i < 10; i++)
        threads[i] = std::thread(print_thread_id, i+1);
    for(auto & th : threads) th.join();

    return 0;
}