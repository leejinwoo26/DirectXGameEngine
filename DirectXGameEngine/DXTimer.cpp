#include "DXTimer.h"


DXTimer::DXTimer()
{
    last = std::chrono::steady_clock::now();
}

float DXTimer::Mark()
{
    const auto  old = last;
    last = std::chrono::steady_clock::now();
    const std::chrono::duration<float> frameTime = last - old;
    return frameTime.count();
}

float DXTimer::Peek() const
{
    return std::chrono::duration<float>(std::chrono::steady_clock::now() - last).count();
}
