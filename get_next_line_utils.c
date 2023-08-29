/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:38:34 by oemelyan          #+#    #+#             */
/*   Updated: 2023/08/29 16:03:38 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *storage, char *buff_tmp)
{
	char				*joined_string;
	unsigned int		i;
	unsigned int		j;

	joined_string = malloc(ft_strlen(storage) + ft_strlen(buff_tmp) + 1);
	if (joined_string == NULL)
		return (NULL);
	i = 0;
	while (storage != NULL && storage[i] != '\0')
	{
		joined_string[i] = storage[i];
		i++;
	}
	j = 0;
	while (buff_tmp[j] != '\0')
	{
		joined_string[i++] = buff_tmp[j++];
	}
	joined_string[i] = '\0';
	free(storage);
	storage = NULL;
	return (joined_string);
}

bool	no_new_line(char *storage)
{
	ssize_t		i;

	if (storage == NULL)
		return (true);
	i = 0;
	while (storage[i] != '\0')
	{
		if (storage[i] == '\n')
			return (false);
		i++;
	}
	return (true);
}
