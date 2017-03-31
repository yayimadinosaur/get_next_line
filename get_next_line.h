#ifndef getnextline_h
# define getnextline_h

#define BUFF_SIZE 1

# include <unistd.h>		//for write
# include <stdlib.h>		//for malloc + free
# include <sys/uio.h>		//for read

//if using linkedlist for GNL
typedef struct		s_list
{
	char			x[BUFF_SIZE];
	struct s_list	*next;
}					t_list;

int		get_next_line(const int fd, char **line);

char	*ft_strcpy(char *dst, const char *src);

#endif
