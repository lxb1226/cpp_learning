#include <thread>
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

// void print(){
//     int i = 0;
//     cout << "hello world" << endl;
// }

// void print1(){
//     int i = 0;
//     while(1){
//         cout << i << endl;
//         i++;
//     }
// }

void *process(void *data){
    while(1){
        printf("xxx------>I'm is Son thread[%d]...\n", gettid());
        sleep(1);
    }
}

int main(){
    // thread t1(print);
    // thread t2(print1);
    
    // // t1.join();
    // sleep(3);
    // t2.detach();
    // exit(1);
    // pthread_exit(nullptr);
    // cout << "hello world!" << endl;

    pthread_t pid;
    printf("xxx------------>%s(), line = %d, thread[%d]\n", __FUNCTION__, __LINE__, gettid());
    pthread_create(&pid, nullptr, process, nullptr);

    
    pthread_detach(pid);
    pthread_exit(nullptr);
    sleep(3);
    return 0;
}