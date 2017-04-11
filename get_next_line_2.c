/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:23:03 by wfung             #+#    #+#             */
/*   Updated: 2017/04/10 19:39:11 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_ptrlen(char *p1, char *p2, int len)
{
	int		i;
	char	*buff;

	i = 0;
	buff = p1;
//	printf("started ptrlen\n");
	if (len == 0)
		return (0);
	while (buff != p2 && i < len)
	{
//		printf("ptrlen = %i buff = [%c] next = [%c]\n", i, *buff, *p2);
		buff++;
		i++;
	}
	return (i);
}

char	*ft_cpychr(char *str, int c, int len)
{
	int		i;
	char	*buff;

	i = 0;
//	printf("started cpychr\n");
	if (str == NULL)
		return (NULL);
	if (!(buff = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i] != (char)c && i < len)
	{
//		printf("copying buff %i str %i\n", i, i);
		buff[i] = str[i];
		i++;
	}
	buff[len + 1] = '\0';
	return (buff);
}

int		get_next_line(const int fd, char **line)
{
	int				count;
	char			tmp[BUFF_SIZE + 1];
	static char		*buff;
	char			*next;
	char			*move;

	if (fd < 0 || !line || read(fd, tmp, 0) < 0)
		return (-1);
	next = NULL;
	//printf("hey GNL!\n");
	while ((count = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[count] = '\0';
//		printf("tmp while %s", tmp);
		buff == NULL ? (buff = ft_strdup(tmp)) : (buff = ft_strjoin(buff, tmp));
		if ((next = ft_strchr(buff, 10)) != NULL)
			break;
	}
//	printf("tmp %s", tmp);
//	if (buff == NULL)
//		return (0);
//	if (next == NULL && buff != NULL)
//		next = ft_strchr(buff, 10);
	if ((next = ft_strchr(buff, 10)) != NULL)
	{
		*line = ft_cpychr(buff, 10, ft_ptrlen(buff, next, ft_strlen(buff)));
	//	printf("line = %s\n", *line);
	//	printf("buff = %s\n", buff);
		move = buff;
		buff = ft_strsub(buff, ft_strlen(*line), ft_strlen(buff) - ft_strlen(*line)) + 1;
	}
	else
	{
		*line = ft_strdup(buff);
	//	free(buff);
		return (0);
	}
//	(next != NULL && ft_strchr(buff, 10) != NULL) ? (*line = ft_cpychr(buff, 10, ft_ptrlen(buff, next, ft_strlen(buff)))) : (*line = ft_strdup(buff));
	return (1);
//	(next != NULL) ? (buff = next + 1) : (buff = next);
}
