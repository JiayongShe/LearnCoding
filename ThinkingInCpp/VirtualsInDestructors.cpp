// VirtualsInDestructors.cpp  Virtual calls inside destructors
	#include <iostream>
	using namespace std;
	
	class Base{
	public:
		virtual ~Base(){
			cout << "Base()\n";
			f();
		}
		virtual void f(){
			cout << "Base::f()\n";
		}
	};

	class Derived : public Base {
	public:
		~Derived() {
			cout << "~Derived()\n";
		//	f();
		}
		void f() {cout <<  "Derived::f()\n";}		
	};

	int 
	main(){
		Base *bp = new Derived;  // Upcast
		delete bp;
		
		return 0;
	}
