#include "ft_printf.h"


void check(const char *str, size_t *index, va_list args)
{
	if (str[*index] == 'c')
		print_c(va_arg(args, int), index);
	else if (str[*index] == 's')
		print_s(va_arg(args, char *), index);
	else if (str[*index] == 'p')
		print_p(va_arg(args, void *), index);
	else if (str[*index] == 'd' || str[*index] == 'i')
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
		if (format[s_len] == '%' && format[s_len + 1])
		{	
			s_len ++;
			index ++;
			check(format, &index, args);
		}
		else 
		{
			write(1,&format[s_len],1);
			index ++;
			s_len ++;
		}
	}

	va_end(args);
	return (index);
}
#include <limits.h>
int main()
{
	char		*str = "str_test";
	unsigned int	ui = 20;
	int		i = -20;
	int		hex = 120410519;
	int		len = 0;

	printf("========= FT_PRINTF ==================\n");
	len =	ft_printf("CHAR		%c%c%c\n",str[0],str[1],str[2]);
	ft_printf("CHAR LEN		%i\n",len);
	len =	ft_printf("STR		%s\n",str);
	ft_printf("STR LEN		%i\n",len);
	len =	ft_printf("PTR_ADDRESS	%p\n",str);
	ft_printf("PTR LEN		%i\n",len);
	len =	ft_printf("INT		%i\n",i);
	ft_printf("INT LEN		%i\n",len);
	len =	ft_printf("DEC		%d\n",i);
	ft_printf("DEC LEN		%i\n",len);
	len =	ft_printf("UNSIGNED INT	%u\n",ui);
	ft_printf("UI LEN		%i\n",len);
	len =	ft_printf("HEX_MIN	%x\n",hex);
	ft_printf("HEXM LEN		%i\n",len);
	len =	ft_printf("HEX_UPP	%X\n",hex);
	ft_printf("HEXU LEN		%i\n",len);
	len =	ft_printf("PERCENT	%%\n");
	ft_printf("PER LEN		%i\n",len);

	printf("========= PRINTF ==================\n");
	len = printf("CHAR		%c%c%c\n",str[0],str[1],str[2]);
	printf("CHAR LEN		%i\n",len);
	len = printf("STR		%s\n",str);
	printf("STR LEN			%i\n",len);
	len = printf("PTR_ADDRESS	%p\n",str);
	printf("PTR LEN			%i\n",len);
	len = printf("INT		%i\n",i);
	printf("INT LEN			%i\n",len);
	len = printf("DEC		%d\n",i);
	printf("DEC LEN			%i\n",len);
	len = printf("UNSIGNED INT	%u\n",ui);
	printf("UI LEN			%i\n",len);
	len = printf("HEX_MIN		%x\n",hex);
	printf("HEXM LEN		%i\n",len);
	len = printf("HEX_UPP		%X\n",hex);
	printf("HEXU LEN		%i\n",len);
	len = printf("PERCENT		%%\n");
	printf("PER LEN			%i\n",len);
	
}
