
// Typical resource holder.
// Task 1: Make it movable.
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

// Task 2:
// Why would C++ have both std::lock_guard and std::unique_lock?
