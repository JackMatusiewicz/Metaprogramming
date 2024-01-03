#ifndef JML_SUBSET_H
#define JML_SUBSET_H

#include "TypeList.h"
#include "Unique.h"
#include "Contains.h"

namespace JML {

    template<typename, typename>
    struct Subset;

    template<typename... Ts, typename... Us>
    requires unique_elements<Ts...> && unique_elements<Us...>
    struct Subset<TypeList<Ts...>, TypeList<Us...>>
        : std::integral_constant<bool, ContainsAll<TypeList<Ts...>, TypeList<Us...>>::value> {
    };

    static_assert(
        Subset<TypeList<int, float>, TypeList<int, float, char>>::value == true,
        "(int, float) should be a subset of (int, float, char)");

    static_assert(
        Subset<TypeList<int>, TypeList<float, char, bool>>::value == false,
        "(int) should not be a subset of (float, char, bool)");
}


#endif //JML_SUBSET_H
