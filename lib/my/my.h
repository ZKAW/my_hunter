/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my lib
*/

#ifndef my_h
    #define my_h

int my_char_isalpha(char c);
int count_words_amount(const char *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_unsigned(unsigned int nb);
int my_putnbr_base_long(long nbr, char const *base);
int my_doublelen(double nb);
void my_put_double(double nb, int precision);
void my_put_double_nt(double nb);
void my_put_scientific_double(double nb, int is_maj, int precision);
void my_put_scientific_double_nt(double nb, int is_maj);
int my_longlen(long value);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_pow(int nb, int power);
int my_sqrt(int nb);
int my_getnbr(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_revstr(char *str);
int my_putstr_err(char const *str);
void my_put_float(float nb);
int my_intlen(int value);
int my_intlen_unsigned(unsigned int value);
int my_doublelen(double nb);
int my_doublelen_nt(double nb);
int my_putnbr_base(int nbr, char const *base);
int my_putnbr_base_unsigned(unsigned int nbr, char const *base);
char *my_itoa(int nbr);
char *my_itoa_dest(char *dest, int nbr);
char *my_itoa_base(int nbr, char const *base, int i);
char *my_itoa_base_unsigned(unsigned int nbr, char const *base, int i);
char *my_itoa_base_unsigned_long(unsigned long nbr, char const *base, int i);
void my_put_hexa(unsigned int nb);
void my_put_hexa_long(unsigned long nb);
int count_nbr_digits(int nbr);
double round_double(double nb, int precision);
int my_strcmp(char const *s1, char const *s2);
int my_strcmp_ci(const char *str1, const char *str2);
char *my_strdup(char const *src);
char *my_strlowercase(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_tablen(char **tab);
char **reverse_tab(char **tab);
char *my_strstr(char *str, char const *to_find);
char *my_strstr_from(char *str, char const *to_find, int from);
char my_chartolower(char c);

#endif
