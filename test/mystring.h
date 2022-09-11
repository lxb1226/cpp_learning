#include <iostream>
#include <cstring>

using namespace std;

class String{
public:
    String();
    // 默认构造函数
    String(const char* str = nullptr);
    // 拷贝构造函数
    String(const String &str);

    // 移动构造函数
    String(String&& str);

    // 析构函数
    ~String();
    // 字符串赋值函数
    String& operator=(const String& str);

    String& operator+(const String& str) const; // 重载+
    char& operator[](int n) const;

private:
    char* m_data;
    int m_size;
};

char& String::operator[](int n) const{
    if(n > 0 && n < m_size) return m_data[n];
    return m_data[n - 1];
}


String& String::operator+(const String& str) const {
    int size = m_size + str.m_size;
    char* tmp = new char[size + 1];
    strcpy(tmp, m_data);
    strcpy(tmp + m_size, str.m_data);
    String ret(tmp);
    delete[] tmp;
    return ret;
}

String::String() : m_data(new char[1]){
    m_data[0] = '\0';
}

String::String(const char* str){
    if(str == nullptr){
        m_data = new char[1];
        m_data[0] = '\0';
        m_size = 0;
    }else{
        m_size = strlen(str);
        m_data = new char[m_size + 1];
        strcpy(m_data, str);
    }
}

String::String(const String& str){
    m_size = str.m_size;
    m_data = new char[m_size + 1];
    strcpy(m_data, str.m_data);
}

String::~String(){
    delete[] m_data;
}

String& String::operator=(const String& str){
    if(this == &str)
        return *this;
    
    delete[] m_data;
    m_size = str.m_size;
    m_data = new char[m_size + 1];
    strcpy(m_data, str.m_data);

    return *this;
}

String::String(String && str){
    this->m_size = str.m_size;
    this->m_data = str.m_data;
    str.m_data = nullptr;
}