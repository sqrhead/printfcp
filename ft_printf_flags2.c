#include "ft_printf.h"

void    print_xX(va_list args, int mode)
{
    int n;

    n = va_arg(args, int);

    if (mode == 0) // min
    {
        print_hex((unsigned int)n);
    }
    if (mode == 1)
    {
        print_hex_upper((unsigned int)n);
    }
}

void    print_percent()
{
    write(1,"%",1);
}