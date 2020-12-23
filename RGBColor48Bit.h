#pragma once
#include <utility>

struct RGBColor48Bit
{
public:
    unsigned short int red;
    unsigned short int green;
    unsigned short int blue;

    bool operator == (const RGBColor48Bit& other) const;

private:
    static unsigned long long int compareCount;
};

template <>
class std::hash<RGBColor48Bit>
{
public:
    unsigned int operator() (const RGBColor48Bit& color) const
    {
        // TODO: Write your own hash function here.
        return color.blue * 41 + color.green * 61 + color.red;
    }
};
