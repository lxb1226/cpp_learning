#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{

    std::vector<std::thread> test_threads;
    for (int i = 0; i < 9; i++)
    {
        test_threads.push_back(std::thread([]
                                           {
    while(1){
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } }));
    }
    test_threads.push_back(std::thread([]
                                       {
      while(1){
        std::cout << "cpu" <<std::endl;
      } }));

    for (auto &x : test_threads)
    {
        x.join();
    }

    return 0;
}