/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:30:41 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/12/29 10:38:08 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_one_line(char *str, int j)
{
	int		i;
	char	*str2;

	i = 0;
	// while (str[i] != '\n')
	// 	i++;
	// while (str[i])
	// {
	// 	if (str[i] == '\n')
	// 	{
	// 		j = i;
	// 		i = 0;
	// 		str2  = malloc (j + 1);
	// 		if (!str2)
	// 			return (NULL);
	// 		while (i < j)
	// 		{
	// 			str2[i] = str[i];
	// 			i++;
	// 		}
	// 		str2[i] = '\0';
	// 		return (str2);
	// 	}
	// 	i++;
	// }
	str2 = malloc(j + 1);
	while (i < j)
	{
			str2[i] = str[i];
			i++;
	}
	str2[i] = '\0';
	// free(str2);
	return (str2);
}

char	*ft_read(int fd)
{
	int		u;
	int		j;
	char	*str;
	char	*buffer;

	j = 0;
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		u = read(fd, str, BUFFER_SIZE);
		if (u == -1)  // proctection for (0)
			return (free(str), NULL);
		str[u] = '\0';
		j = ft_strchr(str, '\n');//printf ("%d", j);
		if (j != 0)
			return (ft_one_line(str, j));
		else
		{
			buffer = ft_strjoin(buffer, str);
			j = ft_strchr(buffer, '\n');
			if (j != 0)
			{
				free(buffer);
				return (ft_one_line(buffer, j));
				free (str);
			}
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	//static char	*res;
	char		*line;
	char		*str;

	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		line = ft_read(fd);
		return (line);
	}
	else
		return (NULL);
}

int main()
{
	int u = open("file.txt", O_RDONLY);
	char *res = get_next_line(u);
	printf("%s", res);
	free(res);
	close(u);
}
