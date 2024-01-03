#ifndef JML_BITSET_H
#define JML_BITSET_H

#include <bitset>

#include "Unique.h"

namespace JML {
    template<typename... Args>
    requires unique_elements<Args...>
    struct BitSet {
        static constexpr std::bitset<TypeList<Args...>::Count> set{};
    };

    static_assert(BitSet<int, float, char, std::string>::set.size() == 4, "Length of the bitset should be 4");
}

#endif //JML_BITSET_H
