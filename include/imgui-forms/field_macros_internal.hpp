#pragma once

#define _EXPAND(x) x

// Pair count helper
#define COUNT_PAIRS_IMPL(                             \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,          \
    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
    _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
    _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
    _41, _42, _43, _44, COUNT, ...) COUNT

#define COUNT_PAIRS(...) COUNT_PAIRS_IMPL(__VA_ARGS__,                                                                                    \
                                          22, 22, 21, 21, 20, 20, 19, 19, 18, 18, 17, 17, 16, 16, 15, 15, 14, 14, 13, 13, 12, 12, 11, 11, \
                                          10, 10, 9, 9, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0)

#define CONCATENATE(a, b) CONCATENATE1(a, b)
#define CONCATENATE1(a, b) a##b

// Main FOR_EACH_PAIR dispatcher
#define _FOR_EACH_PAIR(M, ...) \
    _EXPAND(CONCATENATE(_FOR_EACH_PAIR_, COUNT_PAIRS(__VA_ARGS__))(M, __VA_ARGS__))

// Pair processors
#define _FOR_EACH_PAIR_1(M, f1, t1) M(f1, t1)
#define _FOR_EACH_PAIR_2(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_1(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_3(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_2(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_4(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_3(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_5(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_4(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_6(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_5(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_7(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_6(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_8(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_7(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_9(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_8(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_10(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_9(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_11(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_10(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_12(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_11(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_13(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_12(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_14(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_13(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_15(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_14(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_16(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_15(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_17(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_16(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_18(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_17(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_19(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_18(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_20(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_19(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_21(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_20(M, __VA_ARGS__)
#define _FOR_EACH_PAIR_22(M, f1, t1, ...) M(f1, t1) _FOR_EACH_PAIR_21(M, __VA_ARGS__)
