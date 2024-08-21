/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolamber <rolamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:15:38 by rolamber          #+#    #+#             */
/*   Updated: 2024/08/21 16:06:55 by rolamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ftt_strlen(const char *str);
char	*ftt_strjoin(char const *s1, char const *s2);
int		ft_strsearch(char *s1, char c);
char	*ftt_substr(char *s1, int start, int end);
void	*ftt_calloc(size_t count, size_t size);

#endif