#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout << "A()\n";
    }
    ~A(){
        cout << "~A()\n";
    }

private:
    int a;
};

int main(){
    void *p = malloc(sizeof(A));
    cout << "sizeof(A) :" << sizeof(A) << endl;
    A *a = new(p) A();
    cout << "sizeof(a) :" << sizeof(a) << endl;
    cout << "sizeof(*a) :" << sizeof(*a) << endl;
    free(p);
    //free(a);
}
