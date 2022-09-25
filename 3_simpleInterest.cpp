#include<iostream>

int main()
{
	int p;
	float r,t;
	std:: cout << "Enter the Principal Amount : ";
	std:: cin >> p;
	std:: cout << "Enter the Rate of Interest (pa) : ";
	std:: cin >> r;
	std:: cout << "Enter the Time (years) : ";
	std:: cin >> t;
	int si=(p*r*t)/100;
	std:: cout << "Simple Interest = " << si << std:: endl <<"Amount after "<< t<< " years : "<< p + si << std:: endl;
	
	return 0;
}
