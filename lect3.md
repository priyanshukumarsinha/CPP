# Lecture 3 : Input-Output

## Output Instruction
- In C, standard output device is monitor and **printf()** is used to send data/message to monitor
- **printf()** is a **predefined function**.
- In C++, we can use **cout** to send data/ message to monitor.
- cout is a **predefined object**
- The operator **<<** is called **insertion or put to** operator

```cpp
printf("Hello World!"); //in C
cout << "Hello World!"; // in C++

printf("sum of %d and %d is %d", a,b,c);
cout << "sum of "<<a<<" and "<<b<< "is" << c;

printf("%d", a+b);
cout << a+b;

```

## Input Instruction
- In C, Standard input device is keyboard and **scanf()** is used to recieve data from keyboard.
- scanf() is a **predefined function**.
- In C++, we can use **cin** to input data from keyboard.
- The identifier cin is a **predefined object** in C++.
- The operator **>>** is known as extraction or get from operator

```cpp

scanf("%d", &a); // in C
cin >> a; // in C++

scanf("%d%d",&a, &b);
cin >> a >> b;

```

## Remember
- According to the ANSI standards for C language, explicit declaration of function is recommended but not mandatory.
- ANSI standards for C++ language says explicit declaration of function is compulsory.

## Header files
- predefined functions are declared in header files, so whenever you are using any predefined function in your code, you have to include specific header file that contains its declaration.

## About iostream.h
- We need to include header file iostream.h, it contains declarations for the identifier cout and the operator <<. And also for the identifier cout and operator >>.
- Header file contains declaration of identifiers.
- Identifiers can be function names, variables, objects, Macros, etc.

## endl
- Inserting **endl** into the output stream causes the screen cursor to move to the beginning of the next line.
- endl is a manipulator and it is **declared in iostream.h**
- **'\n'** character also works as it works in C.

## Sample Program (square.cpp)
```cpp

#include <iostream.h> //Declaration of cin and cout
#include <conio.h> //Declaration of clrscr(), getch()

//action statements
int main()
{
	clrscr();
	int x; //Declaration after action statement
	cout << "Enter a Number : " << endl;
	cin >> x;
	int s = x*x; //Run-time / Dynamic Initializaton
	cout << "Square of" << x << "is" << s;
	return 0;
}
```
