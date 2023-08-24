/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oemelyan <oemelyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:36:16 by oemelyan          #+#    #+#             */
/*   Updated: 2023/08/24 12:58:40 by oemelyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	clean_storage(char **storage)
{
	char	*cleaned_storage;
	char	*tmp;
	size_t	i;
	int		j;
	size_t	len;

	i = 0;
	tmp = *storage;
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	len = ft_strlen(tmp) - i;
	cleaned_storage = malloc(len + 1);
	if (cleaned_storage == NULL)
		return (1);
	cleaned_storage[len] = '\0';
	j = 0;
	while (tmp[i] != '\0')
		cleaned_storage[j++] = tmp[i++];
	free(*storage);
	*storage = cleaned_storage;
	return (0);
}

int	extract_line(char **storage, char **new_line)
{
	int		i;
	char	*tmp;

	tmp = *storage;

	i = 0;
	// if (!tmp[i])
	// 	return (NULL);
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	*new_line = malloc(i + 1);
	if (*new_line == NULL)
		return (1);
	(*new_line)[i] = '\0';
	i = 0;
	while (tmp[i] != '\0' && tmp[i] != '\n')
	{
		(*new_line)[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		(*new_line)[i] = tmp[i];
	return (0);
}

char	*read_until_nl(int fd, char **storage)
{
	ssize_t		bites_we_did;
	char		*buff_tmp;

	bites_we_did = 1;
	buff_tmp = malloc(BUFFER_SIZE + 1);
	if (!buff_tmp)
		return (NULL);
	while (no_new_line(*storage) && bites_we_did != 0)
	{
		bites_we_did = read(fd, buff_tmp, BUFFER_SIZE);
		if (bites_we_did == -1)
		{
			free(buff_tmp);
			free(*storage);
			return (NULL);
		}
		buff_tmp[bites_we_did] = '\0';
		*storage = ft_strjoin(*storage, buff_tmp);
	}
	free(buff_tmp);
	return (*storage);
}

char	*get_next_line(int fd)
{
	static char		*storage = NULL;
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_until_nl(fd, &storage);
	if (storage == NULL)
		return (NULL);
	if (extract_line(&storage, &new_line))
		return (free(storage), NULL);
	if (clean_storage(&storage))
		return (free(storage), free(new_line), NULL);
	return (new_line);
}

int	main(void)
{
	int			fd;

	fd = open("example.txt", O_RDONLY);
	printf("the first line is: %s\n", get_next_line(fd));
	printf("the second line is: %s\n", get_next_line(fd));
	printf("the third line is: %s\n", get_next_line(fd));
	return (0);
}