# Lecture 10 : Destructors

- Destructor is an instance member function of a class.
- The name of the destructor is same as the name of a class but preceded by tilde (~) symbol.
- Destructor can never be static.
- Destructor has no return type.
- Destructor takes No argument (No Overloading is possible)
- It is invoked implicitly when object is going to destroy.

```cpp

#include<iostream>
using namespace std;

class Complex
{
	private:
		int a,b;
	public:
		Complex() //Constructor (first function of object)
		{ }
		
		~Complex() //Destructor (last function of object)
		{
			cout << "Destuctor"; 
		}
};

void fun()
{
	Complex c1; //this object will get destroyed when fun function has completed its work.
}

int main()
{
	fun();
}

```

## Why destructor?

It should be defined to release (or access) resources allocated to an object.
