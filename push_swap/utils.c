
#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + (*str++ - '0');
	return (result * sign);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (*str++)
		counter++;
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	count;
	size_t	len_sub;

	if (ft_strlen(s) <= start)
		return (0);
	len_sub = ft_strlen(s + start);
	if (len_sub < len)
		len = len_sub;
	if (!(sub = (char *)malloc(len +1)))
		return (NULL);
	count = -1;
	while (++count < len)
		sub[count] = s[start + count];
	sub[count] = '\0';
	return (sub);
}


static	int	ft_len_of_word(char const *str, char c)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			counter++;
		while (*str != c && *str)
			str++;
	}
	return (counter);
}

static	void	ft_free(char **str)
{
	size_t	idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

static	char	**ft_return(char **arr, int idx)
{
	arr[idx] = 0;
	return (arr);
}

static	char	**ft_split_string(char **arr, char const *str, char c)
{
	int	idx;
	int	arr_idx;
	int	start;

	idx = 0;
	arr_idx = 0;
	while (str[idx])
	{
		while (str[idx] == c)
			idx++;
		start = idx;
		while (str[idx] != c && str[idx])
			idx++;
		if (idx > start)
		{
			arr[arr_idx] = ft_substr(str, start, idx - start);
			if (!arr[arr_idx])
			{
				ft_free(arr);
				return (NULL);
			}
			arr_idx++;
		}
	}
	return (ft_return(arr, arr_idx));
}

char	**ft_split(char const *str, char c)
{
	char	**arr;

	if (!(str) || !(arr = (char **)malloc((ft_len_of_word(str, c) + 1) * sizeof(char *))))
		return (NULL);
	arr = ft_split_string(arr, str, c);
	return (arr);
}


