#ifndef AUTHENTICATION_HPP
#define AUTHENTICATION_HPP


#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 6
#define LIT '#'
#define OFF '.'

std::vector<Instruction*> getInstructions(const std::vector<std::string> &lines);
int getLitPixels(const std::vector<Instruction*> &instructions, std::vector<std::vector<char>> &screen);
void printScreen(const std::vector<std::vector<char>> &screen);


#endif