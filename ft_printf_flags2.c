#include "ft_printf.h"

void    print_xX(int i, int mode, size_t *index)
{

    if (mode == 0) 
    {
        print_hex((unsigned int)i, index);
    }
    if (mode == 1)
    {
        print_hex_upper((unsigned int)i, index);
    }
}

void    print_percent(size_t *index)
{
    write(1,"%",1);
    *index += 1;
}