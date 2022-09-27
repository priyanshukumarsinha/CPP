# Lecture 7 : Classes and Objects in C++

## Class and Structure
The only difference between structure and class is that,
- the members of structures are by default public and
- the members of class are by default private.

```cpp
#include <iostream>
using namespace std;

class Complex
{
	//these members will by default private but we can still write it for better readability
	private:
		int a,b;
	public:
		void set_data(int x,int y)
		{
			a=x;
			b=y;
		}
		
		void show_data()
		{
			cout << "a = " << a << "\nb = " << b << endl;
		}
	
};

int main()
{
	complex c1; //here c1 is not a variable it is an Object
	c1.set_data(3,5);
	c1.show_data();

	return 0;
}

```

We can also define member function outside class block but we will have to declare it within class block for it to be used as a member function

```cpp
#include <iostream>
using namespace std;

class Complex
{
        //these members will by default private but we can still write it for better readability
        private:
                int a,b;
        public:
                void set_data(int,int); //function declaration
                void show_data()
                {
                        cout << "a = " << a << "\nb = " << b << endl;
                }

};

void Complex:: set_data(int x, int y)
{
	a=x;
	b=y;
}

int main()
{
        complex c1; //here c1 is not a variable it is an Object
        c1.set_data(3,5);
        c1.show_data();

        return 0;
}
        
```

## Technical Jargons

- Class is a description of an object

```cpp

//it is a blueprint of an object
class Complex
{
	private: 
		int a,b;
	public:
		//member functions
		void set_data(int x, int y)
		{
			a=x;
			b=y;
		}
		void show_data()
		{
			cout << "a = " << a << "\nb = " << b << endl;
		}
}
```

- Object is an instance of a class

```cpp
int main()
{
	Complex c1; //c1 is an object (an instance/example of a class Complex)	
}
```

- Instance member variable

(also called) Attributes, data members, fields, properties

```cpp

//c1.a and c1.b are instance member variables but we cannot access them directly since they are private
c1.a;
c1.b;
```

- Instance member functions

(also called) methods, procedures, actions, operations, services.

```cpp
c1.set_data(3,4); //set_data() function is called an instance member function which is defined in class Complex for object c1
```
