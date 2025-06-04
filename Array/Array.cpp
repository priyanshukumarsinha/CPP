#include <iostream>
using namespace std;

class Array {
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array(int sz = 10) {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array() {
        delete[] A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    void InsertSort(int x);
    bool isSorted();
    void Rearrange();
    Array* Merge(Array &arr2);
    Array* Union(Array &arr2);
    Array* Inter(Array &arr2);
    Array* Diff(Array &arr2);
};

void Array::Display() {
    cout << "\nElements are: ";
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Array::Append(int x) {
    if (length < size)
        A[length++] = x;
}

void Array::Insert(int index, int x) {
    if (index >= 0 && index <= length) {
        for (int i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}

int Array::Delete(int index) {
    if (index >= 0 && index < length) {
        int x = A[index];
        for (int i = index; i < length - 1; i++)
            A[i] = A[i + 1];
        length--;
        return x;
    }
    return -1;
}

void Array::swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::LinearSearch(int key) {
    for (int i = 0; i < length; i++) {
        if (A[i] == key) {
            swap(&A[i], &A[0]); // Move-to-front
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key) {
    int low = 0, high = length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == key)
            return mid;
        else if (key < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Array::Get(int index) {
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void Array::Set(int index, int x) {
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array::Max() {
    int max = A[0];
    for (int i = 1; i < length; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}

int Array::Min() {
    int min = A[0];
    for (int i = 1; i < length; i++)
        if (A[i] < min)
            min = A[i];
    return min;
}

int Array::Sum() {
    int sum = 0;
    for (int i = 0; i < length; i++)
        sum += A[i];
    return sum;
}

float Array::Avg() {
    return length ? (float)Sum() / length : 0;
}

void Array::Reverse() {
    int *B = new int[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (int i = 0; i < length; i++)
        A[i] = B[i];
    delete[] B;
}

void Array::Reverse2() {
    for (int i = 0, j = length - 1; i < j; i++, j--)
        swap(&A[i], &A[j]);
}

void Array::InsertSort(int x) {
    if (length == size) return;
    int i = length - 1;
    while (i >= 0 && A[i] > x) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}

bool Array::isSorted() {
    for (int i = 0; i < length - 1; i++)
        if (A[i] > A[i + 1])
            return false;
    return true;
}

void Array::Rearrange() {
    int i = 0, j = length - 1;
    while (i < j) {
        while (A[i] < 0) i++;
        while (A[j] >= 0) j--;
        if (i < j) swap(&A[i], &A[j]);
    }
}

Array* Array::Merge(Array &arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    while (i < length)
        arr3->A[k++] = A[i++];
    while (j < arr2.length)
        arr3->A[k++] = arr2.A[j++];
    arr3->length = k;
    return arr3;
}

Array* Array::Union(Array &arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++];
        else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    while (i < length)
        arr3->A[k++] = A[i++];
    while (j < arr2.length)
        arr3->A[k++] = arr2.A[j++];
    arr3->length = k;
    return arr3;
}

Array* Array::Inter(Array &arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}

Array* Array::Diff(Array &arr2) {
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);

    while (i < length && j < arr2.length) {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    while (i < length)
        arr3->A[k++] = A[i++];
    arr3->length = k;
    return arr3;
}

int main() {
    int sz, choice, x, index;

    cout << "Enter size of array: ";
    cin >> sz;

    Array *arr1 = new Array(sz);

    do {
        cout << "\nMenu\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Sum\n5. Display\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element and index: ";
                cin >> x >> index;
                arr1->Insert(index, x);
                break;

            case 2:
                cout << "Enter index: ";
                cin >> index;
                x = arr1->Delete(index);
                cout << "Deleted Element: " << x << endl;
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> x;
                index = arr1->LinearSearch(x);
                cout << "Element index: " << index << endl;
                break;

            case 4:
                cout << "Sum is: " << arr1->Sum() << endl;
                break;

            case 5:
                arr1->Display();
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    delete arr1;
    return 0;
}
