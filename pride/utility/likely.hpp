
#pragma once

#include "../config.hpp"
namespace pride
{
#if defined(PRI_COMPILER_CLANG) || defined(PRI_COMPILER_GCC)
    inline constexpr auto likely(bool x) noexcept
    {
        return __builtin_expect(x, true);
    }

    inline constexpr auto unlikely(bool x) noexcept
    {
        return __builtin_expect(x, false);
    }
#else
    inline constexpr auto likely(bool x) noexcept
    {
        return x;
    }

    inline constexpr auto unlikely(bool x) noexcept
    {
        return x;
    }
#endif
}
