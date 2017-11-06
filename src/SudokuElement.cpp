#include "SudokuElement.hpp"

#include <iostream>
using namespace std;

bool SudokuElement::isValid()
{
  //cout << "setting up initial vars" << endl;
  int sum = 0, expectedValue = (this->numberspace);
  //cout << "iterating over numberspace" << endl;
  for(int i = 0; i < (this->numberspace); i++)
  {
    //cout << "getting a pointer from the constituents" << endl;
    int* pointer2board = (this->constituents)[i];
    //cout << "adding value to sum: " << (this->constituents)[i] << endl;
    sum += (*pointer2board);    /////ISSUE HERE
    //cout << "adding i to expected val" << endl;
    expectedValue += i;
  }
  
  return (sum == expectedValue);
}