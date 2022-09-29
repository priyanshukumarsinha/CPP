#include <iostream>
using namespace std;

class Matrix
{
	private:
		int a[3][3];
	public:
		int& operator()(int i, int j) //this function will return a refernce which will help us to insert data in this array
		{ return (a[i][j]);} //this will not return the value stored in that location but return the refernce of that location
		void printMatrix()
		{
			int i,j;
			for(i=0; i<3; i++)
			{
				for(j=0; j<3; j++)
				{
					cout << " " << a[i][j] << " ";
				}
				cout << endl;
			}
		}
};

int main()
{
	Matrix m1;
	m1(0,0) = 5;
	m1(0,1) = 8;
	m1(0,2) = 1;
	m1(1,0) = 6;
	m1(1,1) = 9;
	m1(1,2) = 4;
	m1(2,0) = 7;
	m1(2,1) = 1;
	m1(2,2) = 0;
	m1.printMatrix();
	return 0;
}
