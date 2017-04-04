
#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				count;
	char			tmp[BUFF_SIZE + 1];
	static char		*buff;
	int				read_attempt;	//for testing purposes

	buff = NULL;
	if (fd == -1 )//|| !(tmp = ft_memalloc((size_t)BUFF_SIZE + 1)))
		return (-1);
	read_attempt = 1;
	printf("inside GNL; about to start\n");
	while ((count = (read(fd, tmp, BUFF_SIZE) > 0)))	//count bytes read
	{												//might be diff vs BUFF_SIZE
		tmp[count] = '\0';
		printf("read_attempt = [%i] count = [%i]\ntmp = %s\n", read_attempt, count, tmp);
		buff == NULL ? buff = ft_strdup((const char*)tmp) : (buff = ft_strjoin((const char*)buff, (const char*)tmp));
		if (!buff)
			return (-1);
		printf("buff str = [%s]\n", buff);
		if (ft_strchr(buff, 10) != NULL)
			break;
		printf("AA\n");
		char *s = ft_memalloc((size_t)tmp);		//clear tmp		//DONT PUT DIFF TYPES AS INPUT
		printf("BB\n");
		read_attempt++;
	}
	printf("finished reading inside GNL\n");
/*	free(tmp);
	ft_memccpy(&line, buff, 10, ft_strlen(buff));
	tmp = ft_memalloc((size_t));
	tmp = ft_strsub(buff, ft_strcmp(buff, *line), ft_strlen(buff) - ft_strcmp(buff, *line));
	if (!tmp)
		return (-1);
*/	if (!(buff = ft_strdup(tmp)))
		return (-1);
//	free(tmp);
	printf("line str = [%s]\n", *line);
	if (count == 0)
		return (0);
	return (1);
}
