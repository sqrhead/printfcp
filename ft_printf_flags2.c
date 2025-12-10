#include "ft_printf.h"

void    print_xX(va_list args, int mode, size_t *index)
{
    int n;

    n = va_arg(args, int);

    if (mode == 0) // min
    {
        print_hex((unsigned int)n, index);
    }
    if (mode == 1)
    {
        print_hex_upper((unsigned int)n, index);
    }
}

void    print_percent(size_t *index)
{
    write(1,"%",1);
    *index ++;
}