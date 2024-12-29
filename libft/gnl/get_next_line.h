/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrondi <magrondi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:12:58 by magrondi          #+#    #+#             */
/*   Updated: 2024/12/29 19:15:30 by magrondi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *buffer);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_trim_buffer(char *buffer);
char	*ft_cpy_current_line(char *buffer);
void	ft_reset_malloc(void *ptr);

#endif
