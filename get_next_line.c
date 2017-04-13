/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:10:54 by wfung             #+#    #+#             */
/*   Updated: 2017/04/13 16:20:24 by wfung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		get_next_line(const int fd, char *line)
{
	static char		*buff;
	char			tmp[BUFF_SIZE];
	int				count;

	if (fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while (count = (read(fd, tmp, BUFF_SIZE) > 0))
	{
		buff == NULL ? ft_strdup(buff, tmp) : ft_strjoin(buff, tmp);
		if ((next = ft_strchr(buff)) != NULL)
			break;
	}

}
