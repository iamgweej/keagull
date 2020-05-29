#pragma once

#include "include/keagull/utility.hpp"

namespace keagull
{
    template <class Iterable, class IterableProxy>
    auto operator>>(Iterable iterable, IterableProxy proxy)
    {
        return proxy.forward_iterable(iterable);
    }
} // namespace keagull
