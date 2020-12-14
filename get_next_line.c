/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:32:28 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/14 11:38:50 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int	get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	static t_gnl	*stock;
	int				newline_index;
	int				read_return;
	char			*temp;

	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (-1);
	if (!stock)
	{
		stock = ft_calloc_zero(1, sizeof(t_gnl));
		stock->str = ft_calloc_zero(1, sizeof(char));
		stock->str[0] = 0;
		stock->len = 0;
	}
	if (!stock->str)
	{
		stock->str = ft_calloc_zero(1, sizeof(char));
		stock->str[0] = 0;
	}
	read_return = 1;
	while ((newline_index = ft_str_find_c(stock->str, '\n', stock->len)) == -1 && (read_return > 0))
	{
		if ((read_return = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(stock->str);
			free(stock);
			return (-1);
		}
		printf("IN WHILE newline_index:%d\n", newline_index);
		printf("IN WHILE stock->len:%d\n", stock->len);
		printf("IN WHILE ft_strlen(stock->str):%d\n", ft_strlen(stock->str));
		temp = ft_gnl_join(stock, buffer, read_return);
		stock->len += read_return;
		free(stock->str);
		stock->str = temp;
		printf("IN WHILE2 newline_index:%d\n", newline_index);
		printf("IN WHILE2 stock->len:%d\n", stock->len);
		printf("IN WHILE2 ft_strlen(stock->str):%d\n", ft_strlen(stock->str));
	}
	*line = ft_gnl_substr(stock->str, stock->len, 0, newline_index);
	temp = ft_gnl_substr(stock->str, stock->len, newline_index + 1, stock->len - newline_index);
	free(stock->str);
	stock->str = temp;
	stock->len -= (newline_index);
	printf("BEFORE IF newline_index:%d\n", newline_index);
	printf("BEFORE IF stock->len:%d\n", stock->len);
	printf("BEFORE IF ft_strlen(stock->str):%d\n", ft_strlen(stock->str));
	printf("BEFORE IF stock->str:%s\n", stock->str);
	if (read_return == 0 && ((newline_index = ft_str_find_c(stock->str, '\n', stock->len)) == -1))
	{
		 printf("INSIDE IF newline_index:%d\n", newline_index);
		 printf("INSIDE IF stock->len:%d\n", stock->len);
		 printf("INSIDE IF ft_strlen(stock->str):%d\n", ft_strlen(stock->str));
		*line = ft_gnl_substr(stock->str, ft_strlen(stock->str), 0, ft_strlen(stock->str));
		free(stock->str);
		stock->str = NULL;
		return (0);
	}
	if (stock->len != 0)
		return (1);
	if (read_return == 0 && stock->len == 0)
	{
		free(stock->str);
		free(stock);
		return (0);
	}
	return (read_return);
}


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

	while ((j = get_next_line(fd, &line)) /*|| i < 15*/)
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
