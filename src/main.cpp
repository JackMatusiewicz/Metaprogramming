#include <iostream>
#include "Bitset.hpp"
#include "Subset.hpp"

int main() {
    std::bitset<3> a("100");
    std::bitset<3> b("011");
    std::cout<< (a | b) << std::endl;
    std::cout << (a.set((1 << 1))) << std::endl;
    auto size = JML::Bitset<JML::TypeList<int>, JML::TypeList<char, int, bool>>::Set;
    std::cout << "For building the application in clion, size: " << size << std::endl;
    return 0;
}