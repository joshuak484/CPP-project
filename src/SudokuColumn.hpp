#ifndef SUDOKUCOLUMN_HPP
#define SUDOKUCOLUMN_HPP

class SudokuColumn : public virtual SudokuElement
{
  public:
    SudokuColumn(SudokuBoard, int, int); //SudokuBoard, col#, NumberSpace
};

#endif //SUDOKUCOLUMN_HPP