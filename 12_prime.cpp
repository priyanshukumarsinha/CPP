#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter a Number : ";
	cin >> n;

	int i;
	for(i=2; i<n; i++)
		if(n%i==0)
			break;

	if(i==n)
		cout << n << " is a Prime Number" << endl;
	else
		cout << n<<" is Not a Prime Number" << endl;

	return 0;

}
