
#pragma once

#include "utils.hpp"

#define PRIDE_PP_IMPL_BOOL(mx) PRIDE_PP_IMPL_BOOL_##mx
#define PRIDE_PP_BOOL(mx) PRIDE_PP_IMPL_BOOL(mx)

#define PRIDE_PP_IMPL_BITNOT_0 1
#define PRIDE_PP_IMPL_BITNOT_1 0

#define PRIDE_PP_IMPL_BITAND_00 0
#define PRIDE_PP_IMPL_BITAND_01 0
#define PRIDE_PP_IMPL_BITAND_10 0
#define PRIDE_PP_IMPL_BITAND_11 1

#define PRIDE_PP_IMPL_BITOR_00 0
#define PRIDE_PP_IMPL_BITOR_01 1
#define PRIDE_PP_IMPL_BITOR_10 1
#define PRIDE_PP_IMPL_BITOR_11 1

#define PRIDE_PP_IMPL_BITNOR_00 1
#define PRIDE_PP_IMPL_BITNOR_01 0
#define PRIDE_PP_IMPL_BITNOR_10 0
#define PRIDE_PP_IMPL_BITNOR_11 0

#define PRIDE_PP_IMPL_BITXOR_00 0
#define PRIDE_PP_IMPL_BITXOR_01 1
#define PRIDE_PP_IMPL_BITXOR_10 1
#define PRIDE_PP_IMPL_BITXOR_11 0

#define PRIDE_PP_BITNOT(mx) \
    PRIDE_PP_CAT_2(PRIDE_PP_IMPL_BITNOT_, PRIDE_PP_DEFER(mx))

#define PRIDE_PP_BITAND(m0, m1) \
    PRIDE_PP_CAT_3(PRIDE_PP_IMPL_BITAND_, PRIDE_PP_DEFER(m0), PRIDE_PP_DEFER(m1))

#define PRIDE_PP_BITOR(m0, m1) \
    PRIDE_PP_CAT_3(PRIDE_PP_IMPL_BITOR_, PRIDE_PP_DEFER(m0), PRIDE_PP_DEFER(m1))

#define PRIDE_PP_BITNOR(m0, m1) \
    PRIDE_PP_CAT_3(PRIDE_PP_IMPL_BITNOR_, PRIDE_PP_DEFER(m0), PRIDE_PP_DEFER(m1))

#define PRIDE_PP_BITXOR(m0, m1) \
    PRIDE_PP_CAT_3(PRIDE_PP_IMPL_BITXOR_, PRIDE_PP_DEFER(m0), PRIDE_PP_DEFER(m1))

#define PRIDE_PP_IMPL_NOT(mx) PRIDE_PP_BITNOT(PRIDE_PP_BOOL(mx))
#define PRIDE_PP_IMPL_AND(m0, m1) PRIDE_PP_BITAND(PRIDE_PP_BOOL(m0), PRIDE_PP_BOOL(m1))
#define PRIDE_PP_IMPL_OR(m0, m1) PRIDE_PP_BITOR(PRIDE_PP_BOOL(m0), PRIDE_PP_BOOL(m1))
#define PRIDE_PP_IMPL_NOR(m0, m1) PRIDE_PP_BITNOR(PRIDE_PP_BOOL(m0), PRIDE_PP_BOOL(m1))
#define PRIDE_PP_IMPL_XOR(m0, m1) PRIDE_PP_BITXOR(PRIDE_PP_BOOL(m0), PRIDE_PP_BOOL(m1))

#define PRIDE_PP_NOT(mx) PRIDE_PP_IMPL_NOT(mx)
#define PRIDE_PP_AND(m0, m1) PRIDE_PP_IMPL_AND(m0, m1)
#define PRIDE_PP_OR(m0, m1) PRIDE_PP_IMPL_OR(m0, m1)
#define PRIDE_PP_NOR(m0, m1) PRIDE_PP_IMPL_NOR(m0, m1)
#define PRIDE_PP_XOR(m0, m1) PRIDE_PP_IMPL_XOR(m0, m1)

#define PRIDE_PP_IMPL_IF_0(mTrue, mFalse) mFalse
#define PRIDE_PP_IMPL_IF_1(mTrue, mFalse) mTrue
#define PRIDE_PP_IF(cond, mTrue, mFalse)                   \
    PRIDE_PP_CAT_2(PRIDE_PP_IMPL_IF_, PRIDE_PP_BOOL(cond)) \
    (mTrue, mFalse)

#define PRIDE_PP_COMMA_IF(cond)                       \
    PRIDE_PP_IF(cond, PRIDE_PP_COMMA, PRIDE_PP_EMPTY) \
    ()
