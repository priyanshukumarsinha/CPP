# Lecture 12 : Friend Function

- Friend Function is not a member function of a class to which it is a Friend.
- Friend Function is declared in the class with friend keyword.
- It must be defined outside the class to which it is friend.
- Friend Function can access any member of the class to which it is friend.
- Friend Function cannot access member of the class directly.
- It hass no caller object.
- It should not be defined with membership label.

```cpp
#include<iostream>
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
		friend void fun(Complex); // declaration of friend function
};

void fun(Complex c)
{
	cout << "Sum is " << (c.a+c.b);
}

int main()
{
	Complex c1;
	c1.setData(3,4);
	fun(c1); //3+4 = 7

	return 0;
}
```

- Friend Function can become friend to more than one class.

```cpp
class B; //forward declaration of class B for fun() function.
class A
{
	private:
		int a;
	public:
		void setData(int x)
		{ a=x; }
		friend void fun(A, B);
};

class B
{
	private:
		int b;
	public:
		void setData(int x)
		{ b=x; }
		friend void fun(A, B);
};

void fun(A o1, B o2)
{	cout << "\nSum is " << o1.a+o2.b << endl; }

int main()
{
	A obj1;
	B obj2;
	obj1.setData(3);
	obj2.setData(4);
	fun(obj1, obj2);
	return 0;
}
```

## Operator Overloading with friend Function

```cpp
#include<iostream>
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
                friend Complex operator+(Complex,Complex);
};

Complex operator+(Complex c1, Complex c2)
{
        Complex temp;
        temp.a = c1.a+c2.a;
        temp.b = c1.b+c2.b;
        return temp;
}

int main()
{
        Complex c1,c2,c3;
        c1.setData(3,4);
        c1.showData();
        c2.setData(5,6);
        c2.showData();
        c3 = c1 + c2; //c3 = operator+(c1,c2);
        c3.showData();
        return 0;
}
```

## Unary Operator Overloading with friend function

```cpp
#include<iostream>
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
                friend Complex operator+(Complex,Complex);
                friend Complex operator-(Complex);
};

Complex operator-(Complex c1)
{
        Complex temp;
        temp.a = -c1.a;
        temp.b = -c1.b;
        return temp;
}

Complex operator+(Complex c1, Complex c2)
{
        Complex temp;
        temp.a = c1.a+c2.a;
        temp.b = c1.b+c2.b;
        return temp;
}

int main()
{
        Complex c1,c2,c3;
        c1.setData(3,4);
        c1.showData();
        c2.setData(5,6);
        c2.showData();
        c3 = c1 + c2; //c3 = operator+(c1,c2);
        c3.showData();

        Complex c4 = -c3;
        c4.showData();
        return 0;
}

```

## Increment Decrement Operator Overloading 

```cpp

#include<iostream>
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
                friend istream& operator>>(istream&, Complex&);
                //cout and cin are defined in ostream and instream Classes 
                //but we cannot make an object of these classes                       
                //therefore we will use reference of that
                friend ostream& operator<<(ostream&, Complex);
};

istream& operator>>(istream &din, Complex &c)
{
        cin >> c.a >> c.b;
        return din; //return so that we can use cascading i.e cin >> c1 >> c2;
}

ostream& operator<<(ostream &dout, Complex c)
{
        cout << "\na = " << c.a << "\nb = " << c.b << endl;
        return dout;
}

int main()
{
        Complex c1;
        cout << "Enter a complex Number : ";
        cin >> c1; //for this to work we will have to overload >> operator to work with Complex class
        cout << c1;
        return 0;
}

```

## Member Function of one class can be friend to other.

```cpp
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
```
