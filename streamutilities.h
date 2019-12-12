#ifndef STREAMUTILITIES_H
#define STREAMUTILITIES_H
#include <iostream>

class streamUtilities
{
public:
    static bool hasNextInt(std::istream &in);
    static void consumeWhitespace(std::istream &in);

private:
    streamUtilities() {}
};

#endif // STREAMUTILITIES_H

