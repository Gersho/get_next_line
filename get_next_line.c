/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:32:28 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/11 15:55:54 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	static t_gnl	*stock;
	ssize_t			newline_index;
	ssize_t			read_return;
	char			*temp;

	if(!stock)
	{
		stock = malloc(sizeof(t_gnl));
		stock->str = malloc (sizeof(char));
		stock->str[0] = 0;
		stock->len = 0;
	}

	while (!(newline_index = ft_str_find_c(stock->str, '\n', stock->len)))
	{
		read_return = read(fd, buffer, BUFFER_SIZE);
		temp = ft_gnl_join(stock, buffer, read_return);
		stock->len += read_return;
		free(stock->str);
		stock->str = temp;
	}

	// une fois qu'on a un \n dans stock
	// \n @ newline_index
	line[0] = 


}


/*
!! derniere ligne \n pas garanti

struct static pour stocker stock.len

join dans static avan de testr \n

detecter le \n dans la condition du while

buffer[BUFFER_SIZE]



*/

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


gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
*/