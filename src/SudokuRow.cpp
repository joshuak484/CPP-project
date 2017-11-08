#include "SudokuRow.hpp"



SudokuRow::SudokuRow(int**& board, int rowNumber, int numberspace)
{
  this->numberspace = numberspace;
  this->constituents = new int*[numberspace];
  for(int col = 0 ; col < numberspace; col++)
  {
    (this->constituents)[col] = &(board[rowNumber][col]);
  }
}