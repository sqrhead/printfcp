#include "ft_printf.h"

void print_p(va_list args)
{
	void	*pul;

	pul = va_arg(args, void *);
	write(1,"0x",2);// start
	print_hex((unsigned long)pul);
	return ;
}

void print_s(va_list args)
{
	char	*str;
	size_t	i;

	str = va_arg(args ,char *);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
	return ;
}

void print_c(va_list args)
{
	char c = va_arg(args, unsigned int); // char give error, check why
	write(1, &c, 1);
	return ;
}

void print_di(va_list args)
{
	unsigned long 	num;
	int		arg;
	
	num = 0;
	arg = 0;
	arg = va_arg(args, int);
	if (arg < 0)
	{
		write(1,"-",1);
		arg = arg * -1; 	
	}
	num = (unsigned long)arg;
	print_dec(num);
}

void print_u(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	print_dec(n);
}
