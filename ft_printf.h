#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *, ...);
void	check(const char *str, size_t *index, va_list args);
void	print_c(va_list args, size_t *index);
void	print_s(va_list args, size_t *index);
void	print_p(va_list args, size_t *index);
void	print_di(va_list args, size_t *index);
void	print_hex(unsigned long p, size_t *index);
void	print_hex_upper(unsigned long p, size_t *index);
void	print_dec(unsigned long n, size_t *index);
void    print_u(va_list args, size_t *index);
void    print_xX(va_list args, int mode, size_t *index);
void    print_percent(size_t *index);

#endif
