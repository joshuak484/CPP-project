#include "SudokuBoard.hpp"



SudokuBoard::SudokuBoard(const int numberSpace)
{
  this->numberSpace = numberSpace;
  this->playspace = new int*[numberSpace];
  for (int i = 0; i < numberSpace; ++i)
    this->playspace[i] = new int[numberSpace];
}



SudokuBoard::~SudokuBoard()
{
  for (int i = 0; i < numberSpace; ++i)
    delete [] (this->playspace)[i];
  delete [] (this->playspace);
}



void SudokuBoard::setPlayspace(int*** newPlayspace)
{
  this -> playspace = *newPlayspace;
}



int*** SudokuBoard::getPlayspace()
{
  return &(this -> playspace);
}