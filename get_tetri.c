int			count_tetri(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			result++;
		i++;
	}
	return (result / 4);
}
void	creat_tetri(t_teri **tmp, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '#')i
		{
			Trouver comment placer dans le tableau
			j++;
		}
	i++;
	}
}

t_tetri		get_tetri(char *str)
{
	int			nb_tetri;
	t_tetri		*first;
	t_tetri		*tmp;

	nb_tetri = count_tetri(str);
	if (!(first = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	while (nb_tetri > 0)
	{
		creat_tetri(tmp, strsub(str, 0 + add21, 20)
		if (!(tmp->next = (t_tetri)malloc(sizeof(t_tetri))))
			return (NULL);
		tmp = tmp->next;
		nb_tetri--;
		add21 += 21;
	}
	tmp->next = NULL;
	return (first);
}
