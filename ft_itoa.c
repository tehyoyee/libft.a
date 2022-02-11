/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 14:27:39 by taehykim          #+#    #+#             */
/*   Updated: 2022/01/30 17:58:48 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_len(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	find_sign(int n)
{
	if (n >= 0)
		return (0);
	return (1);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	long	nbr;
	char	*ret;

	nbr = n;
	sign = find_sign(n);
	len = find_len(n);
	len += sign;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (sign == 1)
		nbr *= -1;
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign == 1)
		ret[0] = '-';
	return (ret);
}
