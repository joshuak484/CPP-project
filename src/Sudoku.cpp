#include "Sudoku.hpp"

#include <iostream>
using namespace std;

Sudoku::Sudoku() : SudokuBoard(9)
{
  this->numberspace = 9;
  //cout << "made namespace" << endl;
  
  this->playspace = new int*[9];
  //cout << "made rows of playspace" << endl;
  
  for (int i = 0; i < 9; ++i)
    (this->playspace)[i] = new int[9];
  //cout << "made cols of playspace" << endl;
  
  getNewBoard9(this->playspace);
  /*cout << "initiailized playspace" << endl;

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cout << (this->playspace)[i][j] << " ";
    }
    cout << endl;
  }*/
  
  this->rules = new SudokuElement*[27];
  //cout << "made rules" << endl;
  
  for(int i = 0; i< 27; i++)
  {
    int set = i/9;
    int setPart = i%9;
    SudokuElement* newElement;
    
    if(set == 0) //Do sudoku rows
    {
      newElement = new SudokuRow(this->playspace, setPart, 9);
      //cout << "making row rule: " << setPart << endl;
    }
    else if(set == 1) // Do sudoku cols
    {
      newElement = new SudokuColumn(this->playspace, setPart, 9);
      //cout << "making col rule: " << setPart << endl;
    }
    else // Do sudoku nonos
    {
      int nonoRow = setPart / 3;
      int nonoCol = setPart % 3;
      bool** shape = new bool*[9];
      for(int i = 0; i < 9; i++)
      {
        shape[i] = new bool[9];
      }
      
      for(int row = 0; row < 9; row++)
      {
        for(int col = 0; col < 9; col++)
        {
          if((col / 3 == nonoCol) && (row / 3 == nonoRow))
          {
            shape[row][col] = true;
          }
          else
          {
            shape[row][col] = false;
          }
        }
      }
      
      newElement = new SudokuNonomino(this->playspace, shape, 9);
      //cout << "making nono rule: " << setPart << endl;
    }
    
    (this->rules)[i] = newElement;
  }
  //cout << "All rules made" << endl;
}



void Sudoku::getNewBoard9(int**& sudoku)
{
  sudoku[0][0] = 2;
  sudoku[0][1] = 9;
  sudoku[0][2] = 5;
  sudoku[0][3] = 7;
  sudoku[0][4] = 4;
  sudoku[0][5] = 3;
  sudoku[0][6] = 8;
  sudoku[0][7] = 6;
  sudoku[0][8] = 1;
  
  sudoku[1][0] = 4;
  sudoku[1][1] = 3;
  sudoku[1][2] = 1;
  sudoku[1][3] = 8;
  sudoku[1][4] = 6;
  sudoku[1][5] = 5;
  sudoku[1][6] = 9;
  sudoku[1][7] = 2;
  sudoku[1][8] = 7;
  
  sudoku[2][0] = 8;
  sudoku[2][1] = 7;
  sudoku[2][2] = 6;
  sudoku[2][3] = 1;
  sudoku[2][4] = 9;
  sudoku[2][5] = 2;
  sudoku[2][6] = 5;
  sudoku[2][7] = 4;
  sudoku[2][8] = 3;
  
  sudoku[3][0] = 3;
  sudoku[3][1] = 8;
  sudoku[3][2] = 7;
  sudoku[3][3] = 4;
  sudoku[3][4] = 5;
  sudoku[3][5] = 9;
  sudoku[3][6] = 2;
  sudoku[3][7] = 1;
  sudoku[3][8] = 6;
  
  sudoku[4][0] = 6;
  sudoku[4][1] = 1;
  sudoku[4][2] = 2;
  sudoku[4][3] = 3;
  sudoku[4][4] = 8;
  sudoku[4][5] = 7;
  sudoku[4][6] = 4;
  sudoku[4][7] = 9;
  sudoku[4][8] = 5;
  
  sudoku[5][0] = 5;
  sudoku[5][1] = 4;
  sudoku[5][2] = 9;
  sudoku[5][3] = 2;
  sudoku[5][4] = 1;
  sudoku[5][5] = 6;
  sudoku[5][6] = 7;
  sudoku[5][7] = 3;
  sudoku[5][8] = 8;
  
  sudoku[6][0] = 7;
  sudoku[6][1] = 6;
  sudoku[6][2] = 3;
  sudoku[6][3] = 5;
  sudoku[6][4] = 2;
  sudoku[6][5] = 4;
  sudoku[6][6] = 1;
  sudoku[6][7] = 8;
  sudoku[6][8] = 9;
  
  sudoku[7][0] = 9;
  sudoku[7][1] = 2;
  sudoku[7][2] = 8;
  sudoku[7][3] = 6;
  sudoku[7][4] = 7;
  sudoku[7][5] = 1;
  sudoku[7][6] = 3;
  sudoku[7][7] = 5;
  sudoku[7][8] = 4;
  
  sudoku[8][0] = 1;
  sudoku[8][1] = 5;
  sudoku[8][2] = 4;
  sudoku[8][3] = 9;
  sudoku[8][4] = 3;
  sudoku[8][5] = 8;
  sudoku[8][6] = 6;
  sudoku[8][7] = 7;
  sudoku[8][8] = 2;
}



bool Sudoku::isValid()
{
  for(int i = 0; i < 27; i++)
  {
    //cout << "getting rule: " << i << endl;
    SudokuElement* rule = (this->rules)[i];
    //cout << "getting validity: " << i << endl;
    int validity = rule->isValid();
    //cout << "returning: " << i << endl;
    if(!validity)
    {
      return false;
    }
  }
  return true;
}