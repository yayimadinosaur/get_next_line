/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_original.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:23:03 by wfung             #+#    #+#             */
/*   Updated: 2017/04/13 19:50:46 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//original GNL
//issues: setting tmp[count] vs tmp[count - 1] has issues for line w/o \n
int		ft_ptrlen(char *p1, char *p2, int len)
{
	int		i;
	char	*buff;

	i = 0;
	buff = p1;
	if (len == 0)
		return (0);
	while (buff != p2 && i < len)
	{
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
	if (str == NULL)
		return (NULL);
	if (!(buff = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_bzero(buff, len + 1);
	while (str[i] != (char)c && i < len)
	{
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

	next = NULL;
//	count = 0;
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, tmp, 0) < 0)
		return (-1);
	while ((count = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[count] = '\0';
		buff == NULL ? (buff = ft_strdup(tmp)) : (buff = ft_strjoin(buff, tmp));
		if ((next = ft_strchr(buff, 10)) != NULL)
			break;
//		printf("buff = [%s]\n", buff);
	}
	if (buff == NULL)
		return (0);
	if (count == 0)
		next = ft_strchr(buff, 10);
//	if (count == 0 && (next = ft_strchr(buff, 10)) != NULL)
	/*buff != NULL  OR   ft_strchr(buff, 10) == NULL*/
//nn		(next = ft_strchr(buff, 10));
	(next != NULL) ? (*line = ft_cpychr(buff, 10, ft_ptrlen(buff, next, ft_strlen(buff))))
		: (*line = ft_strdup(buff));
	(ft_strlen(buff) > (size_t)ft_ptrlen(buff, next, ft_strlen(buff)) + 1) ?
			(buff = next + 1) : (buff = NULL);
	return (1);
}
/*
if (count < BUFF_SIZE && count > 0)	
	next = ft_strchr(buff, 10);
	if (next == NULL)
		line = ft_strdup(buff)
if (count <= 0)	//if -1 closed(fd) if 0 = eof
	return (0);
	*/
