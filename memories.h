#ifndef MEMORIES_H
#define MEMORIES_H
#include "complexNumber.h"

class memories
{
public:
    enum ERRORS {SYMBOL_OUT_OF_RANGE, FILE_DOES_NOT_EXIST};

    memories();
    ~memories();

    void setComplexNumber(char symbol, const complexNumber &complex);
    complexNumber& get(char symbol);
    void loadFromFile(const std::string &filename);
    void saveToFile(const std::string &filename);

    void printSymbolToStream(std::ostream &out, char symbol);
private:
    complexNumber complexNumberList[26];
    void checkSymbolOutOfRange(char symbol);
};

#endif // MEMORIES_H
