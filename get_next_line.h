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

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

#endif
