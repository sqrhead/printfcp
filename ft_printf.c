#include "ft_printf.h"

size_t	print_until(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			return (i);
		write(1,&str[i],1);
		i ++;
	}
	return (0);
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

int main()
{
	char c = 'A';
	char c2 = '@';
	ft_printf("print a char  : %c",c);
	printf("\n");
	char str[] = "STR";
	char str2[] = "STR2";
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
}
