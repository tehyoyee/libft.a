
#include "libft.h"
#include <stdio.h>

int	find_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	find_sign(int n)
{
	if (n >= 0)
		return (0);
	return (1);
}
char	*print_zero(void)
{
	char	*zero;
	int		i;

	i = 0;
	zero = (char *)malloc(sizeof(char) 	+ 1);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}
char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*ret;
	int		i;

	sign = find_sign(n);
	len = find_len(n);
	len += sign;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (sign == 1)
		n *= -1;
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len--] = n % 10 + '0';
		n /= 10;
	}
	if (sign == 1)
		ret[0] = '-';
	return (ret);
}

int	main(void)
{
	printf("%s\n", ft_itoa(001245));
	printf("%s\n", ft_itoa(-001352));
	printf("%s\n", ft_itoa(0));
}