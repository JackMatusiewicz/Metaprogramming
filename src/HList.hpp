#ifndef JML_HLIST_HPP
#define JML_HLIST_HPP

#include <memory>

namespace JML {

    template<typename, typename...>
    struct HList;

    // The HList representing cons, with the head and tail.
    template<typename T, typename... Ts>
    struct HList {
    private:
        T _head;
        std::shared_ptr<HList<Ts...>> _tail;
    public:
        T& head() const noexcept { return _head; }
        std::shared_ptr<HList<Ts...>>& tail() const noexcept { return _tail; }

        explicit HList(T&& head, std::shared_ptr<HList<Ts...>>&& tail) : _head{head}, _tail{tail} {}
    };

    // The HList element that represents the end of the list, holding the final value of the HList.
    template<typename T>
    struct HList<T> {
    private:
        T _head;
    public:
        explicit HList(T&& head) : _head{head} {}
        T& head() const noexcept { return _head; }
    };

    template<typename T>
    std::shared_ptr<HList<T>> singleton(T&& head) noexcept {
        return std::make_shared<HList<T>>(HList<T>{std::forward<T>(head)});
    }

    template<typename T, typename... Ts>
    std::shared_ptr<HList<T, Ts...>> cons(T head, std::shared_ptr<HList<Ts...>> tail) noexcept {
        return std::make_shared<HList<T, Ts...>>(HList<T, Ts...>{std::forward<T>(head), std::move(tail)});
    }

}

#endif //JML_HLIST_HPP
