# Lecture 9 : Constructors in C++

- Constructor is a member function of a class.
- The name of the constructor is same as the name of the class.
- It has no return type, so can't use return keyword.
- It must be an instance member function, that is, it can never be static.
- Example :

```cpp

#include <iostream>
using namespace std;

class Complex
{
	private:
		int a,b;
	public:
		Complex();
		{ }
};

int main()
{
	return 0;
}

```

## How to call Constructor?

- Constructor is implicitly invoked when an object is created.
- Constructor is used to solve problem of initialization.

## What is the problem of Initialization?

The data members of a class have private scope by default, So they can not be accessed directly outside the class. Therefor, when the objects are created member variables of object cannot be initialized directly and this problem of not being able to initialize data members (instance variables) is known as Problem of Initialization.

## Constructor Overloading

```cpp

#include<iostream>
using namespace std;

class Complex
{
	private:
		int a,b;
	public:
		Complex(int x, int y) //Parameterized Constructor
		{ a=x; b=y; }

		Complex(int k) //Parameterized Constructor
		{ a=k; }

		Complex() //default Constructor
		{}
};

int main()
{
	//different ways of creating an object and using constructor
	Complex c1(1,2), c2 = Complex(3,4);
	Complex c3(5), c4 = Complex(5), c5 = 5; 
	Complex c6;

	return 0;
}

```

Compileer creates two type of conostructors on its own 
1. **default constructors** and
2. **copy constructors**

When we create a constructor, compiler stops making default constructor and only makes copy constructor.

When we create a copy constructor, compiler does not creates any constructor on its own.

## How to create a copy constructor?

it takes a reference variable as argument.

```cpp

#include<iostream>
using namespace std;

class Complex
{
	private:
		int a,b;
	public:
		Complex(int x, int y)
		{ a=x;b=y; }
		Complex(int k)
		{a=k;}
		Complex()
		{}
		
		Complex(Complex &c)
		{
			a = c.a;
			b = c.b;
		}
};

int main()
{
	Complex c1(5,6);
	Complex c2(c1);

	return 0;
}

```
