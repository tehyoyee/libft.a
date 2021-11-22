/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:14:33 by taehykim          #+#    #+#             */
/*   Updated: 2021/11/22 15:22:46 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return NULL;
}

int	main(void)
{
	char	a[20] = "show me the money";
	printf("%s", ft_strchr(a, 't'));
}
