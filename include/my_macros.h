/*
** EPITECH PROJECT, 2022
** my_macro_abs.h
** File description:
** ->   macro for absolute value
*/

#pragma once
#include <stddef.h>

#ifdef ABS
    #undef ABS
#endif
#define ABS(value) ((value) < 0 ? -(value) : (value))

#ifdef MIN
    #undef MIN
#endif
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#ifdef MAX
    #undef MAX
#endif
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#ifdef UNSIGNED_ABS
    #undef UNSIGNED_ABS
#endif
#define UNSIGNED_ABS(n1, n2) (ABS(MAX(n1, n2) - MIN(n1, n2)))

#ifdef FREE_IF_ALLOCATED
    #undef FREE_IF_ALLOCATED
#endif
#define FREE_IF_ALLOCATED(ptr, destructor) {    \
    if (ptr) {                                  \
        (destructor)(ptr);                      \
        (ptr) = NULL;                           \
    }                                           \
}

#ifdef FREE_ARRAY_UNTIL_END
    #undef FREE_ARRAY_UNTIL_END
#endif
#define FREE_ARRAY_UNTIL_END(array, length, destructor) {   \
    for (size_t i = 0; i < (length); i++) {                 \
        FREE_IF_ALLOCATED((array)[i], destructor)           \
    }                                                       \
    FREE_IF_ALLOCATED(array, free);                         \
}

#ifdef FREE_CONST_ARRAY_UNTIL_NULL
    #undef FREE_CONST_ARRAY_UNTIL_NULL
#endif
#define FREE_CONST_ARRAY_UNTIL_NULL(array, destructor) {      \
    for (size_t i = 0; (array) && (array)[i]; i++) {    \
        (destructor)((array)[i]);                       \
        (array)[i] = NULL;                              \
    }                                                   \
}

#ifdef FREE_ARRAY_UNTIL_NULL
    #undef FREE_ARRAY_UNTIL_NULL
#endif
#define FREE_ARRAY_UNTIL_NULL(array, destructor) {  \
    FREE_CONST_ARRAY_UNTIL_NULL(array, destructor); \
    FREE_IF_ALLOCATED(array, free);                 \
}

#ifdef REASSIGN_STATIC_ARRAY
    #undef REASSIGN_STATIC_ARRAY
#endif
#define REASSIGN_STATIC_ARRAY_FROM_VALUES(type, size, array, ...) { \
    type _tmp_array[size] = __VA_ARGS__;                            \
    for (size_t i = 0; i < (size); i++) {                           \
        (array)[i] = _tmp_array[i];                                 \
    }                                                               \
}

#ifdef REASSIGN_STATIC_ARRAY
    #undef REASSIGN_STATIC_ARRAY
#endif
#define REASSIGN_STATIC_ARRAY(type, size, array, new_array) {   \
    for (size_t i = 0; i < (size); i++) {                       \
        (array)[i] = (new_array)[i];                            \
    }                                                           \
}

#ifdef RETURN_IF
    #undef RETURN_IF
#endif
#define RETURN_IF(condition) {  \
    if (condition) {            \
        return;                 \
    }                           \
}

#ifdef RETURN_VALUE_IF
    #undef RETURN_VALUE_IF
#endif
#define RETURN_VALUE_IF(condition, return_value) {      \
    if (condition) {                                    \
        return (return_value);                          \
    }                                                   \
}

#ifdef ALLOC_PTR_ARRAY
    #undef ALLOC_PTR_ARRAY
#endif
#define ALLOC_PTR_ARRAY(ptr_type, n)                \
(ptr_type*)my_calloc_pointers(sizeof(ptr_type), (n))

#ifdef MAKE_ARRAY
    #undef MAKE_ARRAY
#endif
#define MAKE_ARRAY(...) \
({__VA_ARGS__})

#ifdef FILL_2D_ARRAY
    #undef FILL_2D_ARRAY
#endif
#define FILL_2D_ARRAY(array, n_lines, n_columns, ...)   {   \
    for (size_t y = 0; y < (n_lines); y++) {                \
        for (size_t x = 0; x < (n_columns); x++) {          \
            (array)[y][x] = __VA_ARGS__;                    \
        }                                                   \
    }                                                       \
}

#ifdef FREE_ALL
    #undef FREE_ALL
#endif
#define FREE_ALL(allocs, destructors, n)                    \
free_all((void*[(n)])allocs, (void*[(n)])destructors, (n))

#ifdef IS_NAN
    #undef IS_NAN
#endif
#define IS_NAN(x) ((x) != (x))
