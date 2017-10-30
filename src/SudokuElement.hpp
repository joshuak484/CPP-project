#ifndef SUDOKUELEMENT_HPP
#define SUDOKUELEMENT_HPP

class SudokuElement
{// maybe make a pure virtual?
  protected:
    int numberspace;
    int** constituents;
  public:
    bool isValid();
};

#endif //SUDOKUELEMENT_HPP