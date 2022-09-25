#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter a Number: ";
	cin >> n;

	int i;
	int a=1;
	cout << a  << " ";

	int b=1;
	cout << b << " ";

	int c=a;
	for(i=1; i<=n-2; i++)
	{
		cout << a+b << " ";
		a=b;
		b=c+b;
	}

	cout << endl;

	return 0;
}
