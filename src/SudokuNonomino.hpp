#ifndef SUDOKUNONOMINO_HPP
#define SUDOKUNONOMINO_HPP

#include "SudokuElement.hpp"

class SudokuNonomino : public virtual SudokuElement
{
  private:
    bool** shape;
  public:
    SudokuNonomino(int**&, bool**, int); //SudokuBoard, shape of the nonomino, NumberSpace
};

#endif //SUDOKUNONOMINO_HPP