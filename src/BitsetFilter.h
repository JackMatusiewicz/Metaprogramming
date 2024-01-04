#ifndef JML_BITSETFILTER_H
#define JML_BITSETFILTER_H

#include <bitset>

#include "Bitset.hpp"
#include "Subset.hpp"

namespace JML {

    template<unsigned long long N>
    static constexpr bool filter_matches(const std::bitset<N>& bs_to_check, const std::bitset<N>& base) {
        for(auto i = 0; i < N; ++i) {
            if (base[i] && !bs_to_check[i]) {
                return false;
            }
        }
        return true;
    }

    template<typename, typename, typename>
    struct BitsetFilter;

    template<typename... Ts, typename... Us, typename... Base>
    struct BitsetFilter<Bitset<TypeList<Ts...>, TypeList<Base...>>, Bitset<TypeList<Us...>, TypeList<Base...>>, void> {
        static constexpr bool FilterMatches =
            filter_matches(
                Bitset<TypeList<Ts...>, TypeList<Base...>>::Set,
                Bitset<TypeList<Us...>, TypeList<Base...>>::Set);
    };

    static_assert(
        BitsetFilter<
            Bitset<TypeList<int, float>, TypeList<int, char, float, bool>>,
            Bitset<TypeList<int, float>, TypeList<int, char, float, bool>>,
            void>::FilterMatches == true);

    static_assert(
        BitsetFilter<
            Bitset<TypeList<int, float>, TypeList<int, char, float, bool>>,
            Bitset<TypeList<int, bool>, TypeList<int, char, float, bool>>,
            void>::FilterMatches == false);
}

#endif //JML_BITSETFILTER_H
