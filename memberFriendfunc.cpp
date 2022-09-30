#include<iostream>
using namespace std;

class A
{
	private:
		int a;
	public:
		void fun()
		{
			cout << "in Class A" << endl;
		}
};

class B
{
	private:
		int b;
	public:
		friend void A::fun();
};

int main()
{
	A obj1;
	B obj2;

	return 0;
}
