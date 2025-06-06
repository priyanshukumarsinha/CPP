#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Array
{
 int *A;
 int size;
 int length;
};

void Display(struct Array arr){
    for(int i=0; i<arr.length; i++){
        cout << arr.A[i] << " ";
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
    
    for(i=arr->length-1, j=0; i>=0; i--, j++){
        B[j] = arr->A[i];
    }

    for(i=0; i<arr->length; i++){
        arr->A[i] = B[i];
    }
}

void reverse2(struct Array *arr){
    int i,j;

    for(i=0, j=arr->length-1; i<j; i++,j--){
        swap(arr->A[i], arr->A[j]);
    }
}

void leftShift(struct Array *arr){
    int temp = arr->A[0];
    for(int i=1; i<arr->length; i++){
        arr->A[i-1] = arr->A[i];
    }
}

void leftRotate(struct Array *arr){
    int temp = arr->A[0];
    for(int i=1; i<arr->length; i++){
        arr->A[i-1] = arr->A[i];
    }
    arr->A[arr->length-1] = temp;
}

void rightShift(struct Array *arr){
    int temp = arr->A[0];
    for(int i=1; i<arr->length; i++){
        arr->A[i-1] = arr->A[i];
    }
}

void rightRotate(struct Array *arr){
    int temp = arr->A[0];
    for(int i=1; i<arr->length; i++){
        arr->A[i-1] = arr->A[i];
    }
    arr->A[arr->length-1] = temp;
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

void append(struct Array *arr, int x){
    if(arr->length < arr-> size){
        arr->A[arr->length] = x;
        arr->length++;
    }
    else
        cout << "Array Overflow" << endl;
}

void insert(struct Array *arr, int index, int x){
    if(arr->length==arr->size){
        cout << "Array Overflow" << endl;
        return;
    }
    if(index>=0 && index<=arr->length){
        for(int i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] =x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index){
    int deleted_item=0;
    if(arr->length>0){
        if(index>=0 && index<arr->length){
            deleted_item = arr->A[index];
            for(int i=index; i<arr->length; i++){
                arr->A[i] = arr->A[i+1];
            }
            arr->length--;
        }
    }
    else
        cout << "Array Underflow";

    return deleted_item;
}

void insertSort(struct Array *arr, int index, int x){
    int i=arr->length -1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1] =arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

bool isSorted(struct Array *arr){
    for(int i=0; i<arr->length-1; i++){
        if(arr->A[i]<arr->A[i+1]){
            return false;
        }
    }
    return true;
}

void rearrange(struct Array *arr){
    int i,j;
    i=0;
    j= arr->length-1;

    while(i<j){
        while(arr->A[i]>0)i++;
        while(arr->A[j]<0)j--;
        if(i<j) swap(&arr->A[i], &arr->A[j]);
    }

}

int main()
{
 struct Array arr1;
 int ch;
 int x, index;

 printf("Enter Size of Array: ");
 cin >> arr1.size;
 arr1.A=(int *)malloc(arr1.size * sizeof(int));
 arr1.length = 0;

 do{
    cout<<"-----------------MENU-----------------" << endl;
    cout<<"1. Insert" << endl;
    cout<<"2. Delete" << endl;
    cout<<"3. Search" << endl;
    cout<<"4. Sum" << endl;
    cout<<"5. Display" << endl;
    cout<<"6. Exit" << endl;

    cout << "Enter your Choice: ";
    cin >> ch;

    switch(ch){
        case 1:
            cout << "Enter element and index: ";
            cin >> x >> index;
            insert(&arr1, index, x);
            break;
        case 2:
            cout << "Enter index: ";
            cin >> index;
            x = Delete(&arr1, index);
            cout << "Deleted element : " << x << endl;
            break;
        case 3:
            cout << "Enter an Element to search: ";
            cin >> x;
            index = LinearSearch(&arr1, x);
            if(index == -1){
                cout << "Could not find the element" << endl;
            }
            else
                cout << "Index: " << index << endl;
            break;
        case 4:
            x = sum(&arr1);
            cout << "Sum = " << x << endl;
            break;
        case 5: 
            Display(arr1);
            break;
    }
 }
 while(ch<6);

 return 0;
}

// int main(){
//     struct Array arr1;
//     arr1.size = 10;
//     arr1.A = (int *)malloc()
//     insert(&arr1, 0, 1);
//     Display(arr1);

//     return 0;
// }