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
#include "BitsetFilter.h"

using AllComponents = JML::TypeList<int, char, bool, float, std::string, std::vector<float>>;

using PositionServiceFilter =
    JML::Bitset<JML::TypeList<int, float, char>, AllComponents>;
using AgentComponents =
    JML::Bitset<JML::TypeList<int, float, char, bool>, AllComponents>;
using TreeComponents =
    JML::Bitset<JML::TypeList<std::string, std::vector<float>>, AllComponents>;


int main() {
    auto agentMatches = JML::BitsetFilter<AgentComponents, PositionServiceFilter, void>::FilterMatches;
    auto treeMatches = JML::BitsetFilter<TreeComponents, PositionServiceFilter, void>::FilterMatches;
    std::cout << "For building the application in clion, size: " << agentMatches << std::endl;
    std::cout << "For building the application in clion, size: " << treeMatches << std::endl;
    return 0;
}