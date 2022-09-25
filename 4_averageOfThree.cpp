#include <iostream>

int main()
{
	int n1, n2, n3;
	std:: cout << "Enter three Numbers : ";
	std:: cin >> n1>>n2>>n3;
	float avg = (n1+n2+n3)/3;
	std:: cout << "Average of " << n1 <<", " << n2 <<" and " << n3 << " is " << avg << std:: endl;

	return 0;
}
