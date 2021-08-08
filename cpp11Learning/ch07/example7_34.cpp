#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

void Stat(vector<int> &v){
    int errors;
    int score;

    auto print = [&]{
        cout << "Errors: " << errors << endl
            << "Score: " << score << endl;
    };

    errors = accumulate(v.begin(), v.end(), 0);
    score = accumulate(v.begin(), v.end(), 100, minus<int>());

    print();

    errors = 0;
    score = 100;

    for_each(v.begin(), v.end(), [&](int i){
        errors += i;
        score += i;
    });

    print();
}

int main(){
    vector<int> v(10);
    generate(v.begin(), v.end(), []{
        return rand() % 10;
    });
    Stat(v);
}