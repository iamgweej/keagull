#pragma once

#include "include/keagull/utility.hpp"

namespace keagull
{
    template <class _UnaryFunction>
    class transform
    {

        template <class _Iterable>
        class _transform_iterable;

    public:
        transform(_UnaryFunction f) : m_f(f) {}

        template <class Iterable>
        auto forward_iterable(Iterable it)
        {
            return _transform_iterable(it, m_f);
        }

    private:
        _UnaryFunction m_f;

        template <class _Iterable>
        class _transform_iterable
        {
        public:
            _transform_iterable(_Iterable it, _UnaryFunction f) noexcept : m_it(it), m_f(f) {}

            template <class __UnaryPredicate>
            void while_predicate(__UnaryPredicate p) noexcept
            {
                m_it.while_predicate([p = p, f = m_f](auto &&x) { return p(f(forward<decltype(x)>(x))); });
            }

        private:
            _Iterable m_it;
            _UnaryFunction m_f;
        };
    };
} // namespace keagull
