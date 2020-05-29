#pragma once

#include "include/keagull/utility.hpp"

namespace keagull
{
    template <class _BinaryFunction, class T>
    class fold
    {
    public:
        fold(_BinaryFunction f, T initial) : m_f(f), m_initial(initial) {}

        template <class Iterable>
        auto forward_iterable(Iterable it)
        {
            T ret = m_initial;
            it.while_predicate([&ret = ret, f = m_f](auto &&x) { ret = f(ret, forward<decltype(x)>(x)); return true; });
            return ret;
        }

    private:
        _BinaryFunction m_f;
        T m_initial;
    };
} // namespace keagull