#include <iostream>

#include "resources.h"

int main() {
    std::cout << _gitignore.data() << std::endl;
    _gitignore.free();
}
