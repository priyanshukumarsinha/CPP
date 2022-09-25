#include<iostream>
using namespace std;

int main()
{
	int y;
	cout<< "Enter an Year : ";
	cin >> y;

	if(!y%100)
	{
		if(!y%4)
			cout<< y<< " is a leap Year";
		else
			cout<<"Not a leap Year";
	}
	else if(!y%4)
		cout<< y<< " is a leap Year";
	else
		cout<<"Not a leap Year";

	cout<<endl;	

	return 0;
}
