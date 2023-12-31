/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:42:35 by oemelyan          #+#    #+#             */
/*   Updated: 2023/08/29 16:04:08 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		read_until_nl(int fd, char **storage);
bool	no_new_line(char *storage);
int		extract_line(char **storage, char **new_line);
int		clean_storage(char **storage);
char	*ft_strjoin(char *storage, char *buff_tmp);
size_t	ft_strlen(const char *str);

#endif
