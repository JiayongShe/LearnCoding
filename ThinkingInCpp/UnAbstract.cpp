// UnAbstract.cpp  Pure virtual destructions seem to behave strangely
	
	class AbstractBase{
	public:
		virtual ~AbstractBase() = 0;
	};

	AbstractBase::~AbstractBase() {}

	class Derived : public AbstractBase {};  //����Ҫ���¶��崿������������ 
	// No overriding of destructor necessary?

	int
	main(){
		Derived d;

		return 0;	
	} 
