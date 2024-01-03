#ifndef JML_SUBSET_HPP
#define JML_SUBSET_HPP

#include "TypeList.hpp"
#include "Unique.hpp"
#include "Contains.hpp"

#include "Concat.hpp"

namespace JML {

    template<typename, typename>
    struct Subset;

    template<typename... Ts, typename... Us>
    requires unique_elements<Ts...> && unique_elements<Us...>
    struct Subset<TypeList<Ts...>, TypeList<Us...>>
        : std::integral_constant<bool, ContainsAll<TypeList<Ts...>, TypeList<Us...>>::value> {
    };

    template<typename, typename>
    constexpr bool is_subset_v = false;

    template<typename... Ts, typename... Us>
    constexpr bool is_subset_v<TypeList<Ts...>, TypeList<Us...>> = Subset<TypeList<Ts...>, TypeList<Us...>>::value;

    // For some reason I cannot get this to work properly, investigate this further when I find some time.
    template<typename...As, typename... Bs>
    concept is_subset = is_subset_v<TypeList<As...>, TypeList<Bs...>>;

    static_assert(
        Subset<TypeList<int, float>, TypeList<int, float, char>>::value == true,
        "(int, float) should be a subset of (int, float, char)");

    static_assert(
        Subset<TypeList<int>, TypeList<float, char, bool>>::value == false,
        "(int) should not be a subset of (float, char, bool)");
}


#endif //JML_SUBSET_HPP
