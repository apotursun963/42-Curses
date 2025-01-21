#include "../include/checker.h"

int	pull_till_new_line(char **str, char **line)
{
	char	*newline_pos;
	char	*temp;	

	newline_pos = ft_strchr(*str, '\n');
	if (!newline_pos)
		return (0);
	*newline_pos = '\0';
	*line = ft_strdup(*str);
	temp = *str;
	*str = ft_strdup(newline_pos + 1);
	return (free(temp), 1);
}

char	*merge_with_previous(char *str, char *buf)
{
	char	*tmp;

	tmp = str;
	if (str == NULL)
		str = ft_strdup(buf);
	else
		str = ft_strjoin(str, buf);
	return (free(tmp), str);
}

char	*read_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	int			byte_rd;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		byte_rd = read(fd, buffer, BUFFER_SIZE);
		if (byte_rd <= 0)
			break ;
		buffer[byte_rd] = '\0';
		str = merge_with_previous(str, buffer);
		if (pull_till_new_line(&str, &line))
			return (line);
	}
	if (!str || !str[0])
		return (free(str), NULL);
	line = ft_strdup(str);
	return (free(str), line);
}
