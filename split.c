#include "push_swap.h"

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_word_count(char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = ft_word_len(s, c);
		s += i;
		if (i)
			w++;
	}
	return (w);
}

static char	*ft_word_cpy(char const *src, int i)
{
	char	*dest;

	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	dest[i] = '\0';
	while (i--)
		dest[i] = src[i];
	return (dest);
}

static char	**free_split(char **str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		size;
	int		i;
	int		n;

	if (!s)
		return (NULL);
	size = ft_word_count(s, c);
	p = malloc((size + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*s && *s == c)
			s++;
		n = ft_word_len(s, c);
		if (*s)
			p[i] = ft_word_cpy(s, n);
		if (!p[i])
			return (free_split(p, i));
		s += n;
	}
	p[size] = 0;
	return (p);
}

