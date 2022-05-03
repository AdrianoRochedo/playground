#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

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

void passArray(int prime[5]) // prime is the actual array
{
    prime[0] = 11; // so changing it here will change the original argument!
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;
}

void PassArrayDemo()
{
    Title("PassArrayDemo");

    int value { 1 };
    std::cout << "before passValue: " << value << '\n';
    passValue(value);
    std::cout << "after passValue: " << value << '\n';

    int prime[5] { 2, 3, 5, 7, 11 };
    std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';
    passArray(prime);
    std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << '\n';

    cout << endl;
}