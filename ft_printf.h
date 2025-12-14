#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		check(const char *str, size_t index, va_list args);
int		print_c(char c);
int		print_s(char *s);
int		print_p(void *p);
int		print_di(int i);
int		print_u(unsigned int ui);
int		print_xx(int i, int mode);
int		print_percent(void);
void	print_hex(unsigned long p, int *count);
void	print_hex_upper(unsigned long p, int *count);
void	print_dec(unsigned long n, int *count);

#endif
