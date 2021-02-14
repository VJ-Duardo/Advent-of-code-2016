#include <iostream>
#include <string>
#include <vector>

#include "day8/Instruction.hpp"
#include "day8/authentication.hpp"



Instruction::Instruction(int na, int nb): a(na), b(nb){}
Instruction::~Instruction(){}


Rect::Rect(int na, int nb): Instruction(na, nb){}
void Rect::doInstruction(std::vector<std::vector<char>> &screen){
  for (int i=0; i < b; i++){
    for (int j=0; j < a; j++){
      screen[i][j] = LIT;
    }
  }
}

Rotate::Rotate(int na, int nb, bool nIsRow): Instruction(na, nb), isRow(nIsRow){}
void Rotate::doInstruction(std::vector<std::vector<char>> &screen){
  if (isRow){
    for (int i=0; i< b; i++){
      char c = screen[a][SCREEN_WIDTH-1];
      screen[a].pop_back();
      screen[a].insert(screen[a].begin(), c);
    }
  } else {
    for (int i=0; i < b; i++){
      char c = screen[SCREEN_HEIGHT-1][a];
      for (int j= SCREEN_HEIGHT-1; j > 0; j--){
        screen[j][a] = screen[j-1][a];
      }
      screen[0][a] = c;
    }
  }
}