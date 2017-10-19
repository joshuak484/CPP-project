#ifndef SUDOKUROW_HPP
#define SUDOKUROW_HPP

class SudokuRow : public virtual SudokuElement
{
  public:
    SudokuRow(SudokuBoard, int, int); //SudokuBoard, row#, NumberSpace
};

#endif //SUDOKUROW_HPP