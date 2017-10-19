#ifndef SUDOKUNONOMINO_HPP
#define SUDOKUNONOMINO_HPP

class SudokuNonomino : public virtual SudokuElement
{
  public:
    SudokuNonomino(SudokuBoard, Shape, int); //SudokuBoard, row#, NumberSpace
};

#endif //SUDOKUNONOMINO_HPP