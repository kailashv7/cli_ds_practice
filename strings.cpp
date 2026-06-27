#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

int main(){
std::cout << "Kai" << std::endl;
const char *s = "Venthan";
printf("%s", s);

std::fstream inputFile("text.txt");

if(inputFile.is_open()){
    std::cerr << "Error could not open the File" << std::endl;
    return 1;    
}

std::string line;

while (std::getline(inputFile, line)){
    std::cout << line << '\n';
}

inputFile.close();

return 0;
}