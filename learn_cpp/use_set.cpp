#include <iostream>
#include <set>
#include <list>
using namespace std;

class A{
public:
    A(){
        int a[] = {1, 2, 3};
        int c[] = {4, 5, 6};
        set<int> b(a, a+3);
        set<int> d(c, c+3);
        m_list.push_back(b);
        m_list.push_back(d);
    }
    void get_list(list<set<int>>& svcs){
        for (auto tmp : m_list) {
            svcs.push_back(tmp);
        }
    }
private:
    list<set<int>> m_list;
};

int main ()
{
    A test;
    list<set<int>> tmp;
    test.get_list(tmp);

    for (auto it : tmp) {
        for (auto iter : it){
            cout << iter  << endl;
        }
    }


    return 0;
}


