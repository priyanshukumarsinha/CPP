#include<iostream>
using namespace std;

struct Array
{
 int A[10];
 int size;
 int length;
};

void Display(struct Array arr){
    for(auto it: arr.A){
        cout << it << " ";
    }
    cout << endl;
}

void swap(int *x, int *y){
    int *temp = x;
    x=y;
    y = temp;
}

int LinearSearch(struct Array *arr, int key){
    int i=0;
    for(i=0; i<arr->length; i++){
        if(key == arr->A[i]){
            return i;
        }
    }
    return -1;
}


int main()
{
 struct Array arr1={{2,23,14,5,6,9,8,12},10,8};
 printf("%d\n",LinearSearch(&arr1,14));
 Display(arr1);
 return 0;
}