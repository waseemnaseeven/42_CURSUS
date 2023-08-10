/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNLCL.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:05:35 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/27 13:11:32 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNLCL.h"


/*
	1- fonction qui va tcheke s'il y a qqch dans ma variable static
	2- read et garder la valeur
	3- clean stash, et passez à la liste suivante
	POUR SAMEDI MATIN : 
		- reussir à join le buf à la j_stash->content 
		- function get_word avec creation de ligne
		- 
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*m;

	m = malloc(sizeof(t_list));
	if (!m)
		return (NULL);
	m->content = content;
	m->next = NULL;
	return (m);
}

int	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	else
		return (ft_lstsize(lst->next) + 1);
}

t_list	*ft_lstlast(t_list *stash)
{
	t_list	*node;

	node = stash;
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
int		ft_findnl(t_list *stash)
{
	unsigned int	i;
	t_list	*actuel;

	if (!stash)
		return (-1);
	i = 0;
	// actuel est un pointeur sur le dernier élément
	actuel = malloc(sizeof(t_list));
	if (actuel == NULL)
		return (0); 
	actuel = ft_lstlast(stash);
	while (actuel->content[i] != '\n' && actuel->content[i] != '\0')
		i++;
	if (actuel->content[i] == '\0')
		return (-1);
	return (i);
}

/* 
	3- On stock dans ma var static ce que j'ai trouvé de buf par rapport à BUFFER_SIZE
	   on doit renvoyer un new_node call j_stash
*/
void	join_to_stash(t_list *stash, char *buf)
{
	t_list	*j_stash;
	// t_list	*last;
	int		i;

	j_stash = malloc(sizeof(t_list));
	if (j_stash == NULL)
		return ;
	j_stash->next = NULL;
	j_stash->content = malloc(sizeof(char) * (ft_strlen(buf) + 1));
	printf("buf : %s\n", buf);
	i = 0;
	while (buf[i])
	{
		j_stash->content[i] = buf[i]; 
		i++;
	}
	j_stash->content[i] = '\0';
	printf("j_stash->content : %s\n", j_stash->content);
	if (stash == NULL)
	{
		stash = j_stash;
		return ;
	}
	// last = ft_lstlast(stash);
	// last->next = j_stash;		
	// printf("On souhaite avoir last : %s\n", last->content);
	// printf("élément suivant de stash : %s\n", (char *)j_stash->next);


}


void	create_line(char **line, t_list *stash)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (stash)
	{
		while(stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++; //augmente la taille
				break;
			}
			len++; // sinon augmente la taille quand même
			i++;
		}
		stash = stash->next; // incrémenter
	}
	*line = malloc(sizeof(char) * (len + 1));

}

void	get_theword(t_list *stash, char **line)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	if (stash == NULL)
		return ;
	create_line(line, stash);
	if (*line == NULL)
		return ;
	while (stash)
	{
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

char	*GNLCL(int fd)
{
	static t_list *stash;
	char	*buf;
	unsigned int	r_read;
	char	*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, &buf, 0) < 0)
		return (NULL);
	r_read = 1;
	line = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (ft_findnl(stash) == -1)
	{
		r_read = read(fd, buf, BUFFER_SIZE);
		if (r_read <= 0)
			break ;
		buf[r_read] = '\0';
		join_to_stash(stash, buf);
		// printf("On essaie de trouver content : %s\n", stash->content);
		// printf("élément suivant de stash : %s\n", (char *)stash->next);
	}
	free(buf);
	get_theword(stash, &line);
	// get_therest(&stash);
	if (line[0] == '\0')
	{
		// free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// void	print_list(t_list *list)
// {
// 	while (list != NULL)
// 	{
// 		printf("%d\n", *(int *)list->content);
// 		list = list->next;
// 	}
// }

int main (void)
{
	int fd = open("CL.txt", O_RDONLY);
	char	*line;
	int i = 1;
	while (i < 10)
	{
		line = GNLCL(fd);
		if (line == NULL)
			break ;
		printf("line[%d] : %s", i, line);
		//free(line);
		i++;
	}
	//free(line);
	close(fd);
	return (0);
}
