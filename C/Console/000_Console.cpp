#include <iostream>

#include "005_Utils.h"
#include "010_Types.h"
#include "012_ArrayType.h"
#include "020_Files.h"
#include "030_Math.h"

int main()
{
    std::cout << "Hello Adriano\n\n";

    TypeSizes();
    TypeDef();
    EnumType();
    ConstKeyword();

    ArrayType();
    ArrayToFunction();
    ArrayWithEnums();
    ArraySize();
    ArraySort();
    ArrayWithVector();

    // String
    // Struct
    // Class

    //Files();
    
    Math();
    Random();

    auto key = std::getchar();

    return key;
}