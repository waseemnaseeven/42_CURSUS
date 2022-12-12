/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:05:35 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/12/12 11:59:22 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_findnl est lié à ma boucle principa, 
	elle permet de savoir si on a trouvé un \n ou \0, 
	si ==-1 alors on continue de chercher
	si == i, alors on sort de la boucle
*/

int	ft_findnl(char *stash)
{
	unsigned int	i;

	if (!stash)
		return (-1);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		return (-1);
	return (i);
}

/*
	1- malloc de la ligne sans le \n donc +1 pour lui et +1 pour le \0
	2- boucle pour tout récupérer
	3- \n si on en trouve un 
*/

char	*ft_getword(char *stash, unsigned int i)
{
	char				*new_s;
	unsigned int		j;

	new_s = malloc(i + 2);
	if (new_s == NULL)
		return (NULL);
	j = 0;
	while (stash[j] != '\n')
	{
		new_s[j] = stash[j];
		j++;
	}
	if (stash[j] == '\n')
	{
		new_s[j] = stash[j];
		j++;
	}
	new_s[j] = '\0';
	return (new_s);
}

/*
	Il faut pouvoir trouver la ligne ou si situe le \n
	1- Si i == -1 donc si ma stash est vide ou NULL 
	ou que i == len_stash - 1 donc si ma stash est 
	arrivée en fin de fichier, je la duplique tellequ'elle
	2- Sinon, ca veut dire que i > 0 et qu'on peut recupérer
	   la line avec le \n 
*/

char	*ft_line_creation(char *stash)
{
	size_t	i;
	char	*new_s;
	size_t	len_stash;

	len_stash = ft_strlen_gnl(stash);
	if (len_stash <= 0)
		return (NULL);
	i = ft_findnl(stash);
	if ((int)i == -1 || i == len_stash - 1)
	{
		new_s = ft_strdup_gnl(stash);
		return (new_s);
	}
	new_s = ft_getword(stash, i);
	return (new_s);
}

/*
	1- Dans le cas de stash == NULL ou vide ou que fin de fichier
	   on free la stash et on sort 
	2- Sinon, on va chercher le reste en évitant le \n donc ++i
	   puis on free et return la new_stash 
*/

char	*get_the_rest(char *stash)
{
	unsigned int		i;
	unsigned int		len_stash;
	char				*new_stash;
	unsigned int		j;

	i = ft_findnl(stash);
	j = 0;
	len_stash = ft_strlen_gnl(stash);
	if (((int)i == -1) || (len_stash - i) == 1)
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (len_stash - i + 1));
	if (!new_stash)
		return (NULL);
	while (stash[i])
		new_stash[j++] = stash[++i];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

/*
	Ici, strjoin sert a concaténer ce que j'ai read à ma static_var
	je concatène jusqu'a j'ai trouvé un \n dans ma static_var
	Ensuite, on sort de la boucle :
	- je free le buffer car plus besoin après être sorti de la boucle
	1- je return line avec le \n
	2- je clean stash pour retirer ce que je viens de renvoyer
*/

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*buf;
	char		*line;
	int			r_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	r_read = 1;
	while (ft_findnl(stash[fd]) == -1)
	{
		r_read = read(fd, buf, BUFFER_SIZE);
		if (r_read <= 0)
			break ;
		buf[r_read] = '\0';
		stash[fd] = ft_strjoin_gnl(stash[fd], buf);
	}
	free(buf);
	if (r_read == -1)
		return (NULL);
	line = ft_line_creation(stash[fd]);
	stash[fd] = get_the_rest(stash[fd]);
	return (line);
}

int main(void)
{
	int fd;
	int fd2;
	char *line;
	char *line2;
	int i;

	i = 1;
	fd = open("get_next_line.h", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	if (fd == -1)
		return -1;
	if (fd2 == -1)
		return -1;
	while(i < 1651)
	{
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		if (!line)
			break;
		if (!line2)
			break;
		printf("line [%d] : %s", i, line);
		printf("line [%d] : %s", i, line2);
		free(line);
		free(line2);
		i++;
	}
	// free(line);
	// free(line2);
	close(fd);
	return (0);
}
