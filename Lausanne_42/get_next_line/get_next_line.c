/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:49:11 by mwikiera          #+#    #+#             */
/*   Updated: 2024/01/04 13:49:11 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_buffer(char *buffer)
{
	//char *new;          //added
	char	*new_buff;
	int 	line;
	int 	all;
	int		x;
	int		c;


	x = 0;
	all = (ft_strlen(buffer) + 1);
	line = ft_strlenline(buffer);
	c = all - line;
	
	if (all - 1 <= line)
	{
		free (buffer);
		//new = malloc(1 * sizeof(char));  //added
		//ft_memset(new, '\0', 1);                    //added
		return (NULL);                    //changed from NULL
	}

	new_buff = malloc(c * sizeof(char) + 1);
	while (x < (all - line - 1))
	{
		new_buff[x] = buffer[all - c];
		x++;
		c--;
	}

	free(buffer);
	new_buff[x] = '\0';
	return (new_buff);
}

char	*only_line(char *buffer)
{
	int		i;
	int		this_line;
	char	*the_line;

	i = 0;
	this_line = ft_strlenline(buffer);
	//printf("Lenght of this_line: %d\n", this_line);
	the_line = malloc((this_line * sizeof(char)) + 1);
	if (the_line == NULL)
		return(NULL);
	while (i < this_line)
	{
		the_line[i] = buffer[i];
		i++;
	}
	//printf("Value of i: %d\n", i);
	//printf("Value of this_line: %d\n", (this_line));
	the_line[i] = '\0';

	return (the_line);
}

char	*add_char(char *buffer, char *next_chars)
{
	char	*returnbuffer;
	int		buffer_lenght;
	int		next_chars_lenght;

	buffer_lenght = ft_strlen(buffer);
	//printf("This is next_chars: %s\n", next_chars);
	next_chars_lenght = ft_strlen(next_chars); // HELP
	//printf("Lenght of next_chars: %d\n", next_chars_lenght);

	returnbuffer = malloc(((buffer_lenght + next_chars_lenght) * sizeof(char)) + 1);
	returnbuffer = ft_strjoin(returnbuffer ,buffer, next_chars); // HELP
	free(buffer);
	return (returnbuffer);
}

char	*read_file(int fd, char *buffer)
{
	int		bytes_read;
	char	temp_buffer[BUFFER_SIZE + 1];
//	char	*buffer;
	//static int i;    //added

	//i = 0;    //added

//	if(i == 0)
//	{
//		buffer = malloc(1 * sizeof(char));
//		if (buffer == NULL)
//			return (NULL);
//		buffer [0] = '\0';
//		i++;
//	}

	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read != 0)
		{
			free(buffer);
			buffer = malloc(1 * 1);
			buffer[0] = '\0';
			//bytes_read = 1;
			lseek(fd, 0, SEEK_SET);
		}
	//lseek(fd, 0, SEEK_SET);


	//ft_memset(temp_buffer, '\0', BUFFER_SIZE);
	//temp_buffer[0] = '\0';
	
//	buffer = malloc(1 * sizeof(char));
//	if (buffer == NULL)
//		return (NULL);
//	buffer [0] = '\0';

	bytes_read = 1;

	//need to malloc buffer and than calloc but need chck if file empty or not
	while (bytes_read > 0)
	{
		//ft_memset(temp_buffer, '\0', BUFFER_SIZE);
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
//		printf("Bytes_read value: %d\n", bytes_read);
		temp_buffer[bytes_read] = '\0';
		if (bytes_read == -1)
		{
			return (NULL);
		}
		if (bytes_read == 0)
		{
			//buffer = NULL;
			//free(buffer);
			break;
		}
		buffer = add_char(buffer, temp_buffer);

		//if(buffer[i] == '\n')   //added needed?
		//	break;              //added needed?
		//i++;                    //added needed?

		//if (bytes_read == -1 || bytes_read == 0)   // needed?
		//	break;                                 // needed?  
	}
	return(buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	static int	i = 0;
	int x;
	char	temp_buffer[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		buffer = 0;
		i = 0;
		return(NULL);
	}
//		return (NULL);
	if (i != 0)                // can move it
	{                          // can move it
		if (buffer == NULL)    // can move it
			return (NULL);     // can move it 
	}                          // can move it

	if (i == 0)
	{
		x = read(fd, temp_buffer, BUFFER_SIZE);
		if (x == 0)
			return(NULL);
		lseek(fd, 0, SEEK_SET);

		buffer = malloc(1 * sizeof(char));
		if (buffer == NULL)
			return (NULL);
		buffer [0] = '\0';
	}

	//if(i == 0)
	//{
	//	buffer = malloc(1 * sizeof(char));
	//	if (buffer == NULL)
	//		return (NULL);
	//	buffer [0] = '\0';
	//}

	//////////////////// i only have to read once otherwise x=0
	//////////////////// to know if has to keep reading need 
	//////////////////// check buffer because everything in it

		buffer = read_file(fd, buffer);
		//if (buffer == NULL)
		//	return (NULL);
	

	i++;
	
	line = only_line(buffer);
	buffer = new_buffer(buffer);
	if(buffer == NULL)
		i = 0;

	return(line);
}

/*int main()
{
    int fd;
    char *line;
	char *line2;
	char *line3;
	char *line4;
	char *line5;
	char *line6;

	fd = open("test.txt", O_RDONLY);

	line = get_next_line(fd);
	line2 = get_next_line(fd);

	printf("Line read:\n%s\n", line);
	printf("Line read:\n%s\n", line2);

	free(line);
	free(line2);
	close (fd);


	fd = open("test.txt", O_RDONLY);

    //printf("%d\n", fd);
    line = get_next_line(fd);
	line2 = get_next_line(fd);
	line3 = get_next_line(fd);
	line4 = get_next_line(fd);
	line5 = get_next_line(fd);
	line6 = get_next_line(fd);

	printf("\033[5;35m\n\n");

	printf("Line read:\n%s\n", line);
	printf("Line read:\n%s\n", line2);
	printf("Line read:\n%s\n", line3);
	printf("Line read:\n%s\n", line4);
	printf("Line read:\n%s\n", line5);
	printf("Line read:\n%s\n", line6);

	free(line);
	free(line6);
	free(line2);
	free(line3);
	free(line4);
	free(line5);
    close(fd);

    return 0;
}*/
