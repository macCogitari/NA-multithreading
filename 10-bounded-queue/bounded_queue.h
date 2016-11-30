#pragma once

#include <cstddef>
#include <array>
#include <mutex>

template<typename T, std::size_t N>
class bounded_queue
{
public:
    void push_back(T t);
    T pop_front();
private:
    std::mutex _mtx;

    std::array<T,N> _buffer;
    std::size_t _front = 0;
    std::size_t _back = 0;
    std::size_t _size = 0;
};
