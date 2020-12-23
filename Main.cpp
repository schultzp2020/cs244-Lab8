#include <iostream>
#include <unordered_set>
#include "RGBColor48Bit.h"

using namespace std;

void test1()
{
    unordered_set<RGBColor48Bit> testSet{ 6 * SHRT_MAX };
    for (unsigned short int i{ 1 }; i <= SHRT_MAX; i++)
    {
        if ((i + 1) % 1024 == 0)
        {
            cout << "Test group " << i << " complete." << endl;
        }

        testSet.insert(RGBColor48Bit{ i, 0, 0 }); // shades of red
        testSet.insert(RGBColor48Bit{ 0, i, 0 }); // shades of green
        testSet.insert(RGBColor48Bit{ 0, 0, i }); // shades of blue
    }
}

void test2()
{
    unordered_set<RGBColor48Bit> testSet{ 6 * (SHRT_MAX + 1) };
    for (unsigned short int i{ 0 }; i <= SHRT_MAX; i++)
    {
        if ((i + 1) % 1024 == 0)
        {
            cout << "Test group " << (i + 1) << " complete." << endl;
        }

        unsigned short int maxMinusI { static_cast<unsigned short int>(SHRT_MAX - i) };

        testSet.insert(RGBColor48Bit{ i, maxMinusI, 0 }); // gradient between red and green
        testSet.insert(RGBColor48Bit{ 0, i, maxMinusI }); // gradient between green and blue
        testSet.insert(RGBColor48Bit{ maxMinusI, 0, i }); // gradient between blue and red
    }
}

int main()
{
    cout << "Test 1: " << endl;
    test1();
    cout << endl;

    cout << "Test 2: " << endl;
    test2();
    cout << endl;

    return 0;
}
