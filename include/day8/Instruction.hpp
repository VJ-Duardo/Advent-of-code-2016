#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP


class Instruction {
  public:
    Instruction(int na, int nb);
    virtual void doInstruction(std::vector<std::vector<char>> &screen)=0;
    virtual ~Instruction();

  protected:
    int a, b;
};


class Rect : public Instruction{
  public:
    Rect(int na, int nb);
    void doInstruction(std::vector<std::vector<char>> &screen);
};

class Rotate: public Instruction{
  public:
    Rotate(int na, int nb, bool nIsRow);
    void doInstruction(std::vector<std::vector<char>> &screen);
  
  private:
    bool isRow;
};


#endif