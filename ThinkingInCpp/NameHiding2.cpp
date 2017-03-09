// NameHiding2.cpp  Virtual functions restrict overloading
	#include <iostream>
	#include <string>
	using namespace std;

	class Base{
	public:
		virtual int f() const{
			cout << "Base::f()\n";
			return 1;	
		}
		virtual void f(string) const {}
		virtual void g() const {}
	};

	class Derived1 : public Base{
	public:
		void g() const {}
	};

	class Derived2 : public Base {
	public:
		// Overriding a virtual function:
		int f() const{
			cout << "Derived2::f()\n";
			return 2;
		}
	};

	class Derived3 : public Base{
	public:
		// Cannot change return type; 
		//! void f() const {cout << "Derived3::f()\n";}
	};

	class Derived4 : public Base {
	public:
		// Change arguement list: 覆盖其他版本！
		int f(int) const {
			cout << "Derived4::f()\n";
			return 4;
		}
	};

	int
	main(){
		string s("hello");
		Derived1 d1;
		int x = d1.f();
		cout << "d1: " << x << endl;
		d1.f(s);
		Derived2 d2;
		x = d2.f();
		cout << "d2: " << x << endl;
		//! d2.f(s); // string version hidden(已被覆盖)
		Derived4 d4;
		x = d4.f(1);
		cout << "d4: " << x << endl;
		//! x = d4.f(); // f() version hidden
		//! d4.f(s);  // string version hidden (均被覆盖)
		Base& br = d4; // Upcast
		//! br.f(1); // Derived version unavailable 
		x = br.f();   // Base version available
		cout << "d4 upcast to Base : " << x << endl;
		br.f(s);   // Base version available 

		return 0;
	}

