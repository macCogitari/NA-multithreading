#pragma once

#include <atomic>

class spinlock
{
public:
    void lock()
    {
        while(!try_lock())
        {
            asm volatile ("pause" : : : "memory");
        }
    }

    bool try_lock()
    {
        return !_locked.exchange(true);
    }

    void unlock()
    {
        assert(_locked); // błąd pre condition
                        // nie wolno wywołać dwa razy unlock
        _locked = false;
    }

private:
    std::atomic<bool> _locked{false};
};

