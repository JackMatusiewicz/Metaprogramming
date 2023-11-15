#ifndef JML_HLIST_H
#define JML_HLIST_H

#include <memory>

namespace JML {

    template<typename, typename...>
    struct HList;

    // The HList element that represents the end of the list, nil.
    template<>
    struct HList<void> {};

    // The HList representing cons, with the head and tail.
    template<typename T, typename... Ts>
    struct HList {
    private:
        T _head;
        std::unique_ptr<HList<Ts...>> _tail;
    public:
        T& head() const noexcept { return _head; }
        HList<Ts...>& tail() const noexcept { return _tail; }

        explicit HList(T head, std::unique_ptr<HList<Ts...>> tail) : _head{head}, _tail{tail} {}
    };

}

#endif //JML_HLIST_H
