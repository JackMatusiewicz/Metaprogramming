#ifndef JML_INDEX_HPP
#define JML_INDEX_HPP

#include <numeric>
#include <string>

#include "TypeList.hpp"

namespace JML {
    // Finds the first index of the type in a type list, left-to-right.
    template<typename, typename...>
    struct Index;

    template<typename, typename...>
    struct Index {
        static constexpr int value = 0;
        static constexpr bool found = false;
    };

    template<typename T, typename... Ts>
    struct Index<T, TypeList<T, Ts...>> {
        static constexpr int value = 0;
        static constexpr bool found = true;
    };

    template<typename T, typename H, typename... Ts>
    struct Index<T, TypeList<H, Ts...>> {
        static constexpr int value = 1 + Index<T, TypeList<Ts...>>::value;
        static constexpr bool found = value < TypeList<H, Ts...>::Count;
    };

    static_assert(Index<int, TypeList<int, float, bool>>::value == 0 && Index<int, TypeList<int, float, bool>>::found == true);
    static_assert(Index<int, TypeList<char, float, bool, int>>::value == 3 && Index<int, TypeList<int, float, bool>>::found == true);
    static_assert(Index<int, TypeList<char, int, int, bool>>::value == 1 && Index<int, TypeList<int, float, bool>>::found == true);
    static_assert(Index<std::string, TypeList<char, int, int, bool>>::value == 4 && Index<std::string, TypeList<char, int, int, bool>>::found == false);
}

#endif //JML_INDEX_HPP
