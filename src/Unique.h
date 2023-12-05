#ifndef JML_UNIQUE_H
#define JML_UNIQUE_H

#include <type_traits>

#include "TypeList.h"
#include "Count.h"

namespace JML {
    template<typename, typename...>
    struct Unique;

    template<typename T, typename... Ts>
    struct Unique : std::integral_constant<bool, true> {};

    template<typename T, typename U, typename... Ts>
    struct Unique<T, U, Ts...> : std::integral_constant<bool, Count<T, TypeList<U, Ts...>>{} == 0 && Unique<T, Ts...>{}> {};

    template<typename T, typename... Ts>
    concept UniqueSet = Unique<T, Ts...>{};
}

#endif //JML_UNIQUE_H
