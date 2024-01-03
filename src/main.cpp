#include <iostream>
#include "BitSet.hpp"

int main() {
    auto size = JML::BitSet<int, float, char, std::string>::set.size();
    std::cout << "For building the application in clion, size: " << size << std::endl;
    return 0;
}