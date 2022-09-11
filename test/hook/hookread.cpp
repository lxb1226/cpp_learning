// hookread.cpp
#include <dlfcn.h>
#include <unistd.h>
 
#include <iostream>
 
typedef ssize_t (*read_pfn_t)(int fildes, void *buf, size_t nbyte);
 
static read_pfn_t g_sys_read_func = (read_pfn_t)dlsym(RTLD_NEXT,"read");
 
ssize_t read( int fd, void *buf, size_t nbyte ){
    std::cout << "进入 hook read\n";
    return g_sys_read_func(fd, buf, nbyte);
}
 
void co_enable_hook_sys(){
    std::cout << "可 hook\n";
}
 
