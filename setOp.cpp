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

struct Array * Merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k] = arr1->A[i];
            i++;
        }
        else{
            arr3->A[k] = arr2->A[j];
            j++;
        }
        k++;
    }

    for(; i<arr1->length; i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }

    for(; j<arr2->length; j++){
        arr3->A[k] = arr2->A[j];
        k++;
    }

    arr3->length = arr2->length + arr1->length;
    arr3->size = 10;

    return arr3;
}

struct Array * Union(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k] = arr1->A[i];
            i++;
        }
        else if(arr1->A[i]>arr2->A[j]){
            arr3->A[k] = arr2->A[j];
            j++;
        }
        else{
            arr3->A[k] = arr1->A[i];
            i++;
            j++;
        }
        k++;
    }

    for(; i<arr1->length; i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }

    for(; j<arr2->length; j++){
        arr3->A[k] = arr2->A[j];
        k++;
    }

    arr3->length = arr2->length + arr1->length;
    arr3->size = 10;

    return arr3;

}

struct Array * Intersection(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            i++;
        }
        else if(arr1->A[i]>arr2->A[j]){
            j++;
        }
        else{
            arr3->A[k] = arr1->A[i];
            i++;
            j++;
            k++;
        }
    }

    arr3->length = ++k;
    arr3->size = 10;

    return arr3;

}

struct Array * Difference(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else if(arr1->A[i]>arr2->A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }

    for(; i<arr1->length; i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;

}

int main()
{
 struct Array arr1={{2,9,21,28,35},10,5};
 struct Array arr2={{2,3,16,18,28},10,5};
 struct Array *arr3; 
 arr3=Difference(&arr1,&arr2);
 Display(*arr3);

 return 0;
}