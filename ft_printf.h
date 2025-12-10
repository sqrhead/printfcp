#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int		ft_printf(const char *, ...);
void	print_c(va_list args);
void	print_s(va_list args);
void	print_p(va_list args);
void	print_di(va_list args);
void	print_hex(unsigned long p);
void	print_hex_upper(unsigned long p);
void	print_dec(unsigned long n);
void    print_u(va_list args);
void    print_xX(va_list args, int mode);
void    print_percent();

#endif
