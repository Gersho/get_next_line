/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:32:28 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/12 17:29:42 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	static t_gnl	*stock;
	int			newline_index;
	int			read_return;
	char			*temp;

	if(fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
	{
		return (-1);
	}


	if(!stock)
	{
		stock = ft_calloc(1,sizeof(t_gnl));
		stock->str = ft_calloc (1,sizeof(char));
		stock->str[0] = 0;
		stock->len = 0;
	}

	if (!stock->str)
	{

		stock->str = ft_calloc (1,sizeof(char));
		stock->str[0] = 0;
	}


	read_return = 1;
	while ((newline_index = ft_str_find_c(stock->str, '\n', stock->len)) == -1 && (read_return > 0))
	{
		//printf("entered while\n");
		if ((read_return = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(stock->str);
			free(stock);
			return (-1);
		}
		//printf("buffer:%s\n", buffer);
		temp = ft_gnl_join(stock, buffer, read_return);
		stock->len += read_return;
		free(stock->str);
		stock->str = temp;
		//printf("stockstrINWHILE:\n%s\n", stock->str);

		
	}

	// une fois qu'on a un \n dans stock
	// \n @ newline_index
	//printf("stockstr:\n%s\n", stock->str);
	//printf("ENDSTOCKSTR\n");
	//printf("nl_index_number:%d\n", newline_index);
	//printf("nl_index:%c", stock->str[newline_index]);
	*line = ft_gnl_substr(stock->str, stock->len, 0, newline_index);
	//printf("lineptr:%p\n", line);
	temp = ft_gnl_substr(stock->str, stock->len, newline_index + 1, stock->len - newline_index);
	free(stock->str);
	stock->str = temp;
	stock->len -= newline_index;
	//printf("stock->len:%d\n", stock->len);
	//printf("nl_index_number:%d\n", newline_index);
	if(read_return == 0 && ((newline_index = ft_str_find_c(stock->str, '\n', stock->len)) == -1))
	{
		//printf("<in last line manager>\n");
		//printf("stockstr2:\n%s\n", stock->str);
	//printf("ENDSTOCKSTR\n");

		*line = ft_gnl_substr(stock->str, ft_strlen(stock->str), 0, ft_strlen(stock->str));
		//printf("line2:%s\n", *line);
		//*line = stock->str;
		free(stock->str);
		//stock->len = 0;
		stock->str = NULL;
		return (0);

	}

	if (stock->len != 0)
	{
		return (1);
	}

	if (read_return == 0 && stock->len == 0)
	{
		free(stock->str);
		free(stock);
		return (0);
	}

	return(read_return);

}
/* 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int fd;
	char	*line;
	int		i;
	int 	j;

	i = 0;

	fd = open("test.txt", O_RDONLY);

	while ((j = get_next_line(fd, &line)) || i < 11)
	{
		printf("gnl loop:%d\ngnl return:%d\nline:%s\n",i, j,line);
		printf("----------------\n");
		i++;

	}
	

printf("gnl loop:%d\ngnl return:%d\nline:%s\n",i, j,line);


}

 */
 




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