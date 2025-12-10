#include "ft_printf.h"

size_t	print_until(const char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (-1);
	while (str[index])
	{
		if (str[index] == '%')
			return (index);
		write(1,&str[index],1);
		index ++;
	}
	return (index);
}

void check(const char *str, size_t index, va_list args)
{
	if (str[index] == 'c')
		print_c(args);
	else if (str[index] == 's')
		print_s(args);
	else if (str[index] == 'p')
		print_p(args);
	else if (str[index] == 'd' || str[index] == 'i')
		print_di(args);
	else if (str[index] == 'u')
		print_u(args);
	else if (str[index] == 'x')
		print_xX(args,0);
	else if (str[index] == 'X')
		print_xX(args,1);
	else if (str[index] == '%')
		print_percent();
}

int	ft_printf(const char *str, ...)
{
	size_t	index;
	va_list	args;
	va_start(args,str);
	index = print_until(str);
	index ++;
	check(str,index,args);

	va_end(args);
	return (index);
}

#include <limits.h>
int main()
{
	char c = 'A';
	ft_printf("print a char  : %c",c);
	printf("\n");
	char str[] = "STR";
	ft_printf("print a char* : %s",str);
	printf("\nprintf a char* : %s\n",str);
	printf("printf void* : %p\n",&str);
	printf("print void*  : %p",&str);
	printf("\n");
	int num = -130;
	int num2 = 2100;
	printf("printf d %d\n",num);
	printf("printf i %i\n",num);
	ft_printf("print d %d\n",num);
	printf("\n");
	ft_printf("print i %i\n",num2);
	printf("\n");
	unsigned int un = INT_MIN;
	printf("printf unsigned int %u\n",un);
	ft_printf("ft_printf unsigned int %u\n",un);
	printf("\n");
	int hn = -2030; // 128808997
	printf("printf hexnum %x\n",hn);
	printf("printf hexnum_upper %X\n",hn);
	ft_printf("ft_printf hexnum %x",hn);
	printf("\n");
	ft_printf("ft_printf hexnum_upper %X",hn);
	printf("\n");
	printf("printf percent %%\n");
	ft_printf("ft_printf percent %%");
	printf("\n");
}
