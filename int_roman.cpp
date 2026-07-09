#include <cstddef>
#include <iostream>
#include <string>


class Solution {
public:
  
   std::string intToRoman(int num){ 
      std::string factors[] = {"ones","tens","hurs","ths"};
      std::string ones[] = {"","I","II","III","IV"};
      std::string tens[] = {"","X","XI","XII","XIII","XIV"};
      std::string hnrs[] = {"","C","CI","CII","CIII","CIV"};
      std::string ths[] = {"","M","MM","MMM"};
      std::string roman; 
      int count = 1;
      std::vector<int> decimal; 
      int mod;
      int size = [&num, &count, &mod, &decimal]()->int {while (num>0){mod = num % 10; num /= 10;  count++;  decimal.push_back(mod);} return count;}();
      
      // std::cout << ths[num/1000] <<std::endl;

     for (std::size_t i = decimal.size(); i-- > 0; ){ 
     std::cout << decimal.at( i) << std::endl;
    } 
     std::cout << "size " << size << std::endl; 

     

     return roman;
   
      } 

   Solution(){

   }

   ~Solution(){
    
   }};



int main(){
   Solution solution;
   solution.intToRoman(2678); 
}