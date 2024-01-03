#ifndef JML_BITSET_HPP
#define JML_BITSET_HPP

#include <bitset>

#include "Unique.hpp"
#include "Subset.hpp"

namespace JML {
    template<typename, typename>
    struct Bitset;

    template<typename... Ts, typename... Us>
    requires is_subset_v<TypeList<Ts...>, TypeList<Us...>>//is_subset<Ts..., Us...>
    struct Bitset<TypeList<Ts...>, TypeList<Us...>> {
        static constexpr std::bitset<TypeList<Us...>::Count> Set{};
    };

    //static_assert(Bitset<int, float, char, std::string>::set.size() == 4, "Length of the bitset should be 4");
}

#endif //JML_BITSET_HPP
