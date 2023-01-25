/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaseeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:59:52 by wnaseeve          #+#    #+#             */
/*   Updated: 2022/11/12 17:06:26 by wnaseeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c_u;

	i = 0;
	c_u = (unsigned char) c;
	if (!c_u)
		return ((char *)&s[ft_strlen(s)]);
	while (*(s + i) != '\0')
		i++;
	while (*(s + i) != c_u && i > 0)
		i--;
	if (i == 0 && *(s + i) != c_u)
		return (0);
	return ((char *)(s + i));
}
/*
int main() 
{

    // Le nom du fichier d'origine
    const char * originalFilename = "folder/image.jpg";

    // On prépare le nom du fichier de destination
    size_t size = strlen( originalFilename ) + 1;   // +1 pour le zéro terminal
    char * destinationFilename = (char *) malloc( size );
    strcpy( destinationFilename, originalFilename );

    // Et on y remplace l'extension du fichier par l'extension .png
    char * lastDotPos = ft_strrchr( destinationFilename, '.' );
    strcpy( lastDotPos, ".png" );

    // On affiche les deux noms de fichiers
    puts( originalFilename );
    puts( destinationFilename );

    return EXIT_SUCCESS;
}
*/
