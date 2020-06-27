#pragma once

#include "include/keagull/utility.hpp"

namespace keagull
{

    template <class T, class Lock>
    class synchronized
    {
        class acquired;

    public:
        synchronized(T resource, Lock lock)
            : m_resource(move(resource)), m_lock(move(lock))
        {
        }

        acquired acquire()
        {
            return acquired(m_resource, m_lock);
        }

    private:
        T m_resource;
        Lock m_lock;

        class acquired
        {
        public:
            acquired(T &resource, Lock &lock)
                : m_resource(resource), m_lock(lock)
            {
                m_lock.lock();
            }

            ~acquired()
            {
                m_lock.unlock();
            }

            T *get()
            {
                return &m_resource;
            }

            T *operator->()
            {
                return &m_resource;
            }

            T &operator*()
            {
                return m_resource;
            }

        private:
            T &m_resource;
            Lock &m_lock;
        };
    };
} // namespace keagull
