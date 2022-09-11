#include <stdio.h>

int main(){
    int x = 10, y = 10, i;
    for(i = 0; x > 8; y = ++i){
        printf("%d%d", x--, y);
    }
}

// #define oxcoder(s, n) #s #n

// int main(){
//     printf(oxcoder(hello, world));
//     return 0;
// }


// int main(){
//     #define max 45
//     max = 32;
//     printf("%d", max);
//     return 0;
// }