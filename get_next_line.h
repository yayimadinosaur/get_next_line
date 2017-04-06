#ifndef get_nextline_h
# define get_nextline_h

#define BUFF_SIZE 10

#include <stdio.h>

# include <unistd.h>		//for write
# include <stdlib.h>		//for malloc + free
# include <fcntl.h>		//for read

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
//void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_strclr(char *s);

/*
 *	custom functions
 */

int		ft_ptrlen(char *p1, char *p2, int len);
char	*ft_cpychr(char *str, int c, int len);
#endif
