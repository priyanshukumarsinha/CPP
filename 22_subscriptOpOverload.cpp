#include<iostream>
using namespace std;

class Array
{
	private:
		int a[10];
	public:
		void insertData(int index, int value)
		{ a[index] = value; }
		int operator[](int index)
		{ return a[index]; }
};

int main()
{
	Array a1;
	
	int i;
	for(i=0; i<10; i++)
	{
		a1.insertData(i,10*(i+1));
	}
        for(i=0; i<10; i++)
        {
                cout << a1[i] << endl;
        }

	//cout << a1[2]; //a1.operator[](2)
	return 0;
}
