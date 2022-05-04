#include <iomanip>
using std::setw;

#include <iterator>  // for std::size
#include <algorithm> // for std::sort
#include <vector>    // for std::vector
#include <iostream>
using namespace std;

#include "005_Utils.h"

// https://www.learncpp.com/cpp-tutorial/arrays-part-i/
// https://www.learncpp.com/cpp-tutorial/arrays-part-ii/

void ArrayType()
{
    Title("Array type");

    int n[10]; // n is an array of 10 integers

    // initialize elements of array n to 0          
    for (int i = 0; i < 10; i++) {
        n[i] = i + 100; // set element at location i to i + 100
    }

    cout << "Element" << setw(13) << "Value" << endl;

    // output each array element's value                      
    for (int j = 0; j < 10; j++) {
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }

    cout << endl;
}

// =======================================================================

void passValue(int value) // value is a copy of the argument
{
    value = 99; // so changing it here won't change the value of the argument
}

void ArrayToFunction(int prime[5]) // prime is the actual array
{
    prime[0] = 11; // so changing it here will change the original argument!
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;
}

void ArrayToFunction()
{
    Title("ArrayToFunction");

    int value { 1 };
    std::cout << "before passValue: " << value << '\n';
    passValue(value);
    std::cout << "after passValue: " << value << '\n';

    int prime[5] { 2, 3, 5, 7, 11 };
    std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';
    ArrayToFunction(prime);
    std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';

    cout << endl;
}

// =======================================================================

void ArrayWithEnums()
{
    Title("ArrayWithEnums");

    enum StudentNames
    {
        kenny,       // 0
        kyle,        // 1
        stan,        // 2
        butters,     // 3
        cartman,     // 4
        wendy,       // 5
        max_students // 6
    };

    int testScores[StudentNames::max_students] {}; // allocate 6 integers
    testScores[StudentNames::stan] = 76;

    cout << "testScores[stan] = " << testScores[StudentNames::stan] << endl;

    cout << endl;
}

// =======================================================================

void printSize(int array[])
{
    // std::size nao funciona com parametros tipo array
    //std::cout << std::size(array) << '\n'; // Error
}

void ArraySize()
{
    Title("ArraySize");
    int array[]{ 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << std::size(array) << '\n'; // will print the size of the array
    printSize(array);
    cout << endl;
}

// =======================================================================

bool myCompareFunction(int i, int j) 
{ 
    return i < j; 
}

struct myCompareClass 
{
    bool operator() (int i, int j) 
    { 
        return i > j; 
    }
} 
myCompareObject;

void ArraySort()
{
    Title("ArraySort");

    int array[]{ 30, 50, 20, 10, 40 };

    // ---------------------------------------------------------

    std::sort(std::begin(array), std::end(array), std::less<>{}); // default

    for (int i = 0; i < static_cast<int>(std::size(array)); ++i)
        std::cout << array[i] << ' ';

    cout << endl << endl;

    // ---------------------------------------------------------

    std::sort(std::begin(array), std::end(array), std::greater<>{});

    for (int i=0; i < static_cast<int>(std::size(array)); ++i)
        std::cout << array[i] << ' ';

    cout << endl << endl;

    // ---------------------------------------------------------

    std::sort(std::begin(array), std::end(array), myCompareFunction);

    for (int i = 0; i < static_cast<int>(std::size(array)); ++i)
        std::cout << array[i] << ' ';

    cout << endl << endl;

    // ---------------------------------------------------------

    std::sort(std::begin(array), std::end(array), myCompareObject);

    for (int i = 0; i < static_cast<int>(std::size(array)); ++i)
        std::cout << array[i] << ' ';

    cout << endl << endl;
}

// =======================================================================

void ArrayWithVector()
{
    Title("ArrayWith: std::vector, std::copy_if, lambda e for(each)");

    std::vector<int> foo = { 25,15,5,-5,-15 };
    std::vector<int> bar(foo.size());

    // copy only negative numbers
    auto it = std::copy_if(foo.begin(), foo.end(), bar.begin(), [](int i) {return i < 0; });
    
    // shrink container to new size
    bar.resize(std::distance(bar.begin(), it));  

    std::cout << "foo contains:";
    for (int x : foo) std::cout << ' ' << x;
    cout << endl;

    std::cout << "bar contains:";
    for (int x : bar) std::cout << ' ' << x;
    cout << endl;

    cout << endl;
}