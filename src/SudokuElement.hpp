#ifndef SUDOKUELEMENT_HPP
#define SUDOKUELEMENT_HPP

class SudokuElement
{
  protected:
    int numberspace;
    int** constituents;
  public:
    bool isValid();
    ~SudokuElement();
};

#endif //SUDOKUELEMENT_HPP