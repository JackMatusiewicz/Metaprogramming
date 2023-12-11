#ifndef JML_CONTAINS_H
#define JML_CONTAINS_H

#include <type_traits>

#include "TypeList.h"
#include "Count.h"

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
}

#endif //JML_CONTAINS_H
