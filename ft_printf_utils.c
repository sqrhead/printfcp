#include "ft_printf.h"

void	print_hex(unsigned long p, size_t *index)
{
	static const char	hex[] = "0123456789abcdef";

	if (p >= 16)
		print_hex(p / 16, index);
	write(1, &hex[p % 16], 1);
	*index += 1;
}

void	print_hex_upper(unsigned long p, size_t *index)
{
	static const char	hex_upper[] = "0123456789ABCDEF";

	if (p >= 16)
		print_hex_upper(p / 16, index);
	write(1, &hex_upper[p % 16], 1);
	*index += 1;
}

void	print_dec(unsigned long n, size_t *index)
{
	static const char	dec[] = "0123456789";

	if (n >= 10)
		print_dec(n / 10, index);
	write(1, &dec[n % 10], 1);
	*index += 1;
}
