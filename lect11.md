# Lecture 11 : Operator Overloading 

Earlier, we learned how to add two complex numbers using member function add() like c3 = c1.add(c2);

```cpp

#include <iostream>
using namespace std;

class Complex
{
	private:
		int a,b;
	public:
		void setData(int x, int y)
		{ a=x; b=y; }
		void showData()
		{ cout << "\na = " << a << "\nb = " << b << endl; }
		
		Complex add(Complex c)
		{
			Complex temp;
			temp.a = a+c.a;
			temp.b = b+c.b;

			return temp;
		}
};

int main()
{
	Complex c1, c2, c3;
	c1.setData(1,2);
	c2.setData(3,4);
	c3 = c1.add(c2);
	c3.showData(); // a = 4 b = 6
}

```	

But we can also do it like c3 = c1 + c2;
**"+"** operator already has a function defined for it for primitive data type.
But we want to use it for our Complex class also, So we will have to use **Function Overloading** for the operator **+** (using operator keyword).


```cpp

#include <iostream>
using namespace std;

class Complex
{
        private:
                int a,b;
        public:
                void setData(int x, int y)
                { a=x; b=y; }
                void showData()
                { cout << "\na = " << a << "\nb = " << b << endl; }

                Complex operator +(Complex c) //we will have to use operator keyword for this
                {
                        Complex temp;
                        temp.a = a+c.a;
                        temp.b = b+c.b;

                        return temp;
                }
};

int main()
{
        Complex c1, c2, c3;
        c1.setData(1,2);
        c2.setData(3,4);
        //c3 = c1.operator+(c2); //we can either do this or simply write c1 + c2
	c3 = c1 + c2;
        c3.showData(); // a = 4 b = 6
}

```


- when an operator is overloaded with multiple jobs, it is known as **operator overloading**.
- It is a way to implement complie time **polymorphism**.

## Rules to Remember

- Any smybol can be used as function name
	- If it is a valid operator in C language.
	- If it is preceded by operator keyword.
- You can not overload **sizeOf** and **?:** operator.

## Overloading of Unary Operator

```cpp
#inculde <iostream>
using namespcae std;

class Complex
{
	private:
		int a,b;
	public:
		void setData(int x, int y)
		{ a=x; b=y; }
		void showData()
		{ cout << "\a = " << a "\b = " << b << endl; }
		Complex operator-()
		{
			Complex temp;
			temp.a = -a;
			temp.b = -b;
			return temp;
		}		
};

int main()
{
	Complex c1,c2;
	c1.setData(3,4);
	c2 = -c1; //i.e c2 = c1.operator-();
	c2.showData(); //-3,-4
	
	return 0;
}
```

## Overloading of increment Operator (Pre/Post)

```cpp
#include<iostream>
using namespace std;

class Integer
{
        private:
                int x;
        public:
                void setData(int a)
                { x=a; }
                void showData()
                { cout << "x = " << x << endl; }
                Integer operator++()//preincement
                {
                        Integer i;
                        i.x = ++x;
                        return i;
                }
		//postincrement
                Integer operator++(int) //this argument will not take any input but it is necessary for differentiation 
                {
                        Integer i;
                        i.x = x++;
                        return i;
                }
};

int main()
{
        Integer i1,i2;
        i1.setData(3);
        i1.showData(); //3
        i2 = i1++; //i1.operator++()
        i1.showData(); //4
        i2.showData(); //4
        return 0;
}

	return 0;
}

```
