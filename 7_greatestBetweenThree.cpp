#include <iostream>
using namespace std;

int main()
{
	int n1,n2,n3;
	cout << "Enter Three Numbers : ";
	cin >> n1>>n2>>n3;

	if(n1>n2 && n1>n3)
			cout<<n1<< " is the greatest number"<<endl;
	else if(n2>n3)
			cout<<n2<< " is the greatest number"<<endl;
	else		
		cout<<n3<< " is the greatest number"<<endl;
	
	return 0;
}
