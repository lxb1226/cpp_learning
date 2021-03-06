#include <iostream>
#include <future>
#include <chrono>
#include <thread>

int countdown(int from, int to){
    for(int i = from; i != to; --i){
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Finished!" << std::endl;
    return from - to;
}

int main(){
    std::packaged_task<int(int,int)> task(countdown); 
    std::future<int> ret = task.get_future();

    std::thread th(std::move(task), 10, 0);

    int value = ret.get();

    std::cout << "The countdown lasted for " << value << " seconds." << std::endl;

    th.join();

    return 0;
}