#pragma once

#include "include/keagull/utility.hpp"

namespace keagull
{

    template <class _UnaryPredicate>
    class all
    {
    public:
        all(_UnaryPredicate p) : m_p(p) {}

        template <class Iterable>
        bool forward_iterable(Iterable it)
        {
            bool ret = true;
            it.take_while([&r = ret, p = m_p](auto &&x) { return (r = p(forward<decltype(x)>(x))); });
            return ret;
        }

    private:
        _UnaryPredicate m_p;
    };

    template <class _UnaryPredicate>
    class none
    {
    public:
        none(_UnaryPredicate p) : m_p(p) {}

        template <class Iterable>
        bool forward_iterable(Iterable it)
        {
            bool ret = true;
            it.take_while([&r = ret, p = m_p](auto &&x) { return (r = !p(forward<decltype(x)>(x))); });
            return ret;
        }

    private:
        _UnaryPredicate m_p;
    };

    template <class _UnaryPredicate>
    class any
    {
    public:
        any(_UnaryPredicate p) : m_p(p) {}

        template <class Iterable>
        bool forward_iterable(Iterable it)
        {
            bool ret = false;
            it.take_while([&r = ret, p = m_p](auto &&x) { r = p(forward<decltype(x)>(x)); return !r; });
            return ret;
        }

    private:
        _UnaryPredicate m_p;
    };
} // namespace keagull