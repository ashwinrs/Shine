/*
Find the max product of three integers in an array

algorithm-
1. Sort the array
2. If there are less than two -ve integers, the product of the first three integers is the max
3. If there are two or more -ve integers then compare the product between the two minimum intergers and one max int with three max int. The larger one is the answer

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int getMaxProduct(vector<int> input){
    long int result= 1;

    if(input.size() < 3){
        return 0;
    }

    sort(input.begin(),input.end());

    for(size_t i = 0 ; i < input.size(); ++i){
        cout << input[i] << " ";
    }
    cout << endl;

    //count the number of -ve intergers
    int count_negative = 0;
    for(size_t i = 0 ; i < input.size(); ++i){
        if(input[i] < 0){
            count_negative++;
        }
    }

    long int negative_result = 1;
    if(count_negative > 1){
        negative_result = input[0] * input[1] * input[input.size()-1];
    }

    //product of max 3 integers
    result = input[input.size()-1]*input[input.size()-2]*input[input.size()-3];
    return result>negative_result?result:negative_result;
}
int main(){
    int arr[] = {-10,-4,4,-2,5,6,7,2,3};
    vector<int> v(arr, arr+(sizeof(arr)/sizeof(arr[0])));

    cout <<  getMaxProduct(v) << endl;
}
