// UnAbstract.cpp  Pure virtual destructions seem to behave strangely
	
	class AbstractBase{
	public:
		virtual ~AbstractBase() = 0;
	};

	AbstractBase::~AbstractBase() {}

	class Derived : public AbstractBase {};  //不需要重新定义纯虚析构函数！ 
	// No overriding of destructor necessary?

	int
	main(){
		Derived d;

		return 0;	
	} 
