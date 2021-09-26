/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:32:59 by yoyoo             #+#    #+#             */
/*   Updated: 2021/05/31 20:47:04 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cut_line(char **backup, char **line, int newline_idx)
{
	char *temp;

	(*backup)[newline_idx] = '\0';
	*line = ft_strdup(*backup);
	if (*line == NULL)
	{
		free(*backup);
		return (-1);
	}
	if ((*backup)[newline_idx + 1] == 0)
	{
		free(*backup);
		*backup = NULL;
		return (1);
	}
	temp = ft_strdup(*backup + newline_idx + 1);
	if (temp == NULL)
	{
		free(*backup);
		return (-1);
	}
	free(*backup);
	*backup = temp;
	return (1);
}

int	remainder_return(char **backup, char **line)
{
	int newline_idx;

	if (*backup == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if ((newline_idx = ft_strchri(*backup, '\n')) >= 0)
	{
		cut_line(backup, line, newline_idx);
		return (1);
	}
	else
	{
		*line = *backup;
		*backup = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static	char	*backup[FD_MAX] = {0, };
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	int				newline_idx;

	if (fd < 0 || fd > FD_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (backup[fd] != NULL && (newline_idx = ft_strchri(backup[fd], '\n')) >= 0)
		return (cut_line(&backup[fd], line, newline_idx));
	while ((read_size = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (read_size < 0)
			return (-1);
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if (backup[fd] == NULL)
			return (-1);
		if ((newline_idx = ft_strchri(backup[fd], '\n')) >= 0)
			return (cut_line(&backup[fd], line, newline_idx));
	}
	return (remainder_return(&backup[fd], line));
}
