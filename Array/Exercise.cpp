#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int missing_element(int * A){
    int diff = A[0];
    int n=11;
    for(int i=0; i<n; i++){
        if(A[i]-i != diff){
            return i+diff;
        }
    }
    return -1;
}

void multiple_missing(int *A){
    int diff = A[0];
    int n=11;
    for (int i=0; i<n; i++){
        if(A[i]-i != diff){
            while(diff < A[i]-i){
                cout << i+diff << " ";
                diff++;
            }
        }
    }
    cout << endl;
}

int min(int *A){
    int m= INT_MAX;
    int n=11;
    for(int i=0; i<n; i++){
        if(A[i]< m){
            m = A[i];
        }
    }
    return m;
}

int max(int *A){
    int m= INT_MIN;
    int n =11;
    for(int i=0; i<n; i++){
        if(A[i]> m){
            m = A[i];
        }
    }
    return m;
}

void missing_hashing(int*A){
    int l = min(A);
    int h = max(A);

    int *H = (int *) malloc(sizeof(int) * (h));
    int n = 11;
    for(int i=0; i<n; i++){
        H[A[i]]++;
    }
    for(int i=l; i<=h; i++){
        if(H[i]<1){
            cout << i << " ";
        }
    }
    cout << endl;

}

void duplicates(int *A){
    int lastduplicate = -1;
    int n= 11;
    for(int i=0; i<n-1; i++){
        if(A[i]==A[i+1] && A[i]!=lastduplicate){
            cout << A[i] << " ";
            lastduplicate = A[i];
        }
    }
    cout << endl;
}

void count_dupli(int *A){
    int n=11;
    for(int i=0; i<n-1; i++){
        if(A[i]==A[i+1]){
            int j=i+1;
            while(A[j] == A[j+1]){
                j++;
            }
            cout << A[i] << " appeared " << j-i+1 << " times "  << endl;
            i=j;
        }
    }
}

void count_dupli_unsorted(int*A){
    int n=11;
    for(int i=0; i<n; i++){
        int count = 1;
        if(A[i]!=-1){
            for(int j=i+1; j<n; j++){
                if(A[i] == A[j]){
                    count++;
                    A[j] = -1;
                }
            }
            if(count >1)
                cout << A[i] << " appeared " << count << " times "  << endl;
        }
    }
}

void twoSum(int *A, int k){
    int n = 11;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n;j++){
            if(A[i] + A[j] == k){
                cout << A[i] << " + " << A[j] << " = " << k << endl;
            }
        }
    }
}

void twoSumHash(int *A, int k){
    int n=11;
    int l = min(A);
    int h = max(A);

    int *H = (int *) malloc(sizeof(int) * (h));

    for(int i=0; i<n; i++){
        if(H[k-A[i]] != 0){
            cout << A[i] << " + " << k-A[i] << " = " << k << endl;
        }
        H[A[i]]++;
    }

}

void twoSum3(int *A, int k){
    int n=11;
    int i=0, j=n-1;
    while(i<j){
        if(A[i] + A[j] == k){
            cout << A[i] << " + " << A[j] << " = " << k << endl;
            i++;
            j--;
        }
        else if(A[i]+A[j]>k){
            j--;
        }
        else {
            i++;
        }
    }
}

void min_max(int*A){
    int min_num, max_num;
    min_num=max_num=A[0];
    int n=11;
    for(int i=0; i<n; i++){
        if(A[i]<min_num){
        min_num = A[i];
        }
        else if(A[i]>max_num){
            max_num = A[i];
        }
    }
    cout << "Max Number : " << max_num << endl;
    cout << "Min Number : " << min_num << endl;

}

int main(){
    int A[] = {6,7,8,9,10,11,13,14,15,16,17};
    int B[] = {6,7,8,9,11,12,15,16,17,18,19};
    int C[] = {3,6,8,8,10,12,15,15,15,20,21};
    int D[] = {6,3,8,10,16,7,5,2,9,14,15};
    int E[] = {1,3,4,5,6,8,9,10,12,14,15};
    // int ele = missing_element(A);
    // cout << ele <<endl;
    // multiple_missing(B);
    // missing_hashing(B);
    // duplicates(C);
    // count_dupli(C);
    // count_dupli_unsorted(C);
    // twoSum(D, 10);
    // twoSumHash(D, 10);
    // twoSum3(E, 10);
    min_max(E);

    return 0;

}