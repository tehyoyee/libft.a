
#include "libft.h"
#include <stdio.h>

void	ft_strncpy(char *dest, char const *src, int n)
{
	int i;

	i = 0;
	while (*src && i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
}

int	word_cmp(char a, char b)
{
	if (a == b)
		return (1);
	return (0);
}

int	find_c(char const *s, char c)
{
	int	result;

	result = 0;
	while (*s)
	{
		if (*s == c)
			result++;
		s++;
	}
	return (result);
}

char	**split_operate(char const *s, char c, char **ret)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while(*s)
	{
		if (!word_cmp(*s, c))
		{
			size = 0;
			while (*s && !word_cmp(*s, c))
			{
				size++;
				s++;
			}
			ret[i] = (char *)malloc(sizeof(char) * (size + 1));
			if (!ret[i])
				return (0);
			ft_strncpy(ret[i], s - size, size);
			i++;
		}
		s++;
	}
	ret[i] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (0);
	if (!c)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (ft_strlen(s) - find_c(s, c) + 1));
	if (!ret)
		return (0);
	return (split_operate(s, c, ret));
}

int	main(void)
{
	char	arr[50] = "asdfgYasdfYasdfYasdFYsdf";
	char	c = 'Y';
	char	**str;
	int 	i = 0;
	str = ft_split(arr, c);
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}