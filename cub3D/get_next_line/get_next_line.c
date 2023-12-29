/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taelkhal <taelkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:08:59 by taelkhal          #+#    #+#             */
/*   Updated: 2023/11/26 15:55:15 by taelkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_next_line(char *line)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	str = ft_substr(line, (i + 1), ft_strlen(line));
	free(line);
	line = NULL;
	return (str);
}

char	*ft_line(char **line)
{
	int	i;

	i = 0;
	if (line[0][i] == '\0')
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	while (line[0][i] != '\n' && line[0][i] != '\0')
		i++;
	return (ft_substr(*line, 0, (i + 1)));
}

char	*ft_read_line(int fd, char *line)
{
	ssize_t	i;
	char	*buff;

	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	while (!ft_strchr(line) && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(line);
			line = NULL;
			return (NULL);
		}
		buff[i] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, line);
	if (line == NULL)
		return (NULL);
	str = ft_line(&line);
	if (str == NULL)
		return (NULL);
	line = ft_next_line(line);
	return (str);
}
// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	int i = 0;
// 	char *line;
// 	int fd = open ("../maps/map.ber", O_RDONLY | 0777);
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd);
// 	// 	printf ("%s",line);
// 		i++;
// 	}
// 	// close (fd);
// 	// // system("leaks a.out");
// 	// return (0);
// }
