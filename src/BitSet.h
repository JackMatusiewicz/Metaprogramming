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
}

#endif //JML_BITSET_H
