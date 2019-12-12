#include "memories.h"

memories::memories()
{

}

memories::~memories() {
    for(int i = 0; i < 26; i++) {
        complexNumberList[i] = complexNumber();
    }
}

void memories::setComplexNumber(char symbol, const complexNumber &complex) {
    checkSymbolOutOfRange(symbol);
    complexNumberList[symbol - 'A'] = complex;
}

complexNumber& memories::get(char symbol) {
    checkSymbolOutOfRange(symbol);
    return complexNumberList[symbol - 'A'];
}

void memories::loadFromFile(const std::string &filename) {
    std::ifstream inputFile(filename);
    if(!inputFile.good()) {
        throw(FILE_DOES_NOT_EXIST);
    }

    char symbol, equalsTrash;

    while(inputFile.good()) {
        std::string line;
        getline(inputFile, line);

        // An expression needs to have atleast a symbol, space, and equals sign to to be considered valid
        if(line.length() >= 3) {
            std::stringstream ss;
            ss << line;
            ss >> symbol >> equalsTrash;
            ss >> get(symbol);
        }
    }
}

// NOTE: Does not check if file already exists
void memories::saveToFile(const std::string &filename) {
    std::ofstream outputFile(filename);
    for(int i = 0 ; i < 26; i++) {
        outputFile << static_cast<char>(i + 'A') << " = " << complexNumberList[i] << std::endl;
    }
    outputFile.close();
}

void memories::printSymbolToStream(std::ostream &out, char symbol) {
    checkSymbolOutOfRange(symbol);
    out << symbol << " = " << complexNumberList[symbol - 'A'] << std::endl;
}

void memories::checkSymbolOutOfRange(char symbol) {
    if(symbol < 'A' || symbol > 'Z') {
        throw(SYMBOL_OUT_OF_RANGE);
    }
}

