
#include "libft.h"
#include <stdio.h>
int	word_cmp(char a, char b);

char	**ft_malloc_fail(char **ret)
{
	size_t	i;

	i = 0;
	while(ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

int count_size(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (!word_cmp(*s, c))
		{
			cnt++;
		}
		s++;
	}
	return (cnt);
}

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
				return (ft_malloc_fail(ret));
			ft_strlcpy(ret[i], s - size, size + 1);
			i++;
		}
		s++;
	}
	ret[i] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	arr_num;

	i = 0;
	arr_num = 0;
	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (count_size(s, c) + 1));
	if (!ret)
		return (NULL);
	return (split_operate(s, c, ret));
}

int	main(void)
{
	char	arr[30] = "       olol";
	char	**a;

	a = ft_split(arr, ' ');
	for (int i = 0; a[i]; i++)
	{
		printf("%s\n", a[i]);
	}
}
