// Given a string representation of a binary,
// add two strings together and return a string result

#include <string>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>

std::string add_binary(std::string str1, std::string str2){
     int carry = 0;
     int str1length = str1.length();
     int str2length = str2.length();
     std::string outstring = "";

     while(str1length > 0 || str2length > 0){
         int sum = carry;

         if(str1length > 0){ 
             sum += str1[--str1length] - '0';
         }

         if(str2length > 0){ 
             sum += str2[--str2length] - '0';
         }

         carry = sum/2;
         outstring += ((sum % 2) + '0');
     }

     if(carry) outstring += (carry + '0');

     std::reverse(begin(outstring), end(outstring));
     return outstring;
}

int main(){
    assert(add_binary("0", "1") == "1");
    assert(add_binary("1", "1") == "10");

}