/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wung <marvin@42.r>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Create: 2017/04/13 16:10:54 by wung             #+#    #+#             */
/*   Upate: 2017/04/14 17:42:04 by wung            ###   ########.r       */
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
	b[i] = '\0';
	return (b);
}

int		get_next_line(const int fd, char **line)
{
	static char		*b;
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
//	printf("gnl newest start\n");
	while ((count = read(fd, tmp, BUFF_SIZE)) > 0)
	{
	//	printf("while rea_attempt = [%i]\n", read_attempt);
		tmp[count] = '\0';
		b == NULL ? (b = ft_strdup(tmp)) : (b = ft_strjoin(b, tmp));
	//	printf("b = [%s]\n", b);
		read_attempt++;
	}
	next = ft_strchr(b, 10) != NULL ? (*line = ft_cpychr(b, 10, ft_ptrlen(b, next, ft_strlen(b))))
		: (*line = ft_strdup(b));
	printf("*line = [%s]\n", *line);
//	if (ft_memcmp(*line, b, ft_strlen(*line)) == 0)
//		return (0);
	if (ft_strlen(b) > ft_strlen(*line) + 1)
	{
		hold = ft_strsub(b, ft_ptrlen(b, next, ft_strlen(b)), ft_strlen(b - ft_strlen(*line)));
		printf("hold = [%s]\n", hold);
		b = ft_strdup(hold);
		printf("b = [%s]\n", b);
		free(hold);
		printf("hold freed? = [%s]\n", hold);
		return (1);
	}
	return (0);
}
