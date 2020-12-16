/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:28:40 by kzennoun          #+#    #+#             */
/*   Updated: 2020/12/16 16:49:00 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int					get_next_line(int fd, char **line);
int					ft_str_find_c(char *str, char c);
char				*ft_gnl_substr(char *s, size_t len_s, size_t start, \
					size_t size);
char				*ft_gnl_join(char *stock, char *s2, int size);
void				*ft_calloc_zero(size_t count, size_t size);
int					ft_strlen(const char *str);
#endif
