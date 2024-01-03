#ifndef JML_REPEAT_H
#define JML_REPEAT_H

#include "TypeList.h"
#include "Concat.h"

namespace JML {
    template<unsigned int, typename, typename...>
    struct RepeatHelper;

    template<typename T, typename... Ts>
    struct RepeatHelper<0u, T, TypeList<Ts...>> {
        using Result = TypeList<Ts...>;
    };

    template<unsigned int i, typename T, typename... Ts>
    struct RepeatHelper<i, T, TypeList<Ts...>> {
        using Result = RepeatHelper<i - 1, T, typename Concat<TypeList<T>, TypeList<Ts...>>::Result>::Result;
    };

    template<unsigned int i, typename T>
    using Repeat = RepeatHelper<i, T, TypeList<>>::Result;

    static_assert(std::is_same_v<Repeat<4, int>, TypeList<int, int, int, int>>);
}

#endif //JML_REPEAT_H
