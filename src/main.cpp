#include <iostream>
#include "Bitset.hpp"
#include "Subset.hpp"

int main() {
    auto size = JML::Bitset<JML::TypeList<int>, JML::TypeList<int, float, char>>::Set;
    std::cout << "For building the application in clion, size: " << size << std::endl;
    return 0;
}