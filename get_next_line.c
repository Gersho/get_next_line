/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:32:28 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/05 11:34:47 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int get_next_line(int fd, char **line)
{
	static char		*buffer;

	if (!buffer)
		if (!(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
			return (NULL);

	read(fd, buffer, BUFFER_SIZE);

	//if EOF free buffer

	//if malloc problem free buffer

}

int main(void)
{

}

/*

Prototype
int get_next_line(int fd, char **line);

Fichiers de rendu
get_next_line.c, get_next_line_utils.c,get_next_line.h

Paramètres
#1. le file descriptor sur lequel lire
#2. La valeur de ce qui a été lu

Valeur de retour
1 : Une ligne a été lue
0 : La fin de fichier a été atteinte
-1 : Une erreur est survenue

Fonctions ex-ternes autorisées
read, malloc, free

Description 
Ecrivez une fonction qui retourne une ligne lue
depuis un file descriptor, sans le retour à laligne


gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.cget_next_line_utils.c
*/