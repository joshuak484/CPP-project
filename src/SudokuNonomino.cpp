#include "SudokuNonomino.hpp"



SudokuNonomino::SudokuNonomino(int**& board, bool** shape, int numberspace) //SudokuBoard, shape of the nonomino, NumberSpace
{
  this->shape = shape;
  this->numberspace = numberspace;
  this->constituents = new int*[numberspace];
  int progress = 0;
  for(int row = 0 ; row < numberspace; row++)
  {
    for(int col = 0; col  <numberspace; col++)
    {
      if(shape[row][col])
      {
        this->constituents[progress++] = &(board[row][col]);
      }
    }
  }
}