#include<iostream>
using namespace std;

int nextPrime(int);
int isPrime(int);

int main()
{
	int n;
	cout << "Enter a Number : ";
	cin >> n;

	int p = nextPrime(n);
	cout << "Next Prime is : " << p << endl;

	return 0;
}

int nextPrime(int x)
{
	int i;
	for(i=x+1;!isPrime(i);i++);
	return i;
}


int isPrime(int y)
{
	int i;
	for(i=2;i<y;i++)
		if(y%i==0)
			return 0;
	return 1;
}
