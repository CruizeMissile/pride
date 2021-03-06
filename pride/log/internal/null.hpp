
#pragma once

namespace pride::log::internal
{
struct null_mutex
{
    void lock() {}
    void unlock() {}
    bool try_lock() { return true; }
};
} // namespace pride::log::internal
