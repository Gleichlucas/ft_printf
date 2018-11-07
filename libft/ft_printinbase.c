#include "libft.h"

void	ft_printinbase(int base, int nb)
{
	if (nb >= base)
	{
		ft_printinbase(base, nb / base);
		ft_printinbase(base, nb % base);
	}
	else
		if (nb >= 10)
			ft_putchar(nb + 'A' - 10);
		else
			ft_putnbr(nb);
}
