#ifndef JML_TYPEMATCH_H
#define JML_TYPEMATCH_H

#include <type_traits>

namespace JML {
    template<typename, typename>
    struct TypeMatch;

    template<typename T, typename U>
    struct TypeMatch : std::integral_constant<bool, false> {};

    template<typename T>
    struct TypeMatch<T,T> : std::integral_constant<bool, true> {};
}

#endif //JML_TYPEMATCH_H
