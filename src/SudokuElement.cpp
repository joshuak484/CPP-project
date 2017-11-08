#include "SudokuElement.hpp"



bool SudokuElement::isValid()
{
  int sum = 0, expectedValue = (this->numberspace);
  for(int i = 0; i < (this->numberspace); i++)
  {
    int* pointer2board = (this->constituents)[i];
    sum += (*pointer2board);
    expectedValue += i;
  }
  
  return (sum == expectedValue);
}