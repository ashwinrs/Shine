#include <iostream>
#include <vector>

using namespace std;

int binarySearchRotatedArray(vector<int> &A, int val_search, int l, int r){
    if(l>r) return -1;

    int mid= (l + r)/ 2;

    if (A[mid] == val_search){
        return mid;
    }

    if( A[l] <= A[mid]){
    // means the left part is sorted
        if(val_search >= A[l] && val_search <= A[mid]){
            return binarySearchRotatedArray(A,val_search,l,mid-1);
        }
        return binarySearchRotatedArray(A,val_search,mid+1,r);
    }

    //the right part is sorted
    if(val_search >= A[mid] && val_search <= A[r]){
        return binarySearchRotatedArray(A,val_search,mid+1,r);
    }
    return binarySearchRotatedArray(A,val_search,l,mid-1);

}

int binarySearchRotatedArray(vector<int> &A, int val_search){
    return binarySearchRotatedArray(A, val_search,0,A.size()-1);
}


int main(){
    int val_search = 3;
    int arr[] = {3,4,5,1,2};
    vector<int> v(arr,arr+(sizeof(arr)/sizeof(arr[0])));

    cout << endl << binarySearchRotatedArray(v,val_search);

}
