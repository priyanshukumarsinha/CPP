#include<iostream>
using namespace std;

#define PI 3.14

float areaOfCircle(int);

int main()
{
	int r;
	cout << "Enter radius of Circle : ";
	cin >> r;

	float a = areaOfCircle(r);
	cout << "Area : " << a << " units square \n";

	return 0;
}

float areaOfCircle(int R)
{
	return PI*R*R;
}
