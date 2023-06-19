/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:48:31 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/12 16:52:41 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
char * strtoupper( char * dest, const char * src ) {
    char * result = dest;
    while( *dest++ = ft_toupper( *src++ ) );
    return result;
}

int main() {

    char * input = "Diego De La Vega";
    char result[17];

    printf( "Result: %s\n", strtoupper( result, input ) );

    return EXIT_SUCCESS;
}
*/
