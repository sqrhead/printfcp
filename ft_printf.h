#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *, ...);
void	check(const char *str, size_t *index, va_list args);
void	print_c(char c, size_t *index);
void	print_s(char *s, size_t *index);
void	print_p(void *p, size_t *index);
void	print_di(int i, size_t *index);
void    print_u(unsigned int ui, size_t *index);
void    print_xX(int i, int mode, size_t *index);
void    print_percent(size_t *index);
void	print_hex(unsigned long p, size_t *index);
void	print_hex_upper(unsigned long p, size_t *index);
void	print_dec(unsigned long n, size_t *index);

#endif
