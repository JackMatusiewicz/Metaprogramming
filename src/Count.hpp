#ifndef JML_COUNT_HPP
#define JML_COUNT_HPP

#include <type_traits>

#include "TypeList.hpp"
#include "TypeMatch.hpp"

namespace JML {

    template<typename T, typename...Ts>
    struct Count : std::integral_constant<std::size_t, 0> {};

    template<typename T, typename H, typename...Ts>
    struct Count<T, TypeList<H, Ts...>>
        : std::integral_constant<std::size_t, (TypeMatch<T,H>{} ? 1 : 0) + Count<T, TypeList<Ts...>>{}> {};

    static_assert(Count<int, TypeList<int, int, bool, int>>::value == 3);
    static_assert(Count<int, TypeList<int, int, bool>>::value == 2);
    static_assert(Count<int, TypeList<char, float, bool>>::value == 0);
}

#endif //JML_COUNT_HPP
