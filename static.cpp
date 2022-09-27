#include<iostream>
using namespace std;

class Account
{
	private:
		int balance; // Instance Member Variable
		static float roi; // Static Memer Variable / Class Variable declaration

	public:
		void setBalance(int b)
		{ balance = b; }
};

float Account:: roi = 3.5f; //Membership label

int main()
{
	//even if there is no object of class Account roi is still defined
	
	Account a1,a2;
	//both of these objects can access roi and its value will be same (3.5) for both of them
	
	return 0;
}

