/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:54:42 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/12 17:09:56 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_u;

	c_u = (unsigned char) c;
	if (!c_u)
		return ((char *)&s[ft_strlen(s)]);
	while (*s)
	{
		if (*s == c_u)
			return ((char *)s);
		s++;
	}
	return (0);
}
/*
int main() {

    const char * source = "The C Language";
    char * destination;
    char * pointer;
    int length = strlen( source );
    
    // We clone the inital string 
    destination = (char *) malloc( sizeof( char) * (length+1) );
    strcpy( destination, source );
        
    // We replace all 'a' characters
    while ((pointer = ft_strchr( destination, '\0')) ) 
	{
        *pointer = 'A';
    }
    
    // Display result : The C LAnguAge
    printf( "Result : %s\n", destination );
        
    // Release dynamicly allocated memory
    free( destination );
    
    return 0;
}
*/
