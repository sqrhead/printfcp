#include "ft_printf.h"

void print_p(void *p, size_t *index)
{
	write(1,"0x",2);
	*index += 2;
	print_hex((unsigned long)p, index);
}

void print_s(char *s, size_t *index)
{
	size_t	i;
	
	i = 0;
	if (!s)
	{
		write(1,"(null)",6);
		return ;
	}
	while (s && s[i])
	{
		write(1, &s[i], 1);
		i ++;
	}
	*index += i;
}

void print_c(char c, size_t *index)
{
	// char c = va_arg(*args, unsigned int); // char give error, check why
	write(1, &c, 1);
	*index += 1;
}

void print_di(int i, size_t *index)
{
	unsigned long 	num;

	num = 0;
	// arg = va_arg(*args, int);
	if (i < 0)
	{
		write(1,"-",1);
		*index += 1;
		i = i * -1;
	}
	num = (unsigned long)i;
	print_dec(num, index);
}

void print_u(unsigned int ui, size_t *index)
{
	print_dec(ui, index);
}
