/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:10:54 by wfung             #+#    #+#             */
/*   Updated: 2017/04/14 17:42:04 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//newest
//with multiple[fd] does not work i dont think
//replacing b after every call
//copied ft_ptrlen and ft_cpychr from gnl1

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

char	*ft_cpychr(char *str, int c, int len)
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
	b[len + 1] = '\0';
	return (b);
}

int		get_next_line(const int fd, char **line)
{
	static char		*b[1000];
	char			*hold;
	char			*next;
	char			tmp[BUFF_SIZE + 1];
	int				count;

	int read_attempt;
	read_attempt = 1;

	next = NULL;
	hold = NULL;
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, tmp, 0) < 0)
		return (-1);
	printf("gnl newest start\n");
	while ((count = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		printf("while read_attempt = [%i]\n", read_attempt);
		tmp[count] = '\0';
		b[fd] == NULL ? (b[fd] = ft_strdup(tmp)) :
			(b[fd] = ft_strjoin(b[fd], tmp));
		printf("b[fd] = [%s]\n", b[fd]);
		read_attempt++;
	}
	next = ft_strchr(b[fd], 10) != NULL ?
		(*line = ft_cpychr(b[fd], 10, ft_ptrlen(b[fd], next, ft_strlen(b[fd]))))
		: (*line = ft_strdup(b[fd]));
	if (ft_memcmp(*line, b[fd], ft_strlen(*line)) == 0)
		return (0);
	hold = ft_strsub(b[fd], ft_ptrlen(b[fd], next, ft_strlen(b[fd])),
			ft_strlen(b[fd] - ft_strlen(*line)));
	b[fd] = ft_strdup(hold);
	free(hold);
	return (0);
}
