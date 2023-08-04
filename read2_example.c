#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void add_to_storage(char *buffer_string, char *storage)
{
	size_t	storage_len;
	unsigned long	i;
	unsigned long	j;
	
	storage_len = ft_strlen(s1);
	ft_strlcpy(joined_string, s1, dst_init_len + 1);
	ft_strlcat(joined_string, s2, total_size + 1);
	while (buffer_string[i] != '\0')
	{
		storage[storage_len + i] = src[i];
		i++;
	}
	storage[storage_len + i] = '\0'; //not sure if it's needed
	j = 0;
	while (i >= 0) //assume that all in the beggining have been checked
	{
		if (storage[storage_len + i] == '\n')
		{
			while(j <= (storage_len + i))
			{
				
			}
		}
	}
}

void read_to_buffer(int fd, char *buffer_string)
{
	ssize_t		bites_read;

	bites_read = read(fd, buffer_string, sizeof(buffer_string) - 1);
	buffer_string[bites_read] = '\0'; // not sure about []
	if (!buffer_string)
		return(NULL);
}

char	*get_next_line(int fd)
{
	char	*storage;
	char	*buffer_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	read_to_buffer(fd, &buffer_string);
	add_to_storage(&buffer_string, &storage);

}

int main ()
{
	int			fd;
	ssize_t		bytes_read;
	
	fd = open("example.txt");
	
	get_next_line(fd);
	return(0);
}
