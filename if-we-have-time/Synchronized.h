#pragma once

#include <mutex>

template<typename Mutex, typename Data>
class Synchronized
{
public:
    class Guard
    {
    public:
        Guard(Synchronized &synchronized)
            : m_ref(synchronized.m_data)
            , m_guard(synchronized.m_mutex)
        {}
        Data &data()
        {
            return m_ref;
        }

    private:
        Data &m_ref;
        std::lock_guard<Mutex> m_guard;
    };

    class ConstGuard
    {
    public:
        ConstGuard(const Synchronized &synchronized)
            : m_ref(synchronized.m_data)
            , m_guard(synchronized.m_mutex)
        {}
        const Data &data() const
        {
            return m_ref;
        }

    private:
        const Data &m_ref;
        std::lock_guard<Mutex> m_guard;
    };

public:
    Guard lock()
    {
        return { *this };
    }

    ConstGuard lock() const
    {
        return { *this };
    }

private:
    mutable Mutex m_mutex;
    Data m_data;
};
