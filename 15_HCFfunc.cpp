#include <iostream>
using namespace std;

int HCF(int, int);

int main()
{
	int n1,n2;
	cout << "Enter two Numbers : ";
	cin >> n1 >> n2;
	
	int h = HCF(n1,n2);
	cout << "HCF of " << n1 << " and " << n2 << " is " << h << endl;

	return 0;
}

int HCF(int x, int y)
{
	int i,H=1;
	int greater_number = y>x?y:x;

	if(x==1 || y==1)
		return 1;
	
	for(i=1;i<=greater_number;i++)
		if(x%i==0 && y%i==0)
			H=i;	
	return H;
}
