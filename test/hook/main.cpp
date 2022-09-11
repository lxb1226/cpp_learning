// main.cpp
#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "hookread.h"
#include <unistd.h>

using namespace std;

int main(){
    co_enable_hook_sys();
    int fd = socket(PF_INET, SOCK_STREAM, 0);
    char buffer[10000];
    
    int res = read(fd, buffer ,10000);
    return 0;
}
