#include <iostream>
#include <fstream>

void TypeSizes();
void TypeDef();
void EnumTypes();
void ConstKeyword();
void Files();

int main()
{
    std::cout << "Hello Adriano\n\n";

    TypeSizes();
    TypeDef();
    EnumTypes();
    ConstKeyword();
    Files();

    auto key = std::getchar();

    return key;
}

void title(const char* name)
{
    std::cout << "====================================" << std::endl << std::endl;
    std::cout << name << std::endl << std::endl;
}

void TypeSizes()
{
    title("Type Sizes");

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
    title("TypeDef");

    typedef int feet;
    feet distance = 20;
    std::cout << "distance: " << distance << " feets" << std::endl;
    std::cout << std::endl;
}

void EnumTypes()
{
    title("Enum Types");
    
    enum color { red, green, blue = 5 } c;
    c = blue;

    std::cout << "color = " << c << std::endl;
    std::cout << std::endl;
}

void ConstKeyword()
{
    title("Const Keyword");

    const int  LENGTH = 10;
    const int  WIDTH = 5;
    const char NEWLINE = '\n';

    int area = LENGTH * WIDTH;

    std::cout << area;
    std::cout << NEWLINE;
}

void Files()
{
    title("Files");

    // buffer
    char data[100];

    // open a file in write mode.
    std::ofstream outfile;
    outfile.open("afile.dat");

    std::cout << "Writing to the file" << std::endl;
    std::cout << "Enter your name: ";
    std::cin.getline(data, 100);

    // write inputted data into the file.
    outfile << data << std::endl;

    std::cout << "Enter your age: ";
    std::cin >> data;
    std::cin.ignore();

    // again write inputted data into the file.
    outfile << data << std::endl;

    // close the opened file.
    outfile.close();

    // open a file in read mode.
    std::ifstream infile;
    infile.open("afile.dat");

    std::cout << "Reading from the file" << std::endl;
    infile >> data;

    // write the data at the screen => name
    std::cout << data << std::endl;

    // again read the data from the file and display it => age
    infile >> data;
    std::cout << data << std::endl;

    // close the opened file.
    infile.close();
}