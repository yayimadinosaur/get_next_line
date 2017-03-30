







































int		get_next_line(const int fd, char **line)
{
	int		i;

	i = 0;
	if (fd == -1)
		return (-1);
	while (read(fd, line[i], BUFF_SIZE) != '\n' || read(fd, line[i], BUFF_SIZE) != NULL)
		i++;
	return (fd);
}
