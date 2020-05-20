#include "include\keagull\type_traits.hpp"

namespace keagull
{

    // std::move adaption
    template <class T>
    constexpr inline remove_reference_t<T> &&move(T &&t) noexcept
    {
        return static_cast<remove_reference_t<T> &&>(t);
    }

    // my implementation for std::forward
    template <class T>
    constexpr inline T &&forward(remove_reference_t<T> &t) noexcept
    {
        return static_cast<T &&>(t);
    }

    template <class T>
    constexpr inline T &&forward(remove_reference_t<T> &&t) noexcept
    {
        static_assert(!is_lvalue_reference_v<T>, "Can not forward an lvalue as an rvalue");
        return static_cast<T &&>(t);
    }
} // namespace keagull
