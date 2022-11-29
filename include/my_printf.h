/*
** EPITECH PROJECT, 2022
** my_printf.h
** File description:
** my_printf header
*/

#ifndef my_printf_h
    #define my_printf_h
    #include <stdarg.h>

int my_printf(const char * format, ...);
int check_specifier(char specifier);
int is_identifier(const char *format, int index);
int is_str_contains_modifiers(const char *format);
char is_all_identifiers_valid(const char *format);
int is_int_positive(va_list arg);
int is_double_positive(va_list arg);
int put_octal_prefix(va_list arg);
int put_hex_prefix(va_list arg);
int put_hex_maj_prefix(va_list arg);
int threat_per(va_list arg);
int threat_bin(va_list arg);
int threat_hex(va_list arg);
int threat_hex_maj(va_list arg);
int threat_int(va_list arg);
int threat_char(va_list arg);
int threat_str(va_list arg);
int threat_octal(va_list arg);
int threat_unsign_int(va_list arg);
int disp_nbr_unsigned(unsigned int nb);
int my_put_nbr_unsigned(unsigned int nb);
int threat_scientific_double(va_list arg);
int threat_scientific_double_maj(va_list arg);
int threat_decimal_double(va_list arg);
int threat_ipvar(va_list arg);
int threat_shorter_double(va_list arg);
int threat_shorter_double_maj(va_list arg);
int threat_space(va_list arg, char const *format, int index);
int threat_positive(va_list arg, char const *format, int index);
int threat_hashtag(va_list arg, char const *format, int index);
int is_specifier(char flag);
char get_format_flag(char const *format, int *index);
int get_width_modifier(va_list arg, char const *format, int *index);
char get_specifier(char const *format, int *index);
int handle_specifier(va_list arg, char const *format, int *index, int len);
int handle_flags(va_list arg, char const *format, int *index, int len);
int threat_modulo(va_list arg);
int get_int_len(va_list arg);
int get_unsigned_len(va_list arg);
int get_octal_len(va_list arg);
int get_hex_len(va_list arg);
int get_bin_len(va_list arg);
int get_str_len(va_list arg);
int get_scientific_double_len(va_list arg);
int get_decimal_double_len(va_list arg);
int get_ipvar_len(va_list arg);
int get_shorter_double_len(va_list arg);
int return_one(va_list arg);
int get_specifier_length(va_list arg, char const *format, int *index);
int get_base_prefix_len(char c);
void jveuxdormirwlh(long ent, long dec, int jade);

#endif
