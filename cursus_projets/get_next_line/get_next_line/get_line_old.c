char	*get_line(fd)
{
	char static	*remaining;
	char		*line;
	char		*buffer;
	int			read_output;
	static int	count;

	read_output = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buffer[0] = '\0';
	count++;
	printf("count = %d\n", count);
	printf("BUFFER value = %s\n", buffer);
	//printf("remaining at start = %s\n", remaining);
	while (!ft_strchr(buffer, '\n') && read_output != 0)
	{
		if (!buffer)
		{
			buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
			if (!buffer)
				return (0);
		}
		read_output = read(fd, buffer, BUFFER_SIZE);
		buffer[read_output] = '\0';
		printf("buffer_out = %d\n", read_output);
		if (read_output == -1)
		{
			free(buffer);
			return (0);
		}
		remaining = ft_strjoin(remaining, buffer);
		printf("remaining after joint = %s\n", remaining);
		//free(buffer);
	}
	free(buffer);
	buffer = NULL;
	line = crop_front(remaining);
	remaining = crop_end(remaining);
	printf("GET_LINE AFTER CROP_FRONT && CROP_END,, line = %s\n", line);
	printf("GET_LINE AFTER CROP_FRONT && CROP_END,, remaining = %s\n", remaining);

	return (line);
}

char	*get_next_line(fd)
{
	char	*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	line = get_line(fd);
	return (line);
}
