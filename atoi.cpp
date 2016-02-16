/*
https://leetcode.com/problems/string-to-integer-atoi/
Implement atoi to convert a string to an integer.

Requirements-
1. Handle negative numbers by taking an optional '+' or '-' sign
2. Handle leading spaces
3. If the conversion is out of range INT_MAX or INT_MIN is returned
Function prototype=
int atoi(string input)
*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
   int myAtoi(string str) {
      long result = 0;
      bool isNegative = false;
      size_t i = 0;

      //handle leading spaces
      while(str[i]==' '){
          i++;
      }

      //check if the string is negative
      if(str[i] == '-') {
          isNegative = true;
          i++;
      }

      //crux
      for (; i < str.size(); i++) {
         if (str[i] >= '0' && str[i] <= '9') {
            result = (str[i] - '0') + (result * 10);
         }
      }

      //handle sign
      if(isNegative){
          result = result * -1;
      }

      //handle extremeties
      if(result > INT_MAX) return INT_MAX;
      if(result < INT_MIN) return INT_MIN;

      return result;
   }
};

int main() {
   Solution s;
   string i = "123468853235689853";
   cout << s.myAtoi(i) << endl;
   cout << INT_MAX << " " << INT_MIN << endl;
}
