#include "ft_printf.h"

void	print_hex(unsigned long p)
{
	static const char	hex[] = "0123456789abcdef";

	if (p >= 16)
		print_hex(p / 16);
	write(1, &hex[p % 16], 1);
}

void	print_dec(long n)
{
	static const char	dec[] = "0123456789";

	if (n >= 10)
		print_dec(n / 10);
	write(1, &dec[n % 10], 1);
}
