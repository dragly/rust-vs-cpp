
// Typical resource holder.
// Objective: Make it movable.
// Can it be done without adding runtime state and branching?
template<typename Mutex>
class Guard
{
public:
    explicit Guard(Mutex& mutex)
        : m_mutex(mutex)
    {
        m_mutex.lock();
    }

    ~Guard()
    {
        m_mutex.unlock();
    }

    Guard(const Guard&) = delete;
    Guard& operator=(const Guard&) = delete;

private:
    Mutex& m_mutex;
};
