#ifndef SUDOKU_HPP
#define SUDOKU_HPP

class Sudoku
{
  private:
    int numberspace;
    SudokuElement** rules;
    SudokuBoard board;
  public:
    Sudoku(int = 9, SudokuElement** = NULL);
};

#endif //SUDOKU_HPP