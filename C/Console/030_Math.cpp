#include <iostream>
#include <cmath>

#include "005_Utils.h"
#include "030_Math.h"

void Math()
{
    Title("Math");

    // number definition:
    short  s = 10;
    int    i = -1000;
    long   l = 100000L;
    float  f = 230.47F;
    double d = 200.374;

    // mathematical operations;
    std::cout << "sin(d) :"     << sin(d)    << std::endl;
    std::cout << "abs(i)  :"    << abs(i)    << std::endl;
    std::cout << "floor(d) :"   << floor(d)  << std::endl;
    std::cout << "sqrt(f) :"    << sqrt(f)   << std::endl;
    std::cout << "pow( d, 2) :" << pow(d, 2) << std::endl;
}

void Random()
{
    Title("Random");

    int i, j;

    // set the seed
    srand((unsigned)time(NULL));

    /* generate 10  random numbers. */
    for (i = 0; i < 10; i++) 
    {
        // generate actual random number
        j = rand();
        std::cout << " Random Number : " << j << std::endl;
    }
}