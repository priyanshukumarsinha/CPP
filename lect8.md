# Lecture 8 : Static Members in C++

## 1. Static Local Variable

- Concept as it is taken from C
- They are by default initialized to zero.
- Their lifetime is throughout the program.

```cpp

void func()
{
	static int x;
	int y;
	
	// here x variable is a static variable 
	// x will have a value 0 already assigned to it whereas y will have some garbage value,
	// x will get memory when program starts whereas y will only get memory when function is called.
	// x will have memory allocated to it throughout the program whereas y will only have it till the function is processing.
}

```

## 2. Static Member Variable

- Declared inside the class body.
- Also known as class member variable.
- They must be defined outside the class.
- Static member variable does not belong to any object, but to the whole class.
- There will be only one copy of static member variable for the whole class.
- Any object can use the same copy of class variable.
- They can also be used with class name.

```cpp

#include<iostream>
using namespace std;

class Account
{
	private:
		int balance; // Instance Member Variable
		static float roi; // static member variable/ class variable declaration

	public:
		void setBalance(int b)
		{
			balance = b;
		}
};

float Account:: roi = 3.5f; // declaration outside the class // Account:: is called membership label

int main()
{
	Account a1, a2;
	//both of these objects can access roi and its value will be same (3.5) for both of them
}

```

**But how can we access roi from main() function?**

```cpp

int main()
{
	//we can do it using membership label like
	Account:: roi = 4.5f; //this will set the value of roi to 4.5 without having to create an object
}

```

**But how can we do this with the help of a function (say setRoi())?** 

we will define a function in class Account

```cpp

#include<iostream>
using namespace std;

class Account
{
        private:
                int balance; // Instance Member Variable
                static float roi; // static member variable/ class variable declaration

        public:
                void setBalance(int b)
                {
                        balance = b;
                }
		
		void setRoi(int r)
		{ roi = r; }
};

float Account:: roi = 3.5f; // declaration outside the class // Account:: is called membership label

int main()
{
        Account a1, a2;
        a1.setRoi(4.6f);

```

**Can we use this function with having to make an object?**

Yes, But for that we will have to make setRoi() a static Member function.

## 3. Static Member Function

- They are qualified with the keyword static.
- They are also called class member functions.
- They can be invoked with or without object.
- They can only access static members of the class.

```cpp

#include<iostream>
using namespace std;

class Account
{
        private:
                int balance; // Instance Member Variable
                static float roi; // static member variable/ class variable declaration

        public:
                void setBalance(int b)
                { balance = b; }
		
		static void setRoi(int r) //Static Member Function
		{ roi = r; }
};

float Account:: roi = 3.5f; // declaration outside the class // Account:: is called membership label

int main()
{
        Account::setRoi(4.6f);
}

```

