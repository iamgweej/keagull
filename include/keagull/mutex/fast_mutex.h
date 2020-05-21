#pragma once

#include <ntddk.h>

namespace keagull
{

    class fast_mutex
    {
    public:
        fast_mutex();
        
        void lock();
        void unlock();

    private:
        FAST_MUTEX m_mut;
    };

} // namespace keagull
