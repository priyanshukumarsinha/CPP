#include <iostream>
using namespace std;

int LCM(int, int);

int main()
{
	int n1,n2;
	cout << "Enter two Numbers : ";
	cin >> n1 >> n2;

	int l = LCM(n1,n2);

	cout << "LCM of " << n1 << " and " << n2 << " is " << l << endl;

	return 0;
}

int LCM(int x, int y)
{
	int i;
	for(i=1;i<=x*y;i++)
		if((x*i)%y == 0)
			return x*i;
	return x*y;
}
