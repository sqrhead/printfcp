#include "ft_printf.h"

void print_p(void *p, size_t *index)
{
	void	*pul;

	pul = va_arg(*args, void *);
	write(1,"0x",2);
	*index += 2;
	print_hex((unsigned long)pul, index);
}

void print_s(va_list *args, size_t *index)
{
	char	*str;
	size_t	i;

	str = va_arg(*args ,char *);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
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

void print_di(va_list *args, size_t *index)
{
	unsigned long 	num;
	int				arg;

	num = 0;
	arg = va_arg(*args, int);
	if (!arg)
		printf("NULL_ARGS\n");
	if (arg < 0)
	{
		write(1,"-",1);
		*index += 1;
		arg = arg * -1;
	}
	num = (unsigned long)arg;
	print_dec(num, index);
}

void print_u(va_list *args, size_t *index)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	print_dec(n, index);
}
