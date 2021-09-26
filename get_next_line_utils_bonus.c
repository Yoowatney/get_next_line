/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:40:24 by yoyoo             #+#    #+#             */
/*   Updated: 2021/05/31 16:53:49 by yoyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strjoin_sub(char *s1, char *s2, char **ret)
{
	int i;

	i = 0;
	while (s1[i])
	{
		(*ret)[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		(*ret)[i] = *s2;
		s2++;
		i++;
	}
	(*ret)[i] = '\0';
	return ;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	ft_strjoin_sub(s1, s2, &ret);
	free(s1);
	return (ret);
}

int		ft_strchri(char *str, int c)
{
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	i = 0;
	while (1)
	{
		if (*str == (unsigned char)c)
			return (i);
		if (i == str_len)
			break ;
		str++;
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *s1)
{
	char	*ret;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	ret = (char *)malloc(ft_strlen(s1) + 1);
	if (!ret)
		return (NULL);
	while (i < s1_len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
