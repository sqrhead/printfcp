#include "ft_printf.h"

int	print_xX(int i, int mode)
{
	int	count;

	count = 0;
	if (mode == 0)
		print_hex((unsigned int)i, &count);
	if (mode == 1)
		print_hex_upper((unsigned int)i, &count);
	return (count);
}

int	print_percent(void)
{
	int	count;

	count = 1;
	write(1, "%", 1);
	return (count);
}
