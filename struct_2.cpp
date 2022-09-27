#include<iostream>
using namespace std;

struct book
{
	int bookID;
	char title[20];
	float price;
	
	//we can also define functions in a structure in C++
	//these functions are called member functions.
	//and they can be accessed as object.
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
