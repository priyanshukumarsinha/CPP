#include<iostream>
using namespace std;

#define PI 3.14

float area(int);
int area(int, int);

int main()
{
	cout << "1. Calculate Area of Circle" << "\n2.Calculate Area of Rectangle\n";
	
	int choice;
	cin >> choice;

	int r;
	int l,b;
	int a;
	float A;
	
	switch(choice)
	{
		case 1:
			;
			cout << "Enter radius of Circle : ";
			cin >> r;
			A = area(r);
			cout << "Area : " << A << "units square\n";
			break;
		case 2:
			;
			cout << "Enter Length and Bredth of Rectangle: ";
			cin >> l >> b;
			a = area(l,b);
			cout << "Area : " << a << "units squre\n";
			break;
		default: 
			cout << "Invalid Input!";
			break;
	}
	

	return 0;
}

float area(int R)
{
	return PI * R*R;
}

int area(int L, int B)
{
	return L*B;
}
