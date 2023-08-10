/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNLCL.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:17:43 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/27 12:31:39 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
    char*   content;
    struct s_list *next;
}   t_list;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 21

#endif
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);

#endif
