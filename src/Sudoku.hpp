#ifndef SUDOKU_HPP
#define SUDOKU_HPP

using namespace std;

#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
 
#include "SudokuBoard.hpp"
#include "SudokuRow.hpp"
#include "SudokuColumn.hpp"
#include "SudokuNonomino.hpp"


class Sudoku : public SudokuBoard
{
  private:
    SudokuBoard lockedNumbers;
    int numberspace;
    SudokuElement** rules;
  public:
    Sudoku(vector<vector<vector<int> > >);
    ~Sudoku();
    void getNewBoard9(int**&);
    bool isValid();
    void populate(int, int, int);
    friend ostream& operator<<(ostream&, Sudoku&);
};

#endif //SUDOKU_HPP