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
void print_c(va_list args)
{
	char c = va_arg(args,char);
	printf("check on 'char' : %c\n",c);
	write(1, &c, 1);
	return ;
}
void print_s(va_list args)
{
	char	*str = va_arg(args, char *);
	size_t	i; 

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i ++;
	}
	return ;
}
void check(const char *str, size_t index, va_list args)
{	
	printf("checking on [ %c ]\n",str[index]);
	if (str[index] == 'c')
		print_c(args);
	else if (str[index] == 's')
		print_s(args);

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
	return (1);
}

int main()
{	
	char c = 'A';
	ft_printf("print a char  : %c",c);
	printf("\n");
	char str[] = "STR";
	ft_printf("print a char* : %s",str);
	printf("\n");
}
