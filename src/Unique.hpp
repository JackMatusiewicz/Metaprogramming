#ifndef JML_UNIQUE_HPP
#define JML_UNIQUE_HPP

#include <type_traits>

#include "TypeList.hpp"
#include "Count.hpp"

namespace JML {

    template<typename BaseCase>
    struct UniqueInner : std::integral_constant<bool, true> {};

    template<typename T, typename... Ts>
    struct UniqueInner<JML::TypeList<T, Ts...>>
        : std::integral_constant<bool, Count<T, JML::TypeList<Ts...>>{} == 0 && UniqueInner<JML::TypeList<Ts...>>{}>
    {};

    template<typename... Ts>
    struct Unique : UniqueInner<JML::TypeList<Ts...>> {
        using SetTypes = TypeList<Ts...>;
    };

    template<typename... Ts>
    concept unique_elements = Unique<Ts...>::value;

    static_assert(Unique<int, float, bool>::value == true);
}

#endif //JML_UNIQUE_HPP
