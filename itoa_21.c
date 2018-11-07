#include "ft_printf.h"

static int		ft_itoa_size2(long long int *n, int *negative)
{
	long long int cpy;
	int size;


	size = 2;
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
		size++;
	}
	cpy = *n;
	while (cpy >= 10)
	{
		cpy /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa_2(long long int n, int *ret, int *neg)
{
	int			size;
	int			negative;
	char		*str;

	negative = 0;

	size = ft_itoa_size2(&n, &negative);
	*ret = size;
	if (!(str = (char*)malloc(size)))
		return (NULL);
	str[--size] = '\0';
	while (--size > 0)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		str[0] = '-';
	else
		str[0] = n % 10 + '0';
	*neg = negative;
	return (str);
}

static int		ft_itoa_size8(long long int *n, int *negative)
{
	long long int cpy;
	int size;

	size = 2;
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
		size++;
	}
	cpy = *n;
	while (cpy >= 8)
	{
		cpy /= 8;
		size++;
	}
	return (size);
}

char			*ft_itoa_8(long long int n, int *ret, int *neg)
{
	int			size;
	int			negative;
	char		*str;

	negative = 0;
	size = ft_itoa_size8(&n, &negative);
	*ret = size;
	if (!(str = (char*)malloc(size)))
		return (NULL);
	str[--size] = '\0';
	while (--size > 0)
	{
		str[size] = n % 8 + '0';
		n /= 8;
	}
	if (negative)
		str[0] = '-';
	else
		str[0] = n % 8 + '0';
	*neg = negative;
	return (str);
}

static int		ft_itoa_size16(long long int *n, int *negative)
{
	long long int cpy;
	int size;

	size = 2;
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
		size++;
	}
	cpy = *n;
	while (cpy >= 16)
	{
		cpy /= 16;
		size++;
	}
	return (size);
}

char ft_conv(char a)
{
	if (a > 9)
		return (a - 10 + 'a');
	return (a + '0');
}

char			*ft_itoa_16(long long int n, int *ret, int *neg)
{
	int			size;
	int			negative;
	char		*str;

	negative = 0;
	size = ft_itoa_size16(&n, &negative);
	size += 2;

	*ret = size + 2;
	if (!(str = (char*)malloc(size)))
		return (NULL);
	str[--size] = '\0';
	while (--size > 0)
	{
		str[size] = ft_conv(n % 16);
		n /= 16;
	}
	if (negative)
		str[0] = '-';
	else
		str[0] = ft_conv(n % 16);
	*neg = negative;
	str[0] = '0';
	str[1] = 'x';
	return (str);
}
