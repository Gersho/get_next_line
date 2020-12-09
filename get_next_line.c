/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:32:28 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/09 16:51:36 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char		*stocked;
	char			*buffer;
	ssize_t			read_result;
	ssize_t			newline_index;

	buffer = NULL;
	if (fd < 0 || !line || !(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	if (stocked)
		if(newline_index = ft_str_find_c(stocked, '\n', ft_strlen(stocked)))
		{
			//redo with substr
			//line[0] = ft_strljoin("", stocked, newline_index);
			line[0] = ft_substr(stocked, 0, newline_index);
			stocked = ft_memmove(stocked, stocked + newline_index, \
					ft_strlen(stocked + newline_index));
			return (1);
		}

	while ((read_result = read(fd, buffer, BUFFER_SIZE)) != -1)
	{


	}

	if (read_result == -1 || read_result == 0)
	{	
		free(stocked);
		free(buffer);
		return (read_result);
	}
	/*
	static char		*stock;
	char			*buffer;
	ssize_t			read_result;
	int				newline_index;

	if (fd <= 0 || !line || !(buffer = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);

	read_result = read(fd, buffer, BUFFER_SIZE);
	if (read_result == -1)
	{	
		//free ?
		return (-1);
	}
	if (stock)
		if(newline_index = ft_str_find_c(stock, '\n', ft_strlen(stock)))
		{
			line[0] = ft_strljoin("", stock, newline_index);
			return (1);
		}
	while ((read_result = read(fd, buffer, BUFFER_SIZE)) != -1)
	{
		// add a \0 at the end of stock
		if (read_result == 0)
		{
			if (stock)
				if(newline_index = ft_str_find_c(stock, '\n', ft_strlen(stock)))
					line[0] = ft_strljoin(stock, buffer, BUFFER_SIZE);
			return (0);
		}



	}
	//read result == number of bytes read
	//read returns
	// -1 error
	// 0 eof
	// number of bytes read

	// gnl returns
	// 1 : Une ligne a été lue
	// 0 : La fin de fichier a été atteinte
	// -1 : Une erreur est survenue


	//if EOF free 

	//if malloc problem free 
	if (read_result == -1 || read_result == 0)
	{	
		free(stock);
		free(buffer);
		return (read_result);
	}
	*/
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


gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
*/