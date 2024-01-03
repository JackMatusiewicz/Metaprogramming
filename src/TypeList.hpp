#ifndef JML_TYPELIST_HPP
#define JML_TYPELIST_HPP

#include <cstdlib>

namespace JML {

    /**
     * A structure representing a list of types at compile time.
     * @tparam Ts - The list of types in the particular type list.
     */
    template<typename... Ts>
    struct TypeList {
        /**
         * The compile time count of the number of values inside the type list
         */
        static constexpr std::size_t Count = sizeof...(Ts);
    };

}

#endif //JML_TYPELIST_HPP
