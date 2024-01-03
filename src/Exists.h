#ifndef JML_EXISTS_H
#define JML_EXISTS_H

#include <type_traits>

#include "TypeList.h"
#include "Count.h"

namespace JML {
    template<typename, typename...>
    struct Exists;

    template<typename T, typename...Ts>
    struct Exists<T, TypeList<Ts...>> :
        std::integral_constant<bool, (Count<T, TypeList<Ts...>>{} > 0)>{};

    static_assert(Exists<int, TypeList<int, float, char>>::value == true);
    static_assert(Exists<bool, TypeList<int, float, char>>::value == false);
}

#endif //JML_EXISTS_H
