#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <condition_variable>

using namespace std;

constexpr int N = 10;

mutex mtx;
condition_variable cv;
int ready = 0;

// 使用一个条件变量和一个int变量控制条件变量wait的等待时机
void printA(){
    std::unique_lock<std::mutex> lk(mtx);
    int cnt = 0;
    while(cnt < 10){
        while(ready != 0)
            cv.wait(lk);
        std::cout << std::this_thread::get_id() << " : " << "A" << std::endl;
        ready = 1;
        cnt++;
        cv.notify_all();
    }
}

void printB(){
    std::unique_lock<std::mutex> lk(mtx);
    int cnt = 0;
    while(cnt < 10){
        while(ready != 1)
            cv.wait(lk);
        std::cout << std::this_thread::get_id() << " : " << "B" << std::endl;
        ready = 2;
        cnt++;
        cv.notify_all();
    }
}

void printC(){
    std::unique_lock<std::mutex> lk(mtx);
    int cnt = 0;
    while(cnt < 10){
        while(ready != 2)
            cv.wait(lk);
        std::cout << std::this_thread::get_id() << " : " << "C" << std::endl;
        ready = 0;
        cnt++;
        cv.notify_all();
    }
}

void print(char ch){
    
    int cnt = 0;
    int n = ch - 'A';
    while(cnt < 10){
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, [n]{return n == ready;});
        cout << ch << endl;
        ready = (ready + 1) % 3;
        cnt++;
        lk.unlock();
        cv.notify_all();
    }
}


int main(){
    // std::thread t1(printA);
    // std::thread t2(printB);
    // std::thread t3(printC);

    // t1.join();
    // t2.join();
    // t3.join();
    vector<std::thread> threads;
    threads.push_back(thread(print, 'A'));
    threads.push_back(thread(print, 'B'));
    threads.push_back(thread(print, 'C'));

    for(int i = 0; i < 3; ++i){
        threads[i].join();
    }

    return 0;
}

