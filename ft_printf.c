#include "ft_printf.h"


void check(const char *str, size_t *index, va_list args)
{
	if (str[*index] == 'c')
		print_c(va_arg(args, int), index);
	else if (str[*index] == 's')
		print_s(va_arg(args, char *), index);
	else if (str[*index] == 'p')
		print_p(va_arg(args, void *), index);
	else if (str[*index] == 'd' || str[*index++] == 'i')
		print_di(va_arg(args, int), index);
	else if (str[*index] == 'u')
		print_u(va_arg(args, unsigned int), index);
	else if (str[*index] == 'x')
		print_xX(va_arg(args, int),0, index);
	else if (str[*index] == 'X')
		print_xX(va_arg(args, int),1, index);
	else if (str[*index] == '%')
		print_percent(index);
	else
		return ;
}

int	ft_printf(const char *format, ...)
{
	size_t	index;
	size_t	s_len; // quando loopo sulla stringa aumento l index ma non e' il valore reale di format
	va_list	args;

	va_start(args, format);
	index = 0;
	s_len = 0;
	if (!format)
		return (index);
	while (format[s_len])
	{
		if (format[s_len] == '%')
		{	
			s_len ++;
			index ++;
			check(format, &index, args);
			index ++;
			s_len ++;
		}
		write(1,&format[s_len],1);
		index ++;
		s_len ++;
	}

	va_end(args);
	return (index);
}

#include <limits.h>
int main()
{
	char c = 'A';
	char str[] = "splash";
	char *strnull = NULL;
	printf("########### c s ###################### \n");
	ft_printf("ft_printf { char }  : %c\n",c);
	ft_printf("ft_print { char*} : %s\n",str);
	printf("printf { char*} : %s\n",str);
	printf("########### p ######################### \n");
	printf("printf { void* } : %p\n",&str);
	ft_printf("ft_printf { void* }  : %p\n",&str);
	printf("########### D & I ##################### \n");
	int num = -130;
	printf("printf { decimal base 10 } %d\n",num);
	printf("printf { integer base 10 } %i\n",num);
	ft_printf("ft_printf { decimal base 10 } %d\n",num);
	ft_printf("ft_printf { integer base 10 } %i\n",num);
	printf("########## U ########################## \n");
	unsigned int un = INT_MIN;
	printf("printf {unsigned int }  %u\n",un);
	ft_printf("ft_printf { unsigned int } %u\n",un);
	printf("######### X x  ######################## \n");
	int hn = -2030; // 128808997
	printf("printf { hex lower } %x\n",hn);
	printf("printf { hex upper } %X\n",hn);
	ft_printf("ft_printf { hex lower } %x\n",hn);
	ft_printf("ft_printf { hex upper } %X\n",hn);
	printf("######## % ########################### \n");
	printf("printf { percent } %%\n");
	ft_printf("ft_printf { percent } %%\n");
}
