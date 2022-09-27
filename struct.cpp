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

