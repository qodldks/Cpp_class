// 다중상속 문제해결
#include <iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "Base Constructor" << endl; }
	void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDrivedOne : virtual public Base
{
public:
	MiddleDrivedOne() : Base()
	{
		cout << "MiddleDrivedOne Constructor" << endl;
	}
	void MiddleFuncOne()
	{
		SimpleFunc();
		cout << "MiddleDrivedOne" << endl;
	}
};

class MiddleDrivedTwo : virtual public Base
{
public:
	MiddleDrivedTwo() : Base()
	{
		cout << "MiddleDrivedTwo Constructor" << endl;
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();
		cout << "MiddleDrivedTwo" << endl;
	}
};

class LastDerived : public MiddleDrivedOne, public MiddleDrivedTwo
{
public:
	LastDerived() : MiddleDrivedOne(), MiddleDrivedTwo()
	{
		cout << "LastDerived Constructor" << endl;
	}
	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main(void)
{
	cout << "객체 생성 전----------" << endl;
	LastDerived ldr;
	cout << "객체 생성 후----------" << endl;
	ldr.ComplexFunc();
	return 0;
}