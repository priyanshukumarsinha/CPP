#include<iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter a Number : ";
	cin >> n;

	int i,s=1;
	for(i=1;i<=n;i++)
		s*=i;

	cout << "Factorial of " << n << " is " << s << endl;

	return 0;
}
