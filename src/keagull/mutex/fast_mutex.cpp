#include "include/keagull/mutex/fast_mutex.h"

namespace keagull
{
    fast_mutex::fast_mutex()
    {
        ExInitializeFastMutex(&m_mut);
    }

    void fast_mutex::lock()
    {
        ExAcquireFastMutex(&m_mut);
    }

    void fast_mutex::unlock()
    {
        ExReleaseFastMutex(&m_mut);
    }
} // namespace keagull