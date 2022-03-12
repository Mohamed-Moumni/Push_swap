/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:58:59 by mmoumni           #+#    #+#             */
/*   Updated: 2022/03/12 18:56:07 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end_check(char *dest)
{
	if (ft_strlen(dest) == 0)
	{
		free(dest);
		return (1);
	}
	return (0);
}

char	*read_line(char *static_buff, int fd)
{
	char	*buffer;
	int		n;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	n = 1;
	while (n > 0 && ft_strchr(static_buff, '\n') == NULL)
	{	
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[n] = '\0';
		if (n == 0)
			break ;
		static_buff = ft_strjoin(static_buff, buffer);
	}
	free(buffer);
	return (static_buff);
}

char	*get_line(char *backup)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (backup[len] != '\n' && backup[len] != '\0')
		len++;
	if (backup[len] == '\n')
	{
		len = len + 1;
	}
	line = malloc(sizeof(char) *(len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*backup_func(char *backup)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (backup[len] != '\n' && backup[len] != '\0')
		len++;
	if (backup[len] == '\0')
	{
		free(backup);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(backup) - len + 1));
	if (!dest)
		return (NULL);
	while (backup[++len])
		dest[i++] = backup[len];
	dest[i] = '\0';
	free(backup);
	if (end_check(dest))
		return (NULL);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_line(backup, fd);
	if (backup == NULL)
		return (NULL);
	line = get_line(backup);
	backup = backup_func(backup);
	return (line);
}
