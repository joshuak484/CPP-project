/*  Name:  Jonathan Strang  */



#ifndef INPUTLIBRARY_HPP
#define INPUTLIBRARY_HPP

#include <string>
#include <iostream>
#include <istream>

char rcinc(std::string);
int rcini(std::string);
std::string rcins(std::string);

char rcinc(std::istream&, std::string);
int rcini(std::istream&, std::string);
std::string rcins(std::istream&, std::string);

#endif // INPUTLIBRARY_HPP