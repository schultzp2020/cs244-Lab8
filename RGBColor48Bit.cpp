#include "RGBColor48Bit.h"
#include <iostream>

unsigned long long int RGBColor48Bit::compareCount { 0 };

bool RGBColor48Bit::operator==(const RGBColor48Bit& other) const
{
    compareCount++;
    if (compareCount % 100000 == 0)
    {
        std::cout << compareCount << " comparisons." << std::endl;
    }

    return red == other.red
        && green == other.green
        && blue == other.blue;
}
