// 清单4.6 使用std::future获取异步任务的返回值

#include <future>
#include <iostream>

int find_the_answer_to_ltuae();
void do_other_stuff();

int main(){
    std::future<int> the_answer = std::async(find_the_answer_to_ltuae);
    do_other_stuff();

    std::cout << "The answer is " << the_answer.get() << std::endl;

}