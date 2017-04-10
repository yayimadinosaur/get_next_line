/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:23:03 by wfung             #+#    #+#             */
/*   Updated: 2017/04/07 19:00:09 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_ptrlen(char *p1, char *p2, int len)
{
	int		i;
	char	*buff;

	i = 0;
	buff = p1;
	printf("started ptrlen\n");
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
	printf("started cpychr\n");
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
//	int				read_attempt;	//for testing purposes
	char			*next;

	next = NULL;
	if (fd < 0 || !line)//|| !(tmp = ft_memalloc((size_t)BUFF_SIZE + 1)))
		return (-1);
//	read_attempt = 1;
//	printf("inside GNL; about to start\n");
	while ((count = read(fd, tmp, BUFF_SIZE)) > 0)	//count bytes read
	{												//might be diff vs BUFF_SIZE
		tmp[count] = '\0';
//		printf("read_attempt = [%i] BUFF_SIZE = [%i] count = [%i]\ntmp = [%s]\n", read_attempt, BUFF_SIZE, count, tmp);
		buff == NULL ? (buff = ft_strdup(tmp)) : (buff = ft_strjoin(buff, tmp));
		if (!buff)
		{
			free(buff);
			return (-1);
		}
//		printf("buff str = [%s]\n", buff);
/*		if ((next = ft_strchr(buff, 10)) != NULL)
		{
			printf("newline found in buff!\n");
			break;
		}
*/	//	ft_strclr(tmp);		//clear tmp		//DONT PUT DIFF TYPES AS INPUT
//		read_attempt++;
	}
	next = ft_strchr(buff, 10);
//	printf("---------out while------------------COUNT IS %i\n", count);
	printf("before moving ptrs buff = [%s] next = [%s]\n", buff, next);
	free(buff);
	(next != NULL) ? (*line = ft_cpychr(buff, 10, ft_ptrlen(buff, next, ft_strlen(buff))))
		:(*line = ft_strdup(buff));
	if (!*line)
	{
		free(*line);
		return (-1);
	}
	(next != NULL) ? (buff = next + 1) : (buff = next);
	if (buff == NULL)
	{
		*line = NULL;
		return (0);
	}
//	printf("reading over buff = [%s] next = [%s]\n", buff, next);
//	printf("-----------------------------GNL saved line = [%s]\n", *line);
//	printf("finished reading inside GNL\n");
	return (1);
}
