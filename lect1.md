# Lecture 1 : INTRODUCTION TO C++

## History of C++
- C++ was developed by Bjarne Stroustrup in 1979 at AT & T's Lab, it was called C with Classes
- C++'s OOP aspect was inspired by a computer simulation language called simula67
- JAVA is written in C++
- Major OS of modern times are written in C++

## Features of C++
- C++ is a middle level language
- C++ supports principles of OOP 
- C++ joins three separate programming traditions
	- The procedural language tradition, represented by C
	- The Object-Oriented language tradition, represented by Class enhancement C++ adds to C
	- generic programming, supported by C++ templates

## Comparision between C and C++
- C++ is a super set of C language
- C++ programs can use existing C software libraries
- C follows top down approach of programming
- C++ follows bottom up approach of programming
- C adopts Procedure Oriented Programming (POP)
- C++ adopts Object Oriented Programming (OOP) as well as POP

## Object Oriented Programming
- OOPs is a programming approach which revolves around the concept of "Object"
- Any entity in the system that can be defined as a set of properties and set of operations performed using entity's property set, is known as object.
	- Encapsulation
	- Data Hiding
	- Abstraction
	- Polymorphism
	- Inheritance

## Concept of Classes and Objects
- Class is a blueprint of an Object
- Class is a description of Object's Property set and set of operations
- Creating class is as good as defining a new data type
- Class is a means to achieve encapsulation
- Object is a run time entity
- Object is an instance of a class.

Example : 
```cpp

class box
{
    int l,b,h;
    void setDimension(int x, int y, int z)
    { 
	//something
    }
    void showDimesion()
    {
        //something
    }
};

//now we can create an object like this
box b1;

```


## Software Development in C++
- software dev process in c++ is very similar to that of c language
- first we make a file and write our code in it 
- save this file with extension cpp
- this file contains many preprocessor statements like #include
- our file (say sum.cpp) will go to preprocessor where preprocessor will see all preprocessor statements and write code in their place using header files
- a sum.i file will be made in RAM
- this sum.i file will go to compiler now where it will get converted into machine readable form (binary) and sum.obj will be formed
- but there must still be some unknown code which will be solved by linker by linking library files
- now we will get a sum.exe file which can be used to run the program


--*--

