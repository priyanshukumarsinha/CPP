#include<iostream>
#include<bits/stdc++.h>
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

int get(struct Array *arr, int index){
    if(index>=0 && index <=arr->length){
        return arr->A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x){
    if(index>=0 && index<=arr->size){
        arr->A[index] = x;
    }
}

int max(struct Array *arr){
    int max = INT_MIN;
    for(int i=0; i<arr->length; i++){
        if(max < arr->A[i]){
            max = arr->A[i];
        }
    }
    return max;
}

int min(struct Array *arr){
    int min = INT_MAX;
    for(int i=0; i<arr->length; i++){
        if(min > arr->A[i]){
            min = arr->A[i];
        }
    }
    return min;
}

int sum(struct Array *arr){
    int sum=0;
    for(int i=0; i<arr->length; i++){
        sum += arr->A[i];
    }
    return sum;
}

int avg(struct Array *arr){
    return (float)sum(arr)/arr->length;
}

void reverse(struct Array *arr){
    int *B = (int *)malloc(sizeof(int) * arr->length);
    int i, j;

    for(i=arr->length-1, j=0; i<=0; i--, j++){
        B[j] = A[i];
    }

    for(i=0; i<arr->length; i++){
        A[i] = B[i];
    }
}


int main()
{
 struct Array arr1={{2,23,14,5,6,9,8,12},10,8};
 cout << get(&arr1, 3) << endl;
 Set(&arr1,3,52);
 Display(arr1);
 cout << sum(&arr1) <<endl<< min(&arr1) <<endl<< max(&arr1)<<endl << avg(&arr1)<<endl;
 return 0;
}