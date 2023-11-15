#ifndef JML_TOTYPE_H
#define JML_TOTYPE_H

#include "TypeList.h"

namespace JML {

    template<typename>
    struct ToType;

    /**
     * Pulls the single type from the TypeList that is holding a single type, TypeList\<T\>
     * <p />
     * For example: TypeList\<int\>::Result => int
     * @tparam T - The type being pulled out of the type list.
     */
    template<typename T>
    struct ToType<TypeList<T>> {
        // The type being pulled out of the single element TypeList
        using Result = T;
    };

}

#endif //JML_TOTYPE_H
