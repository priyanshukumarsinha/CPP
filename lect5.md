# Lecture 5 : Functions

## What is Function?
- Function is a bloack of code performing a unit task.
- Function has a name, return type and arguments.
- Function is a way to achieve modularization.
- Functions are predefined and user-defined.
- Pre-defined functions are declared in header files and defined in library files.

## Definition, Declaration and Call

```cpp

#incude<iostream> //declaration of cin and cout
using namespace std;

int main()
{
	void fun(); //local function declaration
	cout << "You are in main";
	fun(); //function call
	
	return 0;
}

void fun() //function definition
{
	cout << "You are in fun function";
}

```

## Declaration
- Function declaration is also known as Function prototype.
- Function need to be declared before use (just like variables).
- Function can be declared locally or globally.
- Example : ReturnType functionName(argumentList);
- Function definition is a block of code.

## Ways to define a function
- Takes Nothing, Returns Nothing
- Takes Something, Returns Nothing
- Takes Nothing, Returns Something
- Takes Something, Returns Something

## Formal and Actual Arguments

```cpp
#include <iostream>
using namespace std;

int sum(int, int);

int main()
{
	int a=5, b=6;
	int s= sum(a,b); //here a and b are actual arguments
	cout << "Sum is " << s;
	
	return 0;
}

int sum(int x, int y) // here x and y are formal arguments
{
	return x+y;
}

```

## Types of Formal Arguments
- Formal arguments can be of three types
	- Ordinary Variable of any type
	- Pointer Variables
	- Reference Variables
- **Call by Value**
	- when formal arguments are ordinary variables, it is function call by value.

```cpp
#include<iostream>
using namespace std;

int sum(int, int)

int main()
{
	int a, b;
	cout << "Enter two Numbers : ";
	cin >> a >> b;

	int s = sum(a,b);

	cout << "Result is : " << s;

	return 0;
}

int sum(int x, int y)
{
	return x+y;
}

```

- **Call by Address**
	- when formal arguments are pointer variables, it is function call by address.

```cpp

#include<iostream>
using namespace std;

int sum(int*, int*)

int main()
{
	int a, b;
	cout << "Enter two Numbers : ";
	cin >> a >> b;
	
	int s = sum(&a, &b);

	cout << "Result : " << s;
	
	return 0;
}

int sum(int *p, int *q)
{
	return *p+*q;
}

```

- **Call by Reference**
	- when formal arguments are reference variable, it is function call by reference.
	
```cpp
#include <iostream>
using namespace std;

int sum (int &, int &);

int main()
{
	int a, b;
	cout << "Enter two Numbers : ";
	cin >> a >> b;

	int s = sum(a,b);

	cout << "Result : << s;

	return 0;
}

int sum (int &y, int &z)
{
	return y+z;
}
```

## Benefits of function
- Easy to read
- Easy to Modify
- Avoids rewriting of same code
- Easy to debug
- Better Memory Utilization
- **Function savees memeory**
	- function in a program is to save memory space which becomes appreciable when a function is likely be called many times.
### Function is time consuming
- However evey time a function is called, it takes lot of extra time in executing a series of instructions for tasks such as jumping to the functions, saving registers, pushing arguments into the stack and returning to the calling function.
- So, when function is small it is worthless to spend so much extra time in such tasks in cost of saving comparatively small space.

## Inline Function
- To eliminate the cost of calls to small functions, C++ proposes a feature called inline function.
- An inline function is a function that is expanded in line when it is invloved.
- Compiler replaces the function call with the corresponding function code.

## Inline is a request
- Inline is a request, not a command.
- The benefit of speed of inline functions reduces as the function grows in size.
- So, the compiler may ignore the request in some situatiojns
	- Few of them are : 
		1. Function containing loops, switch, goto.
		2. Function with recursion.
		3. Containing static Variable.
- Example : 

```cpp

#include <iostream>
using namespace std;

inline void fun(); // function Declaration

int main()
{
	cout << "You are in main";
	fun(); // function call
}

void fun() // function Definition
{
	cout << "You are in Fun";
}
```

## Default Arguments

```cpp
#include <iostream>
using nnamespace std;

int add(int, int, int=0) // default argument

int main()
{
	int a, b;
	cout << "Enter two Numbers : ";
	cin >> a >> b;
	cout << "Sum is " << add(a,b); // here we have only passed 2 arguments but it will not throw an errow since we have already assigned default argument to the third one
	
	int c;
	cout << "Enter three Numbers : ";
	cin >> a >> b >> c;
	cout << "Sum is " << add(a, b, c);

	return 0;
}

int add(int x, int y, int z)
{
	return x+y+z;
}
```

## Function Overloading
- different function doing similar work but having same name is called Function Overloading.

```cpp
#include <iostream>
using namespace std;

int area(int, int);
float area(int);

int main()
{
	int r;
	cout << "Enter radius of a circle : ";
	cin >> r;
	
	float A = area(r);
	cout << "\nArea off Circle is " << A;
	
	int l, b, a;
	cout << "\nEnter length and breadth of rectangle : ";
	cin >> l >> b;
	a = area(l,b);
	cout << "\n Area of Rectangle is : " << a;

	return 0;
}

float area(int R)
{
	return 3.14*R*R;
}

int area(int L, int B)
{
	return L*B;
}

```

## How Function Overloading is Resolved?
- First C++ tries to find an exact match. This is the case where the actual argument exactly matches the parameter type of one of the overloaded functions.
- If no exact match is found, C++ tries to find a match through promotion.
	- char, unsigned char, and short is promoted to an int.
	- float is promoted to double.
- If no promotion is found, C++ tries to find a match through standard conversion.

