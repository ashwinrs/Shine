#include <iostream>

using namespace std;

void iterate(int d, int n, int size[], int res[]){
    //check exit condition
    if(d >= n){
        // Print out the result array
        for(int i = 0;i<n;++i){
            cout << res[i] << " ";
        }
        cout << endl;
    }else{
        for(int i = 0; i < size[d]; ++i){
            res[d] = i;
            iterate(d+1,n,size,res);
        }
    }
}

int main(){
    int size[] = {2,4,2,3};
    int size_of_arr = 4;
    int res[size_of_arr];
    iterate(0,size_of_arr,size,res);
}
