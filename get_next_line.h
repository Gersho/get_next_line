/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:30:26 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/11 15:26:39 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct		s_gnl
{
	char	*str;
	id_t	len;
}					t_gnl;

int					get_next_line(int fd, char **line);
ssize_t				ft_str_find_c(char *str, char c, ssize_t size);
char	*ft_substr(char const *s, int len_s, unsigned int start, size_t len);

#endif
