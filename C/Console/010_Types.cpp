#include <iostream>
using namespace std;

#include "005_Utils.h"
#include "010_Types.h"

void TypeSizes()
{
    Title("Type Sizes");

    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of int : " << sizeof(int) << endl;
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
    cout << endl;
}

void TypeDef()
{
    Title("TypeDef");

    typedef int feet;
    feet distance = 20;
    cout << "distance: " << distance << " feets" << endl;
    cout << endl;
}

void EnumType()
{
    Title("Enum type");
    
    enum color { red, green, blue = 5 } c;
    c = blue;

    cout << "color = " << c << endl;
    cout << endl;
}

void ConstKeyword()
{
    Title("Const Keyword");

    const int  LENGTH = 10;
    const int  WIDTH = 5;
    const char NEWLINE = '\n';

    int area = LENGTH * WIDTH;

    cout << area;
    cout << NEWLINE;
}
