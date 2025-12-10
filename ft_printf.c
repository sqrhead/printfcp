#include "ft_printf.h"


void check(const char *str, size_t *index, va_list args)
{
	if (str[*index] == 'c')
		print_c(args, index);
	else if (str[*index] == 's')
		print_s(args, index);
	else if (str[*index] == 'p')
		print_p(args, index);
	else if (str[*index] == 'd' || str[*index] == 'i')
		print_di(args, index);
	else if (str[*index] == 'u')
		print_u(args, index);
	else if (str[*index] == 'x')
		print_xX(args,0, index);
	else if (str[*index] == 'X')
		print_xX(args,1, index);
	else if (str[*index] == '%')
		print_percent(index);
	else
		return ;
}

int	ft_printf(const char *format, ...)
{
	size_t	index;
	va_list	args;

	index = 0;
	if (!format)
		return (index);
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			index ++;
			check(format, &index, args);
			index ++;
			// return (*index);
		}
		write(1,&format[index],1);
		index ++;
	}

	va_end(args);
	return (index);
}

#include <limits.h>
int main()
{
	char c = 'A';
	char str[] = "STR";
	ft_printf("ft_printf { char }  : %c\n",c);
	ft_printf("ft_print { char*} : %s\n",str);
	printf("printf { char*} : %s\n",str);
	ft_printf("ft_printf { void* }  : %p\n",&str);
	printf("printf { void* } : %p\n",&str);
	int num = -130;
	printf("printf { decimal base 10 } %d\n",num);
	printf("printf { integer base 10 } %i\n",num);
	ft_printf("ft_printf { decimal base 10 } %d\n",num);
	ft_printf("ft_printf { integer base 10 } %i\n",num);
	unsigned int un = INT_MIN;
	printf("printf {unsigned int }  %u\n",un);
	ft_printf("ft_printf { unsigned int } %u\n",un);
	int hn = -2030; // 128808997
	printf("printf { hex lower } %x\n",hn);
	printf("printf { hex upper } %X\n",hn);
	ft_printf("ft_printf { hex lower } %x\n",hn);
	ft_printf("ft_printf { hex upper } %X\n",hn);
	printf("printf { percent } %%\n");
	ft_printf("ft_printf { percent } %%\n");
}
