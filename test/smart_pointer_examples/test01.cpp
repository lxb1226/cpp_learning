#include<iostream>
#include<thread>
#include<vector>

using namespace std;

shared_ptr<int> pInt(new int(1));

void threadFunc(){
    int cnt = 100;
    while(cnt > 0){
        *pInt = *pInt + 1;
        cnt--;
    }
}

int main(){
    vector<thread> threads;

    for(int i = 0; i < 1000; ++i){
        threads.push_back(thread(threadFunc));
    }
    
    for(int i = 0; i < 1000; ++i){
        threads[i].join();
    }

    cout << *pInt << endl;
    return 0;

}