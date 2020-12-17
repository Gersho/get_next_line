/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:28:45 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/17 11:50:27 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_zero(size_t count, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*str;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	str = (unsigned char *)ptr;
	i = 0;
	while (i < (count * size))
	{
		str[i] = (unsigned char)0;
		i++;
	}
	return (ptr);
}

int		ft_str_find_c(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char			buffer[BUFFER_SIZE];
	static char		*stock;
	int				nl_i;
	int				read_return;
	char			*temp;

	if (fd < 0 || read(fd, 0, 0) || BUFFER_SIZE <= 0)
		return (-1);
	if (!stock)
		stock = ft_calloc_zero(1, sizeof(char));
	read_return = 1;
	while ((nl_i = ft_str_find_c(stock, '\n')) == -1 && (read_return > 0))
	{
		if ((read_return = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(stock);
			return (-1);
		}
		temp = ft_gnl_join(stock, buffer, read_return);
		free(stock);
		stock = temp;
	}
	*line = ft_gnl_substr(stock, ft_strlen(stock), 0, nl_i);
	temp = ft_gnl_substr(stock, ft_strlen(stock), nl_i + 1, ft_strlen(stock) - nl_i - 1);
	free(stock);
	stock = temp;
	if (read_return == 0 && ((nl_i = ft_str_find_c(stock, '\n')) == -1))
	{
		*line = ft_gnl_substr(stock, ft_strlen(stock), 0, ft_strlen(stock));
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
	return (1);
}
