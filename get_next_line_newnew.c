/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:38:21 by wfung             #+#    #+#             */
/*   Updated: 2017/04/18 16:20:20 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//newest
//added new function ft_lenchk (to fit norm)

int		ft_lenchk(char **s1, char **s2, char *ptr)	//&b, *line, next;
{
	char	*hold;

	hold = NULL;
	if (ft_strlen(*s1) > 0)
	{
		ptr = ft_strchr(*s1, 10);
		if (ptr != NULL)
		{
			*s2 = ft_cpychr(*s1, 10, ft_ptrlen(*s1, ptr, ft_strlen(*s1)));
			if (!*s2)
				return (-1);
			hold = ft_strsub(*s1, ft_ptrlen(*s1, ptr + 1, ft_strlen(*s1)), ft_strlen(*s1) - ft_strlen(*s2));
			if (!hold)
				return (-1);
			*s1 = NULL;
			*s1 = ft_strdup(hold);
			if (!*s1)
				return (-1);
			free(hold);
			hold = NULL;
		}
		else if (ptr == NULL)
		{
			*s2 = ft_strdup(*s1);
			if (!*s2)
				return (-1);
			*s1 = NULL;
	//	free(s1);
	//	*s1 = NULL;
		}
		return (1);
	}
//	*s2 = NULL;
	return (0);
}


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
	char			*next;
	char			*h;
	char			tmp[BUFF_SIZE + 1];
	int				count;

	next = NULL;
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, tmp, 0) < 0 || !line)
		return (-1);
	while ((count = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[count] = '\0';
		if (h == NULL)
		{
			h = ft_strdup(tmp);
		}
		else
		{
			h = ft_strjoin(b, tmp);
		}
		b = ft_strdup(h);
		if (ft_strchr(h, 10) != NULL)
			break;
	}
	return (b && ft_lenchk(&b, line, next));
}
