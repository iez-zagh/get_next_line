/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:08:44 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/12/29 17:01:52 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr(const char *str, int c)
{
	int	i;
	int	len;

	len = ft_strlen((char *)str);
	i = 0;
	while (len >= 0)
	{
		if (str[i] == (char)c)
			return (i);
		i++;
		len--;
	}
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	res = NULL;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	len = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		res[len++] = s2[i++];
	}
	res[len] = '\0';
	free ((char *)s1);
	return (res);
}

// char	*ft_strdup(const char *str)
// {
// 	char	*str2;
// 	size_t	len;
// 	int		i;

// 	i = 0;
// 	len = ft_strlen(str);
// 	str2 = malloc(sizeof(char) * (len + 1));
// 	if (!str2)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		str2[i] = str[i];
// 		i++;
// 	}
// 	str2[i] = '\0';
// 	return (str2);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t		i;
// 	size_t		len_s;
// 	char		*res;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (start >= (unsigned int)ft_strlen(s))
// 		return (ft_strdup(""));
// 	len_s = ft_strlen(&s[start]);
// 	if (len_s < len)
// 		len = len_s;
// 	res = malloc(sizeof(char) * (len + 1));
// 	if (!res)
// 		return (NULL);
// 	s = s + start;
// 	while (s[i] != '\0' && len > 0)
// 	{
// 		res[i] = s[i];
// 		i++;
// 		len--;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }
// int main()
// {
// 	char d[] = "hello world";
// 	printf ("%s\n", ft_strjoin(d, " 1337"));
// 	printf ("%s", ft_strjoin(d, " 42 the network"));
// }