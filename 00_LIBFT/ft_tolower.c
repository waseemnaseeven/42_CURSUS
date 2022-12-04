/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <wnaseeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:51:07 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/13 14:41:03 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
char * strtoupper( char * dest, const char * src ) {
    char * result = dest;
    while( *dest++ = ft_tolower( *src++ ) );
    return result;
}

int main() {

    char * input = "Diego De La Vega";
    char result[17];

    printf( "Result: %s\n", strtoupper( result, input ) );

    return (0);
}
*/
