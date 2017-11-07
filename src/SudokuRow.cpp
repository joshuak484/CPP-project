#include "SudokuRow.hpp"

#include <iostream>
using namespace std;

SudokuRow::SudokuRow(int**& board, int rowNumber, int numberspace)
{
  this->numberspace = numberspace;
  this->constituents = new int*[numberspace];
  for(int col = 0 ; col < numberspace; col++)
  {
    (this->constituents)[col] = &(board[rowNumber][col]); // problem is here;; why am i not getting a valid pointer?
  }
}