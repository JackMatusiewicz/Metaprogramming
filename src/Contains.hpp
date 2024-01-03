#ifndef JML_CONTAINS_HPP
#define JML_CONTAINS_HPP

#include <type_traits>

#include "TypeList.hpp"
#include "Count.hpp"

namespace JML {
    template <typename EmptyLeft, typename SetToCheck>
    struct ContainsInner : std::integral_constant<bool, true> {};

    template<typename H, typename... T, typename... Ts>
    struct ContainsInner<JML::TypeList<H, T...>, JML::TypeList<Ts...>>
            : std::integral_constant<
                    bool,
                    (Count<H, JML::TypeList<Ts...>>{} > 0) && ContainsInner<TypeList<T...>, TypeList<Ts...>>{}>
            {};

    template<typename Fst, typename Snd>
    using ContainsAll = ContainsInner<Fst, Snd>;

    static_assert(
        ContainsAll<JML::TypeList<int, float, char>, JML::TypeList<int, float, char, bool>>::value == true,
        "All elements of the first list are contained in the second");

    static_assert(
        ContainsAll<JML::TypeList<int, float, char>, JML::TypeList<int, float, char, bool>>::value == true,
        "All elements of the first list are contained in the second");

    static_assert(
        ContainsAll<JML::TypeList<>, JML::TypeList<int, float, char, bool>>::value == true,
        "Empty list should always be considered a match");
}

#endif //JML_CONTAINS_HPP
