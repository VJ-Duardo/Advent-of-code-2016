#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "day8/Instruction.hpp"
#include "day8/authentication.hpp"
#include "utils/utils.hpp"



int main(){
  std::string input = utils::getFileContent("src/day8/instructions.txt");
  std::vector<std::string> lines = utils::getSplitArray(input, "\n");

  std::vector<std::vector<char>> screen;
  for (int i=0; i < SCREEN_HEIGHT; i++){
    screen.push_back(std::vector<char>(SCREEN_WIDTH, OFF));
  }

  std::vector<Instruction*> instructions = getInstructions(lines);
  std::cout << getLitPixels(instructions, screen) << std::endl;

  printScreen(screen);

  return 0;
}




void printScreen(const std::vector<std::vector<char>> &screen){
  for (std::vector<char> vec : screen){
    for (char c : vec){
      std::cout << c;
    }
    std::cout << std::endl;
  }
}


int getLitPixels(const std::vector<Instruction*> &instructions, std::vector<std::vector<char>> &screen){
  for (size_t i=0; i < instructions.size(); i++){
    instructions[i]->doInstruction(screen);
    delete instructions[i];
  }
  int c = 0;
  for (int j=0; j < SCREEN_HEIGHT; j++){
    c += std::count_if(screen[j].begin(), screen[j].end(), [](char pixel){
      return pixel == LIT;
    });
  }
  return c;
}



std::vector<Instruction*> getInstructions(const std::vector<std::string> &lines){
  std::vector<Instruction*> instructions;
  for (size_t i =0; i< lines.size(); i++){
    std::vector<std::string> parts = utils::getSplitArray(lines[i], " xy=");
    if (parts[0] == "rect"){
      instructions.push_back(new Rect(std::stoi(parts[1]), std::stoi(parts[2])));
    } else {
      instructions.push_back(new Rotate(std::stoi(parts[2]), std::stoi(parts[4]), parts[1] == "row"));
    }
  }
  return instructions;
}