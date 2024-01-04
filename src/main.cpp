#include <iostream>
#include "Aggregate.hpp"
#include "Bitset.hpp"
#include "Subset.hpp"
#include "Concat.hpp"
#include "Contains.hpp"
#include "Count.hpp"
#include "Exists.hpp"
#include "HList.hpp"
#include "Index.hpp"
#include "Map.hpp"
#include "Repeat.hpp"
#include "ToType.hpp"
#include "TypeList.hpp"
#include "TypeMatch.hpp"
#include "Unique.hpp"

int main() {
    std::bitset<3> a("100");
    std::bitset<3> b("011");
    std::cout<< (a | b) << std::endl;
    std::cout << (a.set((1 << 1))) << std::endl;
    auto size = JML::Bitset<JML::TypeList<int>, JML::TypeList<int, char, float, bool>>::Set;
    std::cout << "For building the application in clion, size: " << size << std::endl;
    return 0;
}