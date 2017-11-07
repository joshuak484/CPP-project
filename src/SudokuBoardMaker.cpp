#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>



using namespace std;



void defaultBoard(int**& sudoku)
{
  sudoku[0][0] = 1;
  sudoku[0][1] = 8;
  sudoku[0][2] = 7;
  sudoku[0][3] = 6;
  sudoku[0][4] = 4;
  sudoku[0][5] = 2;
  sudoku[0][6] = 3;
  sudoku[0][7] = 9;
  sudoku[0][8] = 5;
  
  sudoku[1][0] = 3;
  sudoku[1][1] = 4;
  sudoku[1][2] = 5;
  sudoku[1][3] = 7;
  sudoku[1][4] = 1;
  sudoku[1][5] = 9;
  sudoku[1][6] = 8;
  sudoku[1][7] = 2;
  sudoku[1][8] = 6;
  
  sudoku[2][0] = 6;
  sudoku[2][1] = 9;
  sudoku[2][2] = 2;
  sudoku[2][3] = 8;
  sudoku[2][4] = 5;
  sudoku[2][5] = 3;
  sudoku[2][6] = 4;
  sudoku[2][7] = 7;
  sudoku[2][8] = 1;
  
  sudoku[3][0] = 8;
  sudoku[3][1] = 3;
  sudoku[3][2] = 1;
  sudoku[3][3] = 2;
  sudoku[3][4] = 7;
  sudoku[3][5] = 5;
  sudoku[3][6] = 9;
  sudoku[3][7] = 6;
  sudoku[3][8] = 4;
  
  sudoku[4][0] = 7;
  sudoku[4][1] = 2;
  sudoku[4][2] = 9;
  sudoku[4][3] = 1;
  sudoku[4][4] = 6;
  sudoku[4][5] = 4;
  sudoku[4][6] = 5;
  sudoku[4][7] = 8;
  sudoku[4][8] = 3;
  
  sudoku[5][0] = 5;
  sudoku[5][1] = 6;
  sudoku[5][2] = 4;
  sudoku[5][3] = 9;
  sudoku[5][4] = 3;
  sudoku[5][5] = 8;
  sudoku[5][6] = 2;
  sudoku[5][7] = 1;
  sudoku[5][8] = 7;
  
  sudoku[6][0] = 2;
  sudoku[6][1] = 7;
  sudoku[6][2] = 3;
  sudoku[6][3] = 5;
  sudoku[6][4] = 8;
  sudoku[6][5] = 6;
  sudoku[6][6] = 1;
  sudoku[6][7] = 4;
  sudoku[6][8] = 9;
  
  sudoku[7][0] = 4;
  sudoku[7][1] = 1;
  sudoku[7][2] = 8;
  sudoku[7][3] = 3;
  sudoku[7][4] = 9;
  sudoku[7][5] = 7;
  sudoku[7][6] = 6;
  sudoku[7][7] = 5;
  sudoku[7][8] = 2;
  
  sudoku[8][0] = 9;
  sudoku[8][1] = 5;
  sudoku[8][2] = 6;
  sudoku[8][3] = 4;
  sudoku[8][4] = 2;
  sudoku[8][5] = 1;
  sudoku[8][6] = 7;
  sudoku[8][7] = 3;
  sudoku[8][8] = 8;
}

void getAvaliableSlots(vector<int*>& vect, int** board, int n)
{
  vect.clear();// clear vector
  for (int i=0; i<9; i++)// iterate over rows of board
  {
     for (int j=0; j<9; j++)//iterate over cols of board
     {
       int rowN = i/3, // calculate starting row location of nonomino
           colN = j/3; // calculate starting col loc of nonomino
       
       bool avail = (board[i][j] == 0); // check if the slot is avaailable
       
       for (int iCheck = 0; (iCheck < 9) && avail; iCheck++) // iterate over row assuming that the currentl coation is still availiable
       {
         if (iCheck != i) // do not include the current location
         {
           
           avail = ((board [iCheck][j] == n))? false: avail; // if n is in the row, set the current location to unavailiable
         }
       }
       
       for (int jCheck = 0; (jCheck < 9) && avail; jCheck++) // iterate over col assuming that the currentl coation is still availiable
       {
         if (jCheck != j) // do not include current location
         {
           
           avail = ((board [i][jCheck] == n))? false: avail;// if n is in the col, set the current location to unavailiable
         }
       }
       
       for (int iN = rowN * 3; (iN < (rowN * 3 + 3)) && avail; iN++) // iterate over current nonomino rows assuming cur loc is avail
       {
         for (int jN = colN * 3; (jN < (colN * 3 + 3)) && avail; jN++) // iterate over current nonomino cols assuming cur loc is avail
         {
           avail = ((board [iN][jN] == n))? false: avail; // if n is in the nonomino, set current location to unavailiable
         }
       }
       if (avail) // if current location is avila, add to vector
       {
         vect.push_back (&(board [i][j]));
       }
     }
  }
}

