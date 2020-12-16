/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:28:48 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/16 15:25:35 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_gnl_join(char *stock, char *s2, int size)
{
	char	*ptr;
	int		len;
	
	if (!stock || !s2)
		return (NULL);
	len = ft_strlen(stock);
	if (!(ptr = ft_calloc_zero((len + size + 1), sizeof(char))))
		return (NULL);
	//printf("gnl_join strlen(stock):%d\n", ft_strlen(stock));
	//printf("size: %d \n", size);
	//printf("(len + size + 2): %d \n", (len + size + 2));
	ft_memcpy((ft_memcpy(ptr, stock, len) + len), s2, size);
	//temp = ft_memcpy(ptr, stock, len +1);
	//ft_memcpy(temp, s2, size);
	return (ptr);
}

char	*ft_gnl_substr(char *s, size_t len_s, size_t start, size_t size)
{
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= len_s)
		size = 0;
	if (len_s - start < size)
	{
		if (!(ptr = ft_calloc_zero((len_s - start + 1), sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(ptr = ft_calloc_zero((size + 1), sizeof(char))))
			return (NULL);
	}
	ft_strlcpy(ptr, s + start, size + 1);
	ptr[size] = '\0';
	return (ptr);
}

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
