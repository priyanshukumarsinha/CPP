#include<iostream>
using namespace std;

class Rectangle
{
	int L,B;
	public : 
		void setDimensions(int, int);
		void showDimensions();
		int getArea();
		int getPerimeter();
};

void Rectangle:: setDimensions(int l, int b)
{
	L=l; B=b;
}

void Rectangle:: showDimensions()
{
	cout << "length : " << L << "\nbreadth : " << B << endl;
}

int Rectangle:: getArea()
{
	return L*B;
}

int Rectangle:: getPerimeter()
{
	return 2*(L+B);
}

int main()
{
	Rectangle r1;
	int l,b;
	cout << "Enter length and breadth of the Rectangle : ";
	cin >> l >> b;
	r1.setDimensions(l,b);
	r1.showDimensions();
	cout << "Area of the Rectangle : " << r1.getArea() << " units square\n";
	cout << "Perimeter of the Rectangle : " << r1.getPerimeter() << " units\n";

	return 0;
}
