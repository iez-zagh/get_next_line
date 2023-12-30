/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:30:41 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/12/30 13:10:05 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_one_line(char *str, int j)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = malloc(j + 1);
	while (i < j)
	{
			str2[i] = str[i];
			i++;
	}
	str2[i] = '\0';
	free(str);
	return (str2);
}

char	*ft_read(int fd)
{
	int		u;
	int		j;
	char	*str;
	char	*buffer;

	j = 0;
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (free(buffer), NULL);
	while ((u = read(fd, str, BUFFER_SIZE)) >= 0)
	{
		// str[u] = '\0';
		// j = ft_strchr(buffer, '\n');
		// if (j != 0)
		// {
		// 	char *line = ft_one_line(buffer, j);//printf ("%s\n", buffer);
    	// 	free(str);
    	// 	return line;
		// }
		// else
		// {
		// 	buffer = ft_strjoin(buffer, str);
		// 	if (!buffer)
		// 		return (free(str), NULL);
		// 	j = ft_strchr(buffer, '\n');
		// }
		str[u] = '\0';
		buffer = ft_strjoin(buffer, str);
		j = ft_strchr(buffer, '\n');
		if (j != 0)
		{
			char *line = ft_one_line(buffer, j);//printf ("%s\n", buffer);
    		free(str);
    		return (line);
		}
	}
	return (free(buffer), free(str), NULL);
}
char	*get_next_line(int fd)
{
	//static char	*res;
	char		*line;

	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		line = ft_read(fd);
		//
		return (line);
	}
	else
		return (NULL);
}

// void	f()
// {
// 	system("leaks a.out");
// }
// int main()
// {
// 	//atexit(f);
// 	int u = open("file.txt", O_RDONLY);
// 	char *res = get_next_line(u);
// 	printf("%s\n", res);
// 	free(res);
// 	close(u);
// 	// while (1);
// }