bool isValid(int** board)
{
  bool correctness = true;
  for (int i=0; (i<9) && correctness; i++)// iterate over rows of board
  {
     for (int j=0; (j<9) && correctness; j++)//iterate over cols of board
     {
       int rowN = i/3, // calculate starting row location of nonomino
           colN = j/3; // calculate starting col loc of nonomino
       
       bool avail = (board[i][j] != 0); // check if the slot is avaailable
       
       for (int iCheck = 0; (iCheck < 9) && avail; iCheck++) // iterate over col assuming that the currentl coation is still availiable
       {
         if (iCheck != i) // do not include the current location
         {
           avail = ((board [iCheck][j] == board[i][j]))? false: avail; // if n is in the col, set the current location to unavailiable
         }
       }
       
       for (int jCheck = 0; (jCheck < 9) && avail; jCheck++) // iterate over row assuming that the currentl coation is still availiable
       {
         if (jCheck != j) // do not include current location
         {
           avail = ((board [i][jCheck] == board[i][j]))? false: avail;// if n is in the row, set the current location to unavailiable
         }
       }
       
       for (int iN = rowN * 3; (iN < (rowN * 3 + 3)) && avail; iN++) // iterate over current nonomino rows assuming cur loc is avail
       {
         for (int jN = colN * 3; (jN < (colN * 3 + 3)) && avail; jN++) // iterate over current nonomino cols assuming cur loc is avail
         {
           if (jN != j && iN != i) // do not include current location
           {
             avail = ((board [iN][jN] == board[i][j]))? false: avail; // if n is in the nonomino, set current location to unavailiable
           }
         }
       }
       correctness &= avail;
     }
  }
  
  return correctness;
}
int main()
{
  int** sudoku;
  sudoku = new int*[9];
  for (int i = 0; i < 9; ++i)
    sudoku[i] = new int[9];
  
  
  srand(time(NULL));
  int counter = 0;
  while(counter < 20)
  {
    for(int i=0;i<9;i++)
      for(int j=0;j<9;j++)
        sudoku[i][j] = rand() % 9 + 1;
  

    if(isValid(sudoku))
    {
      printSudoku(board);
      counter++;
    }
  }

int numberOfZeroes(int* array,int arraylength)
{
  int output = 0;
  for(int i = 0 ; i < arraylength; i++)
  {
    output += (array[i] == 0)?1:0;
  }
}

void removeFromBoard(int**& board, int n)
{
  for(int i = 0 ; i < 9 ; i++)
  {
    for(int j = 0 ; j < 9 ; j++)
    {
       if(board[i][j] == n)
         board[i][j] = 0;
    }
  }
}




void generateBoard(int**& board)
{
  int** currentboard = new int*[9];
  for(int  i = 0; i<9; i++)
    currentboard[i] = new int[9];
    
  int* boardHistoryN = new int[9];
  
  
  vector<int> remainingN;
  for(int i = 0; i < 9; i++)
  {
    remainingN.push_back(i);
  }
  
  
  int boardHistoryIndex = 0;
  while(boardHistoryIndex != 9)
  {
    int expectedAvailableSlots = (9 - boardHistoryIndex) * 9;
    
    vector<int*> availableSlots;
    int nLoc = rand() % remainingN.size();
    int chosenN = remainingN.at(nLoc);
    remainingN.erase(remainingN.begin() + nLoc);
    getAvaliableSlots(availableSlots, currentboard, chosenN);
    
    if(availableSlots.size() != expectedAvailableSlots)
    {
      if(remainingN.size() == 1)
      {
        for(int  i = 0; i<9; i++)
        {
          boardHistoryN[i] = 0;
          for(int j = 0; j<9; j++)
            currentboard[i][j] = 0;
        }
        boardHistoryIndex = 0;
        
        remainingN.clear();
        for(int i = 0; i < 9; i++)
        {
          remainingN.push_back(i);
        }
        srand(time(NULL));
      }
      else
      {
        //cout << "exceeded expected sloots N="<< boardHistoryIndex<<": " << availableSlots.size() << "/" << expectedAvailableSlots << endl;
        //printSudoku(currentboard);  
        int rN = boardHistoryN[--boardHistoryIndex];
        removeFromBoard(currentboard, rN);
        remainingN.push_back(rN);
        getAvaliableSlots(availableSlots, currentboard, chosenN);
      }
    }
    
    do
    {
      availableSlots.clear();
      getAvaliableSlots(availableSlots, currentboard, chosenN);
      if(availableSlots.size() != 0)
      {
        *(availableSlots.at(rand() % availableSlots.size())) = chosenN;
      }
    } while(availableSlots.size() != 0);
    boardHistoryN[boardHistoryIndex++] = chosenN;
    
    if(boardHistoryIndex == 9 && !isValid(currentboard))
    {
      cout << "Something went wrong!" << endl;
    }
  }
  board = currentboard;
}




int main()
{
  int** board;
  board = new int*[9];
  for (int i = 0; i < 9; ++i)
    board[i] = new int[9];
    
    
  for (int n=1; n<=20; n++)
  {
    for(int i = 0 ; i < 9; i++)
      for(int j = 0; j < 9; j++)
        board[i][j] = 0;
  
    generateBoard(board);
    printSudoku(board);
  }
};