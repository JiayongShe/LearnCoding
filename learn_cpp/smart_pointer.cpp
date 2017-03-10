#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> up1(new int(10)); // 不能复制的unique_ptr
    // unique_ptr<int> up2 = up1; // 这样是错的
    cout<<*up1<<endl;

    unique_ptr<int> up3 = move(up1); // 现在up3是数据唯一的unique_ptr智能指针

    cout<<*up3<<endl;
    // cout<<*up1<<endl; // 运行时错误

    up3.reset(); // 显示释放内存
    up1.reset(); // 即使up1没有拥有任何内存，但是这样调用也没有问题
    // cout<<*up3<<endl; // 已经释放掉up3了，这样会运行时错误

    shared_ptr<int> sp1(new int(20));
    shared_ptr<int> sp2 = sp1; // 这是完全可以的，增加引用计数

    cout<<*sp1<<endl;
    cout<<*sp2<<endl;

    sp1.reset(); // 减少引用计数
    cout<<*sp2<<endl;

    return 0;
}
