/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:45:39 by taehykim          #+#    #+#             */
/*   Updated: 2021/11/23 17:09:44 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	s += ft_strlen(s) - 1;
	while (*s--)
	{
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
