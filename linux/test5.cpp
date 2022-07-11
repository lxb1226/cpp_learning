#include <stdio.h>
#include <stdint.h>

class C {
public:
    uint64_t a = 15;
    virtual void vfunc() { };
};

C func() {
    C c;
    return c;
}

int main() {
    C c = func();
}
