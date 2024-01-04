#ifndef JML_BITSET_HPP
#define JML_BITSET_HPP

#include <bitset>

#include "Unique.hpp"
#include "Subset.hpp"
#include "Index.hpp"

// Until we move to c++23, in order to keep this a compile-time construct we need to limit the size of the bitset to
// that of an unsigned long long. After c++23 there are a constexpr functions we can use to allow for larger bitsets.
namespace JML {

    template<typename, typename>
    struct BitSetHelper {
        static constexpr unsigned long long encoded_set = 0;
    };

    template<typename... Ts, typename... Us>
    requires is_subset_v<TypeList<Ts...>, TypeList<Us...>>
    struct BitSetHelper<TypeList<Ts...>, TypeList<Us...>> {
        static constexpr unsigned long long encoded_set = 0;
    };

    template<typename T, typename...Ts, typename...Us>
    struct BitSetHelper<TypeList<T, Ts...>, TypeList<Us...>> {
        static constexpr unsigned long long encoded_set =
            (Index<T, TypeList<Us...>>::found
                ? (1 << (TypeList<Us...>::Count - 1 - Index<T, TypeList<Us...>>::value)) : 0)
            | BitSetHelper<TypeList<Ts...>, TypeList<Us...>>::encoded_set;
    };

    template<typename, typename>
    struct Bitset;

    template<typename... Ts, typename... Us>
    requires is_subset_v<TypeList<Ts...>, TypeList<Us...>>
    struct Bitset<TypeList<Ts...>, TypeList<Us...>> {
        static constexpr std::bitset<TypeList<Us...>::Count> Set{BitSetHelper<TypeList<Ts...>, TypeList<Us...>>::encoded_set};
    };

    static_assert(Bitset<TypeList<int>, TypeList<char, int, bool>>::Set.size() == 3);
    static_assert(Bitset<TypeList<int>, TypeList<char, int, bool>>::Set[0] == 0);
    static_assert(Bitset<TypeList<int>, TypeList<char, int, bool>>::Set[1] == 1);
    static_assert(Bitset<TypeList<int>, TypeList<char, int, bool>>::Set[0] == 0);

    static_assert(Bitset<TypeList<int>, TypeList<int, char, float, bool>>::Set.size() == 4);
    static_assert(Bitset<TypeList<int>, TypeList<int, char, float, bool>>::Set[0] == 0);
    static_assert(Bitset<TypeList<int>, TypeList<int, char, float, bool>>::Set[1] == 0);
    static_assert(Bitset<TypeList<int>, TypeList<int, char, float, bool>>::Set[2] == 0);
    static_assert(Bitset<TypeList<int>, TypeList<int, char, float, bool>>::Set[3] == 1);
}

#endif //JML_BITSET_HPP
