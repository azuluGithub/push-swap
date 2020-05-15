#include "libft.h"

int					read_contents_from_fd_into_line(const int fd, char **line)
{
	char			*buf;
	char			*temp;
	int				ret;

	if (!(buf = (char *)malloc(sizeof(*buf) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret > 0)
	{
		buf[ret] = '\0';
		temp = ft_strjoin(*line, buf);
		if (!temp)
			return (-1);
		free(*line);
		*line = temp;
	}
	free(buf);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	static char		*buf = NULL;
	char			*str;
	int				value;

	if (!buf && (buf = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	str = ft_strchr(buf, '\n');
	while (str == NULL)
	{
		if ((value = read_contents_from_fd_into_line(fd, &buf)) == 0)
		{
			if (ft_strlen(buf) == 0)
				return (0);
			buf = ft_strjoin(buf, "\n");
		}
		if (value < 0)
			return (-1);
		else
			str = ft_strchr(buf, '\n');
	}
	*line = ft_strsub(buf, 0, str - buf);
	str = ft_strdup(str + 1);
	free(buf);
	buf = str;
	return (1);
}