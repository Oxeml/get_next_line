#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
	int			fd;
	char		buffer_string[30];
	ssize_t 	bytes_read;

	fd = open("example.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening the file");
		return	(1);
	}
	bytes_read = read(fd, buffer_string, sizeof(buffer_string) - 1);
	//to read sizeof(buffer) - 1 bytes from the file
	//it will include the new line character '\n'
	if(bytes_read < 0)
	{
		printf("Error in reading");
		close(fd);
	}
	buffer_string[bytes_read] = '\0';
	printf("what we read: %s\n", buffer_string);
	printf("the quantity of bytes read is: %zd\n", bytes_read);
	close(fd);
	return(0);
}
