#include <iostream>

using namespace std;

void TypeSizes();
void TypeDef();

int main()
{
    std::cout << "Hello Adriano\n\n";

    TypeSizes();
    TypeDef();

    auto key = std::getchar();

    return key;
}

void title(const char* name)
{
    std::cout << "====================================" << endl << endl;
    std::cout << name << endl << endl;
}

void TypeSizes()
{
    title("TypeSizes");

    std::cout << "Size of char : " << sizeof(char) << endl;
    std::cout << "Size of int : " << sizeof(int) << endl;
    std::cout << "Size of short int : " << sizeof(short int) << endl;
    std::cout << "Size of long int : " << sizeof(long int) << endl;
    std::cout << "Size of float : " << sizeof(float) << endl;
    std::cout << "Size of double : " << sizeof(double) << endl;
    std::cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
    std::cout << endl;
}

void TypeDef()
{
    title("TypeDef");

    typedef int feet;
    feet distance = 20;
    std::cout << "distance: " << distance << " feets" << endl;
    std::cout << endl;
}