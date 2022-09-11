#include <iostream>
#include <vector>

using namespace std;

void removeZero(vector<int>& arr){
    int n = arr.size();
    int idx = 0;
    int i = 0;
    while(i < n){
        if(arr[i] == 0){
            // cout <<"i : " << i << endl;
            for(int j = n - 2; j >= i + 1; j--){
                // cout << arr[j] << endl;
                arr[j] = arr[j - 1];
            }
            if(i + 1 < n)
                arr[i + 1] = 0;
            i++;
        }
        i++;
    }

}

void printArr(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int a = 1, b = 1;
    // (a + 2) = b + 1;
    (a = 2) = b + 1;
    vector<int> arr{1, 0, 2, 3, 0, 4, 5, 0};
    vector<int> arr2{1, 2, 3};
    removeZero(arr);
    printArr(arr);
    removeZero(arr2);
    printArr(arr2);

    return 0;
}