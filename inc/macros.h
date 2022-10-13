#pragma once

#ifndef MAX
#define MAX(x, y)           \
    ({                      \
        typeof(x) _x = (x); \
        typeof(y) _y = (y); \
        (void)(&_x == &_y); \
        _x > _y ? _x : _y;  \
    })
#endif

#ifndef MIN
#define MIN(x, y)           \
    ({                      \
        typeof(x) _x = (x); \
        typeof(y) _y = (y); \
        (void)(&_x == &_y); \
        _x < _y ? _x : _y;  \
    })
#endif

// clang-format off
#ifndef TYPE_ID
#define TYPE_ID(x) _Generic((x),                   \
                            uint8_t  : "uint8_t",  \
                            uint16_t : "uint16_t", \
                            uint32_t : "uint32_t", \
                            uint64_t : "uint64_t", \
                            int8_t   : "int8_t",   \
                            int16_t  : "int16_t",  \
                            int32_t  : "int32_t",  \
                            int64_t  : "int64_t",  \
                            float    : "float",    \
                            double   : "double",   \
                            default  : "unknown")
#endif
// clang-format on

#define FIELD_SIZEOF(t, f) (sizeof(((t *)0)->f))

#define BUILD_BUG_ON_ZERO(e) (sizeof(char[1 - 2 * !!(e)]) - 1)

#define __must_be_array(a) BUILD_BUG_ON_ZERO(__builtin_types_compatible_p(typeof(a), typeof(&a[0])))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(a))
#define IS_ARRAY_PTR(p)    (!__builtin_types_compatible_p(typeof(p), typeof(&p[0])))

#ifndef LAMBDA
#define LAMBDA(return_type, Function_body) \
    ({                                     \
        return_type __fn__ Function_body   \
            __fn__;                        \
    })
#endif

#ifndef STRINGIZE
#define STRINGIZE(x) _STRINGIZE(x)
#define _STRINGIZE(x) #x
#endif

#ifndef CONCATE
#define CONCATE(x, y) _CONCATE(x, y)
#define _CONCATE(x, y) x##y
#endif

#ifndef COUNT_ARGS
#define COUNT_ARGS(args...) _COUNT_ARGS(_, ##args,      \
                                        10, 9, 8, 7, 6, \
                                        5, 4, 3, 2, 1,  \
                                        0)
#define _COUNT_ARGS(_,                  \
                    _0, _1, _2, _3, _4, \
                    _5, _6, _7, _8, _9, \
                    args...) _COUT_ARGS_FIRST(args)
#define _COUT_ARGS_FIRST(count, args...) count
#endif

#ifndef ENUM_CLASS
#define ENUM_CLASS(NAME, _ENUMS...) \
    typedef enum                    \
    {                               \
        _ENUMS                      \
    } _##NAME;                      \
    typedef struct                  \
    {                               \
        _##NAME _raw;               \
    } NAME
// #define ENUM_0 ((NAME){_ENUM_0})
// #define ENUM_1 ((NAME){_ENUM_1})
#define ENUM_EQ(x, value) ({typeof(x) _y = value; (void) _y; x._raw == _##value; })
#endif
