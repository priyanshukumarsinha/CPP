#include<iostream>
using namespace std;

#define PI 3.14

float volume(int);
int volume(int, int, int);

int main()
{
	cout << "1. Calculate Volume of Sphere" << "\n2.Calculate Volume of Cuboid\n";
	
	int choice;
	cin >> choice;

	int r;
	int l,b,h;
	int v;
	float V;
	
	switch(choice)
	{
		case 1:
			;
			cout << "Enter radius of Sphere : ";
			cin >> r;
			V = volume(r);
			cout << "Volume : " << V << " cubic units\n";
			break;
		case 2:
			;
			cout << "Enter Length, Bredth and Height of Cuboid : ";
			cin >> l >> b >>h;
			v = volume(l,b,h);
			cout << "Volume : " << v << " cubic units\n";
			break;
		default: 
			cout << "Invalid Input!";
			break;
	}
	

	return 0;
}

float volume(int R)
{
	return (4*PI*R*R*R)/3;
}

int volume(int L, int B, int H)
{
	return L*B*H;
}
