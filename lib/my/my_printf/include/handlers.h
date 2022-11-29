/*
** EPITECH PROJECT, 2022
** myprintf
** File description:
** handlers
*/

#ifndef HANDLERS_H_
    #define HANDLERS_H_
    #include "../include/my_printf.h"

static int (*specifier_handlers[])(va_list) = {
    threat_modulo,
    threat_int,
    threat_int,
    threat_octal,
    threat_unsign_int,
    threat_hex,
    threat_hex_maj,
    threat_bin,
    threat_char,
    threat_str,
    threat_scientific_double,
    threat_scientific_double_maj,
    threat_decimal_double,
    threat_decimal_double,
    threat_ipvar,
    threat_shorter_double,
    threat_shorter_double_maj,
    return_one,
};

static int (*flags_format_handlers[])(va_list, char const *, int) = {
    threat_space,
    threat_positive,
    threat_space,
    threat_hashtag,
};

static int (*positive_table[])(va_list) = {
    is_int_positive,
    is_int_positive,
    is_double_positive,
    is_double_positive,
    is_double_positive,
    is_double_positive,
    is_double_positive,
    is_double_positive,
};

static int (*base_prefix[])(va_list) = {
    put_octal_prefix,
    put_hex_prefix,
    put_hex_maj_prefix,
};

// get length for each SPECIFIERS
static int (*specifier_length[])(va_list) = {
    return_one,
    get_int_len,
    get_int_len,
    get_octal_len,
    get_unsigned_len,
    get_hex_len,
    get_hex_len,
    get_bin_len,
    return_one,
    get_str_len,
    get_scientific_double_len,
    get_scientific_double_len,
    get_decimal_double_len,
    get_decimal_double_len,
    get_ipvar_len,
    get_shorter_double_len,
    get_shorter_double_len,
    return_one,
};

#endif /* !HANDLERS_H_ */
