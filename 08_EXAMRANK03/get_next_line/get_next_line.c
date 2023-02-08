#include "get_next_line.h"

int	ft_strlen(char *stash)
{
	int i = 0;
	while (stash && stash[i])
		i++;
	return (i);
}

int	ft_findnl(char *stash)
{
	int i = 0;
	if (!stash)
		return (-1);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		return (-1);
	return (i);
}

char	*ft_get_word(char *stash, int i)
{
	char *new;
	int j;
	new = malloc(i + 2);
	if (new == NULL)
		return (NULL);
	j = 0;
	while(stash[j] != '\n')
	{
		new[j] = stash[j];
		j++;
	}
	if (stash[j] == '\n')
	{
		new[j] = stash[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char *ft_strdup(char *str)
{
	int i = 0;
	int len = ft_strlen(str);
	char *new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);

}

char *ft_line_creation(char *stash)
{
	int i = ft_findnl(stash);
	char *line;
	int len_stash = ft_strlen(stash);
	if (ft_strlen(stash) <= 0)
		return (NULL);
	if (i == -1 || i == len_stash - 1)
	{
		line = ft_strdup(stash);
		return (line);
	}
	line = ft_get_word(stash, i);
	return (line);
}

char *get_the_rest(char *stash)
{
	int i;
	int len_stash;
	char *new;
	int j;

	i = ft_findnl(stash);
	j = 0;
	len_stash = ft_strlen(stash);
	if (i == -1 || (len_stash - i) == 1)
	{
		free(stash);
		return (NULL);
	}
	new = malloc((sizeof(char) * (len_stash - i + 1)));
	if (!new)
		return (NULL);
	while (stash[i])
		new[j++] = stash[++i];
	new[j] = '\0';
	free(stash);
	return (new);

}

char	*ft_strjoin(char *s1, char *s2)
{
	int  size;
	int i;
	char *new;

	if (s1)
		size = ft_strlen(s1);
	if (s2)
		size = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	size = 0;
	while (s1 && s1[size])
	{
		new[size] = s1[size];
		size++;
	}
	i = -1;
	while (s2 && s2[++i])
		new[size++] = s2[i];
	new[size] = '\0';
	free(s1);
	return (new);
}

char	*get_next_line(int fd)
{
	static char *stash;
	int r_read;
	char *buf;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	r_read = 1;
	while (ft_findnl(stash) == -1)
	{
		r_read = read(fd, buf, BUFFER_SIZE);
		if (r_read <= 0)
			break ;
		buf[r_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	if (r_read == -1)
		return (NULL);
	line = ft_line_creation(stash);
	stash = get_the_rest(stash);
	return (line);
}
