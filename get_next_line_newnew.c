/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:38:21 by wfung             #+#    #+#             */
/*   Updated: 2017/04/17 15:57:52 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//newest
//with multiple oes not work i ont think
//replacing b ater every call
//copie t_ptrlen an t_cpychr rom gnl1

int		ft_ptrlen(char *p1, char *p2, int len)
{
	int		i;
	char	*b;

	i = 0;
	b = p1;
	if (len == 0)
		return (0);
	while (b != p2 && i < len)
	{
		b++;
		i++;
	}
	return (i);
}

char		*ft_cpychr(char *str, int c, int len)
{
	int		i;
	char	*b;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (!(b = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(b, len + 1);
	while (str[i] != (char)c && i < len)
	{
		b[i] = str[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}

int				get_next_line(const int fd, char **line)
{
	static char		*b;
	char			*hold;
	char			*next;
	char			tmp[BUFF_SIZE + 1];
	int				count;

	next = NULL;
	hold = NULL;
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, tmp, 0) < 0)
		return (-1);
	while ((count = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[count] = '\0';
		b == NULL ? (b = ft_strdup(tmp)) : (b = ft_strjoin(b, tmp));
	}
	(next = ft_strchr(b, 10)) != NULL ? (*line = ft_cpychr(b, 10, ft_ptrlen(b, next, ft_strlen(b))))
		: (*line = ft_strdup(b));
	if (ft_strlen(b) > ft_strlen(*line))
	{
		hold = ft_strsub(b, ft_ptrlen(b, next + 1, ft_strlen(b)), ft_strlen(b) - ft_strlen(*line));
		free(b);
		b = ft_strdup(hold);
		free(hold);
		return (1);
	}
	return (0);
}
