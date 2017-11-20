char		*get_str(int fd)
{
	int		f;
	int		i;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	f = read(fd, &c, 1);
	if (f < 0)
		return (NULL);
	if (f == 1)
	{
		str = (char *)malloc(sizeof(char) * 600);
		while (f != '\0')
		{
			str[i] = c;
			i++;
			f = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	return (str);
}
