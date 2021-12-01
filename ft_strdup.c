/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehykim <taehykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:13:25 by taehykim          #+#    #+#             */
/*   Updated: 2021/12/01 11:44:00 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*arr;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	arr = (char *)malloc(sizeof(char) * i + 1);
	arr[i] = '\0';
	i--;
	while (i >= 0)
	{
		arr[i] = s1[i];
		i--;
	}
	return (arr);
}
