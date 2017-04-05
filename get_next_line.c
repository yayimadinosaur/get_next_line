
#include "get_next_line.h"

int		ft_ptrlen(char *p1, char *p2)
{
	int		i;
	char	*buff;

	i = 0;
	buff = p1;
	while (buff != p2)
	{
		printf("ptrlen = %i\n", i);
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
	if (!(buff = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i] != (char)c && i < len)
	{
		printf("copying buff %i str %i\n", i, i);
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
	int				read_attempt;	//for testing purposes
	char			*next;

	buff = NULL;
	next = NULL;
	if (fd == -1 )//|| !(tmp = ft_memalloc((size_t)BUFF_SIZE + 1)))
		return (-1);
	read_attempt = 1;
	printf("inside GNL; about to start\n");
	while ((count = (read(fd, tmp, BUFF_SIZE) > 0)))	//count bytes read
	{												//might be diff vs BUFF_SIZE
		tmp[count] = '\0';
		printf("read_attempt = [%i] count = [%i]\ntmp = [%s]\n", read_attempt, count, tmp);
		buff == NULL ? (buff = ft_strdup(tmp)) : (buff = ft_strjoin(buff, tmp));
		if (!buff)
			return (-1);
		printf("buff str = [%s]\n", buff);
		next = ft_strchr(buff, 10);
		if (next != NULL)
		{
			printf("newline found in buff!\n");
			break;
		}
		ft_strclr(tmp);		//clear tmp		//DONT PUT DIFF TYPES AS INPUT
		read_attempt++;
	}
//	free(tmp);
	if (!(*line = ft_cpychr(buff, 10, ft_ptrlen(buff, next))))
		return (-1);
	printf("line = %s\n", *line);
	printf("finished reading inside GNL\n");
/*	ft_memccpy(&line, buff, 10, ft_strlen(buff));
	tmp = ft_memalloc((size_t));
	tmp = ft_strsub(buff, ft_strcmp(buff, *line), ft_strlen(buff) - ft_strcmp(buff, *line));
	if (!tmp)
		return (-1);
	if (!(buff = ft_strdup(tmp)))
		return (-1);
	free(tmp);
	printf("line str = [%s]\n", *line);
	free(next);
*/	return (1);
}
