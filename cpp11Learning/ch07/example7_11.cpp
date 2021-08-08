
class DefaultedOptr{
public:
    DefaultedOptr() = default;
    DefaultedOptr & operator = (const DefaultedOptr &);
};

// 在类定义外用"= default" 来指明使用缺省版本
inline DefaultedOptr &
DefaultedOptr::operator=(const DefaultedOptr &) = default;