/*
The Longest Increasing Subsequence problem is to find the longest increasing subsequence of a given sequence

Link - https://www.codechef.com/wiki/tutorial-dynamic-programming
*/

#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int> arr) {
   vector<int> LS(arr.size(),1);
   int max = 0;

   for (size_t i = 0; i < arr.size(); ++i) {
      for (size_t j = 0; j < i; ++j) {
         if (arr[i] > arr[j] && LS[i] <= LS[j]) {
            LS[i] = LS[j] + 1;
         }
      }
      if (LS[i] > max) {
         max = LS[i];
      }

      //print the data
      for(int i = 0 ;i< arr.size();++i){
          cout << LS[i] << " ";
      }
      cout << endl;
   }

   return max;
}

int main() {
   int arr[] = { 5,1,6,2,4,3,6 };
   vector<int> v(arr, arr + (sizeof(arr) / sizeof(arr[0])));

   cout << LIS(v) << endl;
}
