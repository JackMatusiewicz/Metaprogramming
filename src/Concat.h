#ifndef JML_CONCAT_H
#define JML_CONCAT_H

#include "TypeList.h"

namespace JML {

    template<typename, typename>
    struct Concat;

    /**
     * Enables the concatenation of two type lists, with the resulting type list having the types of the first
     * type list parameter followed by the types of the second type list parameter.
     * <p />
     * For example: Concat\<TypeList\<int, float\>, TypeList\<char\>\>::Result => TypeList\<int, float, char\>
     * @tparam As - The type parameters in the first type list.
     * @tparam Bs - The type parameters in the second type list.
     */
    template<typename... As, typename... Bs>
    struct Concat<TypeList<As...>, TypeList<Bs...>> {
        using Result = TypeList<As..., Bs...>;
    };

    static_assert(
        std::is_same_v<Concat<TypeList<int, float>, TypeList<char, bool>>::Result, TypeList<int, float, char, bool>>,
        "Concatenating <int, float> to <char, bool> should equal <int, float, char, bool>");

}

#endif //JML_CONCAT_H
