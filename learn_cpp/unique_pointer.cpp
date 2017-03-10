#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int> Func(unique_ptr<int> a)
{
    cout<< "*a = " <<*a<<endl;
    return a;
}

int main()
{
    unique_ptr<int> up1(new int(10));

    up1 = Func(move(up1));
    cout<< "*up1 = " <<*up1<<endl;

    return 0;
}
