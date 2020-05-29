#pragma once

#include "include/keagull/utility.hpp"

namespace keagull
{
    template <class _UnaryFunction>
    class for_each
    {
    public:
        for_each(_UnaryFunction f) : m_f(f) {}

        template <class Iterable>
        void forward_iterable(Iterable it)
        {
            it.while_predicate([f = m_f](auto &&x) { f(forward<decltype(x)>(x)); return true; });
        }

    private:
        _UnaryFunction m_f;
    };
} // namespace keagull