
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (len > 0)	
	{
		str[i] = s[i + start];
		i++;
		len--;
	}
	str[i] = '\0';

	return (str);
}