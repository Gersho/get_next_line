/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:32:30 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/12 14:37:24 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int ft_str_find_c(char *str, char c, int size)
{
	int	i;
	(void)size;

	i = 0;
	while (str[i])
	{
		//printf("in_find:i:%d  c:%c\n", i, str[i]);
		if (str[i] == c)
		{
			//printf("returning:%d\n", i);
			return (i);
		}
		i++;
	}
	return (-1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*casted_dst;
	unsigned char	*casted_src;
	unsigned int	i;

	casted_dst = (unsigned char *)dst;
	casted_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (casted_dst);
	i = 0;
	while (i < n)
	{
		casted_dst[i] = casted_src[i];
		i++;
	}
	return (casted_dst);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;

	if (!dest || !src)
		return (0);
	j = 0;
	while (src[j])
	{
		j++;
	}
	if (size == 0)
		return (j);
	i = 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if (j < size)
		dest[j] = '\0';
	else
		dest[size - 1] = '\0';
	return (j);
}


int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


char	*ft_gnl_join(t_gnl *stock, char *s2, int size)
{
	char	*ptr;

	if (!stock || !s2)
		return (NULL);
	if (!(ptr = ft_calloc((stock->len + size + 1), sizeof(char))))
		return (NULL);
	stock->len = ft_strlen(stock->str);
	//printf("in gnl_join stock.len:%d\n", stock->len);
	ft_memcpy((ft_memcpy(ptr, stock->str, stock->len) + stock->len), s2, size);
	return (ptr);
}


char	*ft_gnl_substr(char *s, size_t len_s, size_t start, size_t size)
{
	char				*ptr;

	if (!s)
		return (NULL);
	if (start >= len_s)
		size = 0;
	if (len_s - start < size)
	{
		if (!(ptr = ft_calloc((len_s - start + 1) , sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(ptr = ft_calloc((size + 1) , sizeof(char))))
			return (NULL);
	}
	ft_strlcpy(ptr, s + start, size + 1);
	ptr[size] = '\0';
	return (ptr);
}


void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
