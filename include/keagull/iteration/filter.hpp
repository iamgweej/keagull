#pragma once

#include "include/keagull/utility.hpp"

namespace keagull
{
    template <class _UnaryPredicate>
    class filter
    {

        template <class _Iterable>
        class _filter_iterable;

    public:
        filter(_UnaryPredicate p) : m_p(p) {}

        template <class Iterable>
        auto forward_iterable(Iterable it)
        {
            return _filter_iterable(it, m_p);
        }

    private:
        _UnaryPredicate m_p;

        template <class _Iterable>
        class _filter_iterable
        {
        public:
            _filter_iterable(_Iterable it, _UnaryPredicate p) noexcept : m_it(it), m_p(p) {}

            template <class __UnaryPredicate>
            void while_predicate(__UnaryPredicate p) noexcept
            {
                m_it.while_predicate([p = p, _p = m_p](auto &&x) {
                    if (_p(forward<decltype(x)>(x)))
                    {
                        return p(forward<decltype(x)>(x));
                    }
                    return true;
                });
            }

        private:
            _Iterable m_it;
            _UnaryPredicate m_p;
        };
    };
} // namespace keagull