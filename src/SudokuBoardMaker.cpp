#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;





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
  
    for (int n=1; n<=9; n++)
    {
      vector <int*> vect;
      do// Fill vect
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
        if (vect.size() > 0) // if any locations are available...
        {
          int randInt = rand() % vect.size(); // choose a random location on the board for n
          *(vect.at (randInt)) = n; // set chosen location to n
        }
        cout<<n<<" ; "<<vect.size()<<endl;
      }while (vect.size() > 0); // keep iterating until locations arent available for the current n
    }
    
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
    
    cout << endl;
  }
  
  
  
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
};
