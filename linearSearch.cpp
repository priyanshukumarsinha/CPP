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
            swap(arr->A[i], arr->A[0]);
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Array *arr, int key){
    int l, h, mid;
    l=0;
    h=arr->length -1;
    while(l<=h){
        mid = (l+h)/2;
        if(arr->A[mid] == key){
            return mid;
        }
        else if(arr->A[mid] < key){
            h = mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}

int RbinarySearch(struct Array *arr,int l, int h, int key){
    int mid=0;
    if(l<=h){
        mid = (l+h)/2;
        if(key == arr->A[mid]){
            return mid;
        }
        else if(arr->A[mid] < key){
            return RbinarySearch(arr, l, mid-1, key);
        }
        else
            return RbinarySearch(arr, mid+1, h, key);
    }
    return -1;
}


int main()
{
 struct Array arr1={{2,23,14,5,6,9,8,12},10,8};
 printf("%d\n",RbinarySearch(&arr1,0, arr1.length-1 ,14));
 Display(arr1);
 return 0;
}