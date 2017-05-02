// 相关网页介绍：http://www.voidcn.com/blog/u011619422/article/p-2289121.html
#include <iostream>

using namespace std;


namespace {

    inline int getValue(int a){
        return a;
    }

}


int main()
{

    cout << "please input your id:";
    int a;
    cin >> a;
    cout<<"your id is :"<<getValue(a)<<endl;

    return 0;
}
