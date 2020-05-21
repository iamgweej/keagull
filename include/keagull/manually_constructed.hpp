#pragma once

#include "include/keagull/utility.hpp"
#include "include/keagull/new.h"

namespace keagull
{

    // TODO add (concept, metaprog) check for IsDestructible?
    // TODO add (concept, metaprog) check that for HasSize?
    // TODO add m_empty for "safety"
    // Notes:
    //  This class is provided to remedy the fact that a driver cannot have global constructors/destructors.
    //  Therefore, the use-case for this class is for wrapping safe resources (like RAII pointers) so that
    //  an explicit call to manually_constructed::destruct in DriverUnload would free them, by calling their dtor.
    //  The state of an manually_constructed instance after calling manually_constructed::destruct is undefined,
    //  and may cause undefined behaviour.
    template <class T>
    class manually_constructed
    {
    public:
        template <class... Args>
        inline void construct(Args &&... args)
        {
            new (m_data) T(forward<Args>(args)...);
        }

        inline void destruct()
        {
            reinterpret_cast<T *>(m_data)->~T();
        }

        inline T *operator->() noexcept
        {
            return reinterpret_cast<T *>(m_data);
        }

        inline T &operator*() noexcept
        {
            return *reinterpret_cast<T *>(m_data);
        }

    private:
        alignas(T) char m_data[sizeof(T)];
    };

} // namespace keagull
