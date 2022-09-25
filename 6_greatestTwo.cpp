#include<iostream>
using namespace std;

int main()
{
	int n1,n2;
	cout<< "Enter two Numbers : ";
	cin>>n1>>n2;

	if(n1>n2)
		cout<<n1<< " is greater than " << n2;
	else
		cout<<n2<<" is greater than " << n1;

	cout << endl;
	return 0;
}
