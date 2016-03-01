#include <iostream>

using namespace std;


void iterate(int d, int n, int size[], int res[]){
    if(d >= n){
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
    int res[4];
    iterate(0,4,size,res);
}
