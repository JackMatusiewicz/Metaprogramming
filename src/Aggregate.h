#ifndef JML_AGGREGATE_H
#define JML_AGGREGATE_H

#include "TypeList.h"

namespace JML {
    template<template<typename> class, typename...>
    struct Aggregate;

    /**
     * Applies a higher kinded type, F, to all the type parameters in Ts.
     * <p />
     * For example:
     *      Aggregate\<std::tuple, TypeList\<int, float\>\>::Result = TypeList\<std::tuple\<int, float\>\>
     * @tparam F - The higher kinded type to apply to all of the types in Ts.
     * @tparam Ts - The types to be applied to F
     */
    template<template<typename> class F, typename... Ts>
    struct Aggregate<F, TypeList<Ts...>> {
        using Result = TypeList<F<Ts...>>;
    };
}

#endif //JML_AGGREGATE_H
