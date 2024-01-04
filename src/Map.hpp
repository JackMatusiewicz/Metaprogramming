#ifndef JML_MAP_HPP
#define JML_MAP_HPP

#include <vector>

#include "TypeList.hpp"

namespace JML {

    template<template<typename> class, typename...>
    struct Map;

    /**
     * Applies a higher kinded type, F, to each type parameter in Ts.
     * <p />
     * For example:
     *      Map\<std::vector, TypeList\<int, float\>\>::Result = TypeList\<std::vector\<int\>, std::vector\<float\>\>
     * @tparam F - The higher kinded type (such as std::vector)
     * @tparam Ts - The types you want the higher kinded type applied to.
     */
    template<template <typename> class F, typename... Ts>
    struct Map<F, TypeList<Ts...>> {
        using Result = TypeList<F<Ts>...>;
    };

    static_assert(
        std::is_same_v<Map<std::vector, TypeList<int, float>>::Result, TypeList<std::vector<int>, std::vector<float>>>,
        "Mapping std::vector over <int, float> should result in <vector<int>, vector<float>>");
}

#endif //JML_MAP_HPP
