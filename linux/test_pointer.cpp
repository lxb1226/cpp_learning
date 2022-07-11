
int main(){
    // int i = 5;
    // int &ri = i;
    // ri = 8;

    int i = 5;
    int* const pi = &i;
    *pi = 8;
}