#include<iostream>
using namespace std;

class Complex
{
	private:
		int a,b;
	public:
		void setData(int x, int y)
		{ a=x; b=y; }
		void showData()
		{ cout << "\na = " << a << "\nb = " << b << endl; }
		friend istream& operator>>(istream&, Complex&); 
		//cout and cin are defined in ostream and instream Classes 
		//but we cannot make an object of these classes 		      
		//therefore we will use reference of that
		friend ostream& operator<<(ostream&, Complex);
};

istream& operator>>(istream &din, Complex &c)
{
	cin >> c.a >> c.b;
	return din; //return so that we can use cascading i.e cin >> c1 >> c2;
}

ostream& operator<<(ostream &dout, Complex c)
{
	cout << "\na = " << c.a << "\nb = " << c.b << endl;
	return dout;
}

int main()
{
	Complex c1;
	cout << "Enter a complex Number : ";
	cin >> c1; //for this to work we will have to overload >> operator to work with Complex class
	cout << c1;
	return 0;
}
