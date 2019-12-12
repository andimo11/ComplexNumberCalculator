#include "streamutilities.h"

bool streamUtilities::hasNextInt(std::istream &in) {
    consumeWhitespace(in);
    if(in.good()) {
        char nextChar = static_cast<char>(in.peek());
        if(nextChar >= '0' && nextChar <= '9') {
            return true;
        }
    }
    return false;
}

void streamUtilities::consumeWhitespace(std::istream &in) {
    while(in.good() && in.peek() == ' ') {
        in.ignore();
    }
}
