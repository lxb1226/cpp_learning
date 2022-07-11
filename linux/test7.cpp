class Base {
public: int x = 0xff;
};

class A : public virtual Base {
public: int a = 0x1;
};

class B : public Base {
public: int b = 0x2;
};

class D : virtual public B {
public:
    int d = 0x4;
};

class E : virtual public Base {
public: int e = 0x5;
};

class F : virtual public E {
public: int f = 0x6;
};

class G : virtual Base {
public: int g = 0x7;
};

class H : public G {
public: int h = 0x8;
};

class C : public A, virtual public D, public F, virtual public H {
public:
    int c = 0x3;
};

int main() {
    C c;
    int x = c.g;
}

