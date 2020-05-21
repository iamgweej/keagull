#pragma once

namespace keagull
{

    template <class T>
    concept TriviallyLockable = requires(T a)
    {
        {
            a.lock()
        }
        ->void;
        {
            a.unlock()
        }
        ->void;
    };

} // namespace keagull
