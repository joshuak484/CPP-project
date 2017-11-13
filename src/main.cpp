#include "Sudoku.hpp"
#include "inputLibrary.hpp"



#include <iostream>
#include <fstream>
#include <vector>



using namespace std;



vector<vector<vector<int> > > getBoards9()
{
  ifstream file("boards.txt"); 
  int numberOfBoards;
  file>>numberOfBoards;
  vector< vector< vector< int > > > boards(numberOfBoards, vector< vector< int > >  (9, vector< int > (9)));
  
  for(int i = 0; i < numberOfBoards; i++)
  {
    for(int j = 0; j < 9; j++)
    {
      for(int k = 0; k < 9; k++)
      {
        file>>(boards[i][j][k]);   
      }
    }
  }
  
  return boards;
}



int main()
{
  vector<vector<vector<int> > > answers = getBoards9();
  
  char runflag = 0;
  do{
    runflag = rcinc("Would you like to play a game? (y/n): ");
    
    if(runflag == 'y')
    {
      Sudoku s = Sudoku(answers);
      while(!s.isValid())
      {
        cout << endl << endl<< "Quit at any time by inputting 'Q'" << s << "Leave input sequence at any time by inputting 'L'" << endl;
        try
        {
          int row;
          do
          {
            row = rcinc("Choose a row? (a-i): ") - 'a';
            if(row == ('Q' - 'a'))
            {
              throw(string("Thank you for playing!"));
            }
            else if(row == ('L' - 'a'))
            {
              throw(0);
            }
            else if(row < 0 || row > 9)
            {
              cout << "\tCheck yo sef. Ya jus REKT ya sef." << endl;
            }
          } while(row < 0 || row > 9);
          
          int col;
          do
          {
            col = rcinc("Choose a col? (A-I): ") - 'A';
            if(col == ('Q' - 'A'))
            {
              throw(string("Thank you for playing!"));
            }
            else if(col == ('L' - 'A'))
            {
              throw(0);
            }
            else if(col < 0 || col > 9)
            {
              cout << "\tCheck yo sef. Ya jus REKT ya sef." << endl;
            }
          } while(col < 0 || col > 9);
          
          int num;
          do
          {
            num = rcinc("Choose a num? (1-9): ") - '0';
            if(num == ('Q' - '0'))
            {
              throw(string("Thank you for playing!"));
            }
            else if(num == ('L' - '0'))
            {
              throw(0);
            }
            else if(num < 1 || num > 9)
            {
              cout << "\tCheck yo sef. Ya jus REKT ya sef." << endl;
            }
          } while(num < 1 || num > 9);
          
          try
          {
            s.populate(row, col, num);
          } catch(string message)
          {
            cout << message << endl;
          }
        } catch(string message)
        {
          cout << message << endl;
          runflag = 'n';
          break;
        } catch(int errorCode)
        {
          cout << "\tDisregarding input..." << endl;
        }
      }
      
      if(s.isValid())
      {
        cout << "You won!" << endl << endl;
      }
    }
    else if(runflag == 'n')
    {
      cout << "Yeah, run while you can." << endl;
    }
    else
    {
      cout << "\tYa done did somethin wrong." << endl;
    }
    
  } while(runflag != 'n');
}