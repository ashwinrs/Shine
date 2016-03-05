/* write all subsets of a set*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printVector(vector<int> v){
    if (v.size() == 0) return;

    for(size_t i = 0 ; i < v.size(); ++i){
        cout << v[i] << " ";
    }
}

void printVectorOfVector(vector<vector<int> > v){
    if (v.size() == 0) return;

    for(size_t i = 0;i<v.size();++i){
        printVector(v[i]);
        cout << endl;
    }
}

vector<int> getVectorFromNumber(vector<int> v, int n){
    vector<int> result;
    int i = 0;
    while(n){
        if(n & 1){
            result.push_back(v[i]);
        }
        i++;
        n = n >> 1;
    }
    return result;
}


vector<vector<int> > getSubsets(vector<int> v){
    vector<vector<int> > result;

    if (v.size() == 0) return result;

    size_t range = pow(2,v.size());

    for(size_t i = 0 ; i < range; ++i ){
        vector<int> temp = getVectorFromNumber(v , i);
        result.push_back(temp);
    }

    return result;
}

int main(){
    int arr[] = {1,2,3};
    vector<int> v(arr,arr+(sizeof(arr)/sizeof(arr[0])));

    vector<vector<int> > result = getSubsets(v);
    printVectorOfVector(result);
}
