#include <iostream>

using namespace std;

class MyTest
{
public:
    MyTest(){};
    ~MyTest(){};

    void FirstPrint()
    {
        std::cout << "this is first member fun in Test\n";
    }

private:
    int m_iInternal;
};

class Point
{
public:
    virtual ~Point(){
        
    };
    float x(){
        return 1.0;
    };
    float y(){
        return 2.0;
    };
    virtual float z();
};

template <typename dst_type, typename src_type>
dst_type pointer_cast(src_type src)
{
    return *static_cast<dst_type *>(static_cast<void *>(&src));
}

int main()
{
    MyTest t;
    int iTemp = 3;

    //以下输出错误地址为：1，明显错误
    std::cout << "the addr of Test::testfunc is " << &MyTest::FirstPrint << std::endl;
    //下述语句打印正确
    std::cout << "the addr of local var iTemp is " << &iTemp << std::endl;

    std::cout << "the addr of Point::~Point is " << &Point::~Point << std::endl;

    std::cout << "the addr of Point::x is " << &Point::x << std::endl;

    std::cout << "the addr of Point::z is " << &Point::z << std::endl;

    //这是正确的做法,一定注意格式修饰符为%p，否则64位系统中会出错
    printf("the addr of Test::testfunc is %p\n", &MyTest::FirstPrint);
    printf("the addr of local var iTemp is %p\n", &iTemp);
}
