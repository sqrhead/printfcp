#include "ft_printf.h"

int	print_p(void *p)
{
	int	count;
	
	if (!p)
	{
		count = 5;
		write(1, "(nil)", 5);
		return (count);	
	}
	count = 2;
	write(1,"0x",2);
	print_hex((unsigned long)p, &count);
	return (count);
}

int	print_s(char *s)
{
	size_t	i;
	int	count;
	
	i = 0;
	count = 0;
	if (!s)
	{
		write(1,"(null)",6);
		count = 6;
		return (count);
	}
	while (s && s[i])
	{
		write(1, &s[i], 1);
		i ++;
		count ++;
	}
	return (count);
}

int	print_c(char c)
{
	// char c = va_arg(*args, unsigned int); // char give error, check why
	int	count;
	
	count = 1;
	write(1, &c, 1);
	return (count);
	
}

int	print_di(int i)
{
	unsigned int	num;
	int		count;

	num = 0;
	count = 0;
	if (i < 0)
	{
		write(1,"-",1);
		count ++;
		i = i * -1;
	}
	num = (unsigned int)i;
	print_dec(num, &count);
	return (count);
}

int	print_u(unsigned int ui)
{	
	int	count;
	
	count = 0;
	print_dec(ui, &count);
	return (count);
}
