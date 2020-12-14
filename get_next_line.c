/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:28:45 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/14 18:02:45 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	static char		*stock;
	int				newline_index;
	int				read_return;
	char			*temp;

	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (-1);
	if (!stock)
	{
		stock = ft_calloc_zero(1, sizeof(char));
		stock[0] = 0;
	}
	read_return = 1;
	while ((newline_index = ft_str_find_c(stock, '\n')) == -1 && (read_return > 0))
	{
		if ((read_return = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(stock);
			return (-1);
		}
		//printf("IN WHILE stock:%s\n", stock);
		temp = ft_gnl_join(stock, buffer, read_return);
		free(stock);
		stock = temp;
	}
	*line = ft_gnl_substr(stock, ft_strlen(stock), 0, newline_index);
	temp = ft_gnl_substr(stock, ft_strlen(stock), newline_index + 1, ft_strlen(stock) - newline_index);
	free(stock);
	stock = temp;
	//printf("BEFORE IF stock:%s\n", stock);
	if (read_return == 0 && ((newline_index = ft_str_find_c(stock, '\n')) == -1))
	{
		*line = ft_gnl_substr(stock, ft_strlen(stock), 0, ft_strlen(stock));
		//printf("line:%s\n", *line);
		free(stock);
		stock = NULL;
		return (0);
	}
	if (ft_strlen(stock) != 0)
		return (1);
	if (read_return == 0 && ft_strlen(stock) == 0)
	{
		free(stock);
		return (0);
	}
	return (read_return);
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

	while ((j = get_next_line(fd, &line)) || i < 12)
	{
		printf("gnl loop:%d\ngnl return:%d\nline:%s\n",i, j,line);
		printf("----------------\n");
		free(line);
		i++;

	}
printf("gnl loop:%d\ngnl return:%d\nline:%s\n",i, j,line);

//while(1)
{
}

}
*/