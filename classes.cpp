#include<iostream>
using namespace std;

class Complex
{
	private:
		int a,b;
	public:
		void set_data(int x, int y)
		{
			a=x;
			b=y;
		}

		void show_data()
		{
			cout<<"a = " << a << "\nb = " << b << endl;
		}

		Complex add(Complex c)
		{
			Complex temp;
			temp.a = a+c.a;
			temp.b = b+c.b;

			return temp;
		}

};

int main()
{
	Complex c1,c2,c3;

	c1.set_data(3,4);
	c2.set_data(5,4);
	
	c3 = c1.add(c2); //add value of c1 to c2 and assign it to c3

	c3.show_data();

	return 0;
}
