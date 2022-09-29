#include<iostream>
using namespace std;

class Integer
{
        private:
                int x;
        public:
                void setData(int a)
                { x=a; }
                void showData()
                { cout << "x = " << x << endl; }
		Integer operator++()//preincement
		{ 
			Integer i;
			i.x = ++x;
			return i;
		}
		Integer operator++(int) //this argument will not take any input but it is necessary for differentiation 
		{
			Integer i;
			i.x = x++;
			return i;
		}
};

int main()
{
        Integer i1,i2;
        i1.setData(3);
        i1.showData(); //3
        i2 = i1++; //i1.operator++()
        i1.showData(); //4
        i2.showData(); //3
        return 0;
}

