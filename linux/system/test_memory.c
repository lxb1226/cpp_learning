#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main() {
    int ret;
    char* addr[4];
    printf("使用cat /proc/%d/maps查看内存分配\n",getpid());
    size_t s = 1024 * 1024 * 1024;
    int i = 0;
    for(i = 0; i < 4; ++i) {
        printf("alloc size = %d\n", s);
        addr[i] = (char*) malloc(s);
        printf("主线程调用malloc后，申请1gb大小得内存，此内存起始地址：0X%x\n", addr[i]);
    }
    getchar();
    return 0;
}