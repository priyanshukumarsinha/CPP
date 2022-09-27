#include<iostream>
using namespace std;

class Time
{
	private:
		int HR, MIN, SEC; //member variables
	public:
		void setTime();
		void showTime();
		void normalize();
};

void Time:: setTime()
{
	cout << "Enter the time (h m s) : ";
	cin >> HR >> MIN >> SEC;
	normalize();
}

void Time:: showTime()
{
	cout << "Time : " << HR << ":" << MIN << ":" << SEC << endl;
}

void Time:: normalize()
{
	if(SEC>=60)
	{
		SEC = SEC-60;
		MIN = MIN + 1;
	}
	if(MIN>=60)
	{
		MIN = MIN - 60;
		HR = HR + 1;
	}
	
	while(1)
		if(HR>=24)
			HR = HR - 24;
		else
			break;
}


int main()
{
	Time t;
	t.setTime();
	t.showTime();

	return 0;
}
