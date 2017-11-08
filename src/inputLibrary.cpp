/*  Name:  Jonathan Strang  */



#include "inputLibrary.hpp"



char rcinc(std::string prompt)
{
  bool inputBufferStillPopulated = false;
  char character = 0;
  
  do
  {
    if(std::cin.fail() || inputBufferStillPopulated)
    {
      inputBufferStillPopulated = false;
      std::cin.clear();
      while(std::cin.get() != '\n');
      std::cout << "\tERROR: Input was not accepted, try again." << std::endl;
    }
    std::cout << prompt;
  } while(!(std::cin >> character) || (inputBufferStillPopulated = (std::cin.get() != '\n')));
  
  return character;
}



int rcini(std::string prompt)
{
  bool inputBufferStillPopulated = false;
  int integer = 0;
  
  do
  {
    if(std::cin.fail() || inputBufferStillPopulated)
    {
      inputBufferStillPopulated = false;
      std::cin.clear();
      while(std::cin.get() != '\n');
      std::cout << "\tERROR: Input was not accepted, try again." << std::endl;
    }
    std::cout << prompt;
  } while(!(std::cin >> integer) || (inputBufferStillPopulated = (std::cin.get() != '\n')));
  
  return integer;
}



std::string rcins(std::string prompt)
{
  std::cout << prompt;
  std::string output;
  std::getline(std::cin, output);
  return output;
}



char rcinc(std::istream& is, std::string prompt)
{ // needs checking
  bool inputBufferStillPopulated = false;
  char character = 0;
  
  do
  {
    if(is.fail() || inputBufferStillPopulated)
    {
      inputBufferStillPopulated = false;
      is.clear();
      while(std::cin.get() != '\n');
      std::cout << "\tERROR: Input was not accepted, try again." << std::endl;
    }
    std::cout << prompt;
  } while(!(is >> character) || (inputBufferStillPopulated = (is.get() != '\n')));
  
  return character;
}



int rcini(std::istream& is, std::string prompt)
{ // needs checking
  bool inputBufferStillPopulated = false;
  int integer = 0;
  
  do
  {
    if(is.fail() || inputBufferStillPopulated)
    {
      inputBufferStillPopulated = false;
      is.clear();
      while(is.get() != '\n');
      std::cout << "\tERROR: Input was not accepted, try again." << std::endl;
    }
    std::cout << prompt;
  } while(!(is >> integer) || (inputBufferStillPopulated = (is.get() != '\n')));
  
  return integer;
}



std::string rcins(std::istream& is, std::string prompt)
{ // needs checking
  std::cout << prompt;
  std::string output;
  std::getline(is, output);
  return output;
}