#include <memory>
#include <cassert>

using namespace std;

class Foo
{
public:
    std::shared_ptr<Foo> GetSPtr()
    {
        return std::shared_ptr<Foo>(this);
    }
};

int main()
{
    std::unique_ptr<int> uptr = std::make_unique<int>(200);
    // std::unique_ptr<int> uptr1 = uptr; // 编译错误

    std::unique_ptr<int> uptr2 = std::move(uptr); // 移动语义
    assert(uptr == nullptr);

    {
        std::shared_ptr<int> sptr = std::make_shared<int>(200);
        assert(sptr.use_count() == 1); // 此时引用计数为 1
        {
            std::shared_ptr<int> sptr1 = sptr;
            assert(sptr.get() == sptr1.get());
            assert(sptr.use_count() == 2); // sptr 和 sptr1 共享资源，引用计数为 2
        }
        assert(sptr.use_count() == 1); // sptr1 已经释放
    }
    // use_count 为 0 时自动释放内存

    {
        auto sptr1 = std::make_shared<Foo>();
        assert(sptr1.use_count() == 1);
        auto sptr2 = sptr1->GetSPtr();
        assert(sptr1.use_count() == 1);
        assert(sptr2.use_count() == 1);
    }
}