#include "libft.h"

static char	ft_free2d(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != '\0')
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word++;
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (word);
		}
		i++;
	}
}

static char	ft_stralloc(char *str, char c)
{
	char	*word;
	int		k;

	k = 0;
	while (str[k] != '\0')
	{
		if (str[k] != c)
		{
			while (str[k] != '\0' && str[pos] != c)
				k++;
			word = (char *)malloc(sizeof(char) * (k + 1));
			if (word == NULL)
				return (NULL);
			break ;
		}
		k++;
	}
	k = 0;
	while (str[k] != c && str[k] != '\0')
	{
		word[k] = str[k];
		k++;
	}
	word[k] = '\0';
	return (word);
}

static int	ft_wordpos(int pos, char *str, char c)
{
	while (str[pos] != '\0')
	{
		if (str[pos] != c)
		{
			while (str[pos] != c && str[pos] != '\0')
			{
				pos++;
			}
			break ;
		}
		pos++;
	}
	return (pos);
}

char	**ft_split(char const *str, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		pos;

	if (str == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	j = ft_wordcount(str, c);
	strs = (char **)malloc(sizeof(char *) * (j + 1));
	if (strs == NULL)
		return (NULL);
	strs[j] = NULL;
	while (i < j)
	{
		strs[i] = ft_stralloc((str + pos), c);
		if (strs[i] == NULL)
		{
			return (ft_free2d(strs));
		}
		pos = ft_wordpos(pos, str, c);
		i++;
	}
	return (strs);
}
