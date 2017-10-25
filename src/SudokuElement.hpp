#ifndef SUDOKUELEMENT_HPP
#define SUDOKUELEMENT_HPP

class SudokuElement
{
  private:
    int numberspace;
    int** constituents;
  public:
    SudokuElement(int = 9, int**);
    virtual bool isValid();
};

#enfid //SUDOKUELEMENT_HPP