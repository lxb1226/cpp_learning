#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class SmartPointer{
private:
    T* _ptr;
    size_t* _count; // 指针

public:
    SmartPointer(T* ptr = nullptr): _ptr(ptr){
        if(_ptr){
            _count = new size_t(1);
        }else{
            _count = new size_t(0);
        }
    }

    // 拷贝构造函数
    SmartPointer(const SmartPointer& ptr){
        
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
    }

    // 拷贝赋值函数
    SmartPointer& operator=(const SmartPointer& ptr){
        
        if(this->_ptr == ptr._ptr){
            return *this;
        }

        if(this->_ptr){
            (*this->_count)--;
            if(this->_count == 0){
                delete this->_ptr;
                delete this->_count;
            }
        }

        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        (*this->_count)++;
        return *this;
    }

    T& operator*(){
        assert(this->_ptr == nullptr);
        return *(this->_ptr);
    }

    T* operator->(){
        assert(this->_ptr == nullptr);
        return this->_ptr;
    }

    ~SmartPointer(){
        (*this->_count)--;
        if(*this->_count == 0){
            delete this->_ptr;
            delete this->_count;
        }
    }

    size_t use_count(){
        return *this->_count;
    }
};

template<typename T, typename... Args>
shared_ptr<T> my_make_shared(Args&&... args){
    // 将模板参数的形参类型设置为Args&& 右值引用和将传给T的构造函数的形参使用std::forward可保留我们转发调用该模板函数时实参的所有属性
    // 先调用类型T的构造函数new处一个新内存空间，然后减控制权传给shared_ptr的构造函数
    shared_ptr<T> ret(new T(std::forward(args)...));

    // 返回shared_ptr的一个副本，因为该模板函数返回类型是shared_ptr，因此会再调用一次shared_ptr的拷贝构造函数，递增目标对象的引用计数，递减该临时副本的引用计数
    return ret;
}

int main(){
    SmartPointer<int> sp(new int(10));

    cout << sp.use_count() << endl;

    {
        SmartPointer<int> sp2(sp); // 拷贝
        cout << sp.use_count() << endl;
        cout << sp2.use_count() << endl;

        SmartPointer<int> sp3(new int(20));
        cout << sp3.use_count() << endl;

        sp2 = sp3;
        cout << sp.use_count() << endl;
        cout << sp2.use_count() << endl;
        cout << sp3.use_count() << endl;
    }
    
    cout << sp.use_count() << endl;

    return 0;
}