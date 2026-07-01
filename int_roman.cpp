#include <iostream>
#include <string>


class Solution {
public:
   
   std::string intToRoman(int num){ 
      std::string roman; 
      int count = 1;
      std::vector<int> decimal; 
      int mod;
      int size = [&num, &count, &mod, &decimal]()->int {while (num>1){num /= 10;  mod = num % 10;count++;  decimal.push_back(mod);} return count;}();
      


     std::cout << decimal.at( 1) << std::endl; 
     std::cout << size << std::endl; 
     return roman;
   
      } 

   Solution(){

   }

   ~Solution(){
    
   }};



int main(){
   Solution solution;
   solution.intToRoman(152678); 
}