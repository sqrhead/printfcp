#include "ft_printf.h"


int check(const char *str, size_t index, va_list args)
{
	if (str[index] == 'c')
		return (print_c(va_arg(args, int)));
	else if (str[index] == 's')
		return (print_s(va_arg(args, char *)));
	else if (str[index] == 'p')
		return (print_p(va_arg(args, void *)));
	else if (str[index] == 'd' || str[index] == 'i')
		return (print_di(va_arg(args, int)));
	else if (str[index] == 'u')
		return (print_u(va_arg(args, unsigned int)));
	else if (str[index] == 'x')
		return (print_xX(va_arg(args, int),0));
	else if (str[index] == 'X')
		return (print_xX(va_arg(args, int),1));
	else if (str[index] == '%')
		return (print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	index;
	int	total_count; 
	va_list	args;

	va_start(args, format);
	index = 0;
	total_count = 0;
	if (!format)
		return (-1);
	while (format[index])
	{
		if (format[index] == '%' && format[index + 1])
		{
			total_count += check(format, ++index, args);
			index += 1;
		}
		else
		{
			write(1,&format[index++],1);
			total_count ++;
		}
	}
	va_end(args);
	return (total_count);
}

/*
#include <limits.h>
int main()
{
	char		*str = "str_test";
	unsigned int	ui = 20;
	int		i = -20;
	int		hex = 120410519;
	int		len = 0;

	printf("========= FT_PRINTF ==================\n");
	len =	ft_printf("CHAR %c%c%c\n",str[0],str[1],str[2]);
	ft_printf("CHAR LEN %i\n",len);
	printf("======================================\n");
	len =	ft_printf("STR %s\n",str);
	ft_printf("STR LEN %i\n",len);
	printf("======================================\n");
	len =	ft_printf("PTR_ADDRESS %p\n",str);
	ft_printf("PTR LEN %i\n",len);
	printf("======================================\n");
	len =	ft_printf("INT %i\n",i);
	ft_printf("INT LEN %i\n",len);
	printf("======================================\n");
	len =	ft_printf("DEC %d\n",INT_MIN);
	ft_printf("DEC LEN %i\n",len);
	printf("======================================\n");
	len =	ft_printf("UNSIGNED INT %u\n",ui);
	ft_printf("UI LEN %i\n",len);
	printf("======================================\n");
	len =	ft_printf("HEX_MIN %x\n",hex);
	ft_printf("HEXM LEN %i\n",len);
	printf("======================================\n");
	len =	ft_printf("HEX_UPP %X\n",hex);
	ft_printf("HEXU LEN %i\n",len);
	printf("======================================\n");
	len =	ft_printf("PERCENT %%\n");
	ft_printf("PER LEN %i\n",len);
	printf("======================================\n");
	printf("========= PRINTF ==================\n");
	len = printf("CHAR %c%c%c\n",str[0],str[1],str[2]);
	printf("CHAR LEN %i\n",len);
	printf("======================================\n");
	len = printf("STR %s\n",str);
	printf("STR LEN %i\n",len);
	printf("======================================\n");
	len = printf("PTR_ADDRESS %p\n",str);
	printf("PTR LEN %i\n",len);
	printf("======================================\n");
	len = printf("INT %i\n",i);
	printf("INT LEN %i\n",len);
	printf("======================================\n");
	len = printf("DEC %d\n",i);
	printf("DEC LEN %i\n",len);
	printf("======================================\n");
	len = printf("UNSIGNED INT %u\n",ui);
	printf("UI LEN %i\n",len);
	printf("======================================\n");
	len = printf("HEX_MIN %x\n",hex);
	printf("HEXM LEN %i\n",len);
	printf("======================================\n");
	len = printf("HEX_UPP %X\n",hex);
	printf("HEXU LEN %i\n",len);
	printf("======================================\n");
	len = printf("PERCENT %%\n");
	printf("PER LEN %i\n",len);
	printf("======================================\n");
}
*/
