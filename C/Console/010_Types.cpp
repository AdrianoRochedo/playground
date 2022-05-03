#include <iostream>

#include "005_Utils.h"
#include "010_Types.h"

void TypeSizes()
{
    Title("Type Sizes");

    std::cout << "Size of char : " << sizeof(char) << std::endl;
    std::cout << "Size of int : " << sizeof(int) << std::endl;
    std::cout << "Size of short int : " << sizeof(short int) << std::endl;
    std::cout << "Size of long int : " << sizeof(long int) << std::endl;
    std::cout << "Size of float : " << sizeof(float) << std::endl;
    std::cout << "Size of double : " << sizeof(double) << std::endl;
    std::cout << "Size of wchar_t : " << sizeof(wchar_t) << std::endl;
    std::cout << std::endl;
}

void TypeDef()
{
    Title("TypeDef");

    typedef int feet;
    feet distance = 20;
    std::cout << "distance: " << distance << " feets" << std::endl;
    std::cout << std::endl;
}

void EnumType()
{
    Title("Enum Types");
    
    enum color { red, green, blue = 5 } c;
    c = blue;

    std::cout << "color = " << c << std::endl;
    std::cout << std::endl;
}

void ConstKeyword()
{
    Title("Const Keyword");

    const int  LENGTH = 10;
    const int  WIDTH = 5;
    const char NEWLINE = '\n';

    int area = LENGTH * WIDTH;

    std::cout << area;
    std::cout << NEWLINE;
}
