#include <rl_file.h>

/**
 * Orion "KeinR" Musselman
 * Version 1.1
 */

rl_file::rl_file(int sizeVal, const char *dataVal): sizeVal(sizeVal), dataVal(dataVal) {
}

rl_file::~rl_file() {
    free();
}

void rl_file::free() {
    if (sizeVal) {
        delete[] dataVal;
        sizeVal = 0;
    }
}

int rl_file::size() const {
    return sizeVal;
}

const char *rl_file::data() const {
    return dataVal;
}
