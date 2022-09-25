#include<iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter a Number : ";
	cin >> n;
	
	int s,i;
	for(i=1;i<=n;i++)
		s+=i;

	cout << "Sum of " << n << " Natural Numbers is " << s << endl;

	return 0;
}
