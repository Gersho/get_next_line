/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 15:32:30 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/11 15:55:55 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_str_find_c(char *str, char c, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i < size)
	{
		if (str[i] == c)
			return (i);
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

char	*ft_gnl_join(t_gnl *stock, char const *s2, size_t size)
{
	char	*ptr;

	if (!stock || !s2)
		return (NULL);
	if (!(ptr = malloc((stock->len + size + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy((ft_memcpy(ptr, stock->str, stock->len) + stock->len), s2, size + 1);
	return (ptr);
}

char	*ft_gnl_substr(char const *s, int len_s, unsigned int start, size_t len)
{
	char				*ptr;

	if (!s)
		return (NULL);
	if (start >= len_s)
		len = 0;
	if (len_s - start < len)
	{
		if (!(ptr = malloc((len_s - start + 1) * sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(ptr = malloc((len + 1) * sizeof(char))))
			return (NULL);
	}
	ft_strlcpy(ptr, s + start, len + 1);
	ptr[len] = '\0';
	return (ptr);
}