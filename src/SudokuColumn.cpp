#include "SudokuColumn.hpp"



SudokuColumn::SudokuColumn(int**& board, int colNumber, int numberspace)
{
  this->numberspace = numberspace;
  this->constituents = new int*[numberspace];
  for(int row = 0 ; row < numberspace; row++)
  {
    this->constituents[row] = &(board[row][colNumber]);
  }
}