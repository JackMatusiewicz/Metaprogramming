#ifndef JML_AGGREGATE_HPP
#define JML_AGGREGATE_HPP

#include "TypeList.hpp"

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

    static_assert(
        std::is_same_v<Aggregate<std::tuple, TypeList<int, float>>::Result, TypeList<std::tuple<int, float>>>,
        "these are the same");
}

#endif //JML_AGGREGATE_HPP
