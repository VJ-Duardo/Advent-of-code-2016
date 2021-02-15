#include <iostream>
#include <string>
#include <vector>

#include "day9/format.hpp"
#include "utils/utils.hpp"



int main(){
  std::string input = utils::getFileContent("src/day9/file.txt");

  std::cout << getDecompressedLength(input) << std::endl;
  std::cout << getRealDecompressedLength(input) << std::endl;

  return 0;
}



long int getRealDecompressedLength(const std::string input){
  if (input.find('(') == std::string::npos){
    return input.length();
  }

  long int localCount = 0;
  for (size_t i=0; i < input.length(); i++){
    if (input[i] != '('){
      localCount++;
    }else {
      std::string marker = input.substr(i+1, input.find(')', i)-i-1);
      int x = marker.find('x');
      int a = std::stoi(marker.substr(0, x));
      int b = std::stoi(marker.substr(x+1));
      localCount += b*getRealDecompressedLength(input.substr(i+marker.length()+2, a));
      i += marker.length()+1 +a;
    }
  }
  return localCount;
}


int getDecompressedLength(const std::string &input){
  int c = 0;
  for (size_t i=0; i < input.length(); i++){
    if (input[i] != '('){
      c++;
    } else{
      std::string marker = input.substr(i+1, input.find(')', i)-i-1);
      int x = marker.find('x');
      int a = std::stoi(marker.substr(0, x));
      int b = std::stoi(marker.substr(x+1));
      c += a*b;
      i += marker.length()+1 + a;
    }
  }
  return c;
}