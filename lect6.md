# Lecture 6 : Structures in C++
- Structure is a collection of dissimilar elements.
- Structure is a way to group variables. (encapsulation)
- Structure is used to create Data types.

```cpp

#include <iostream>
using namespace std;

struct book
{
	int bookID;
	char title[20];
	float price;
};

int main()
{
	book b1; //struct keyword is optional here in C++
	
	//we can initialize b1 during declaration like : book b1 = { 100, "Book Name", 459.90);
	//or we can also initialize it after declaration like : 
	
	b1.bookID = 100;
	strcpy(b1.title, "Book Name"); // b1.title = "Book Name" won't work since it will only give address of the first char
	b1.price = 459.90;
	
	return 0;
}

```

## Difference Between structure in C and C++

### 1. struct keyword is optional in C++ (unlike C)

```cpp

#include<iostream>
using namespace std;

struct book
{
        int bookID;
        char title[20];
        float price;
};

book input();
void display(book);

int main()
{
        book b1; //struct keyword is optional in C++
        b1 = input(); //we will need the function to return a struct of type book
        display(b1); //takes struct returns nothing
}

book input()
{
        book b;
        cout << "Enter Book Id, Price, and Title: ";
        cin >> b.bookID >> b.price >> b.title;

        return b;
}

void display(book b)
{
        cout << "Book Id : " << b.bookID << "\nTitle : " << b.title << "\nPrice : " << b.price << endl;
}

```



### 2. We can define functions inside a structure in C++ (called member functions)

```cpp
#include<iostream>
using namespace std;

struct book
{
	int bookID;
	char title[20];
	float price;
	
	//we can also define functions in a structure in C++
	//these functions are called member functions.
	//and they can be accessed as objects.
	void input()
	{
	        cout << "Enter Book Id, Price, and Title: ";
	        cin >> bookID >> price >> title;

	}

	void display()
	{
		cout << "Book ID : " << bookID << "\nTitle : " << title << "\nPrice : " << price;
	}
};

int main()
{
	book b1;
	b1.input();
	b1.display();

	return 0;
}
```

### 3. Data Security (using Private, Protected and Public Keywords)
In the code above, we can see that if we run the code and enter the value of bookID as -100 (i.e a negative number) which might be against policies of that data (since, generally bookID must be a non-negative number).

We can solve this by using conditional statement in input() function to check if the number is -ve of +ve and if it is -ve convert it to a +ve number by multiplying it with -1.

```cpp

void input()
{
	 
        cout << "Enter Book Id, Price, and Title: ";
        cin >> bookID >> price >> title;

	if(bookID<0)
		bookID = -bookID;
}

```

But what if someone changes its value via main() function.

```cpp
int main()
{
	book b1;
	b1.bookID = -100;
}
```

This will result in corrupt value of bookID which might cause futher problems.

So, to stop this from happening we can restrict access of these variables using **Private** Keyword.

```cpp

#include<iostream>
using namespace std;

struct book
{	
	Private : 
        	int bookID;
        	char title[20];
        	float price;

	//but this way we won't even be able to access input() and display() functions
	//and therefore we will use Public Keyword here so that we can access these functions
	
	Public : 
        void input()
        {
                cout << "Enter Book Id, Price, and Title: ";
	        cin >> bookID >> price >> title;

        }

        void display()
        {
                cout << "Book ID : " << bookID << "\nTitle : " << title << "\nPrice : " << price;
        }
};

int main()
{
        book b1;
        b1.input();
        b1.display();

        return 0;
}

```





