#include "push_swap.h"

int	verification(int argc, char *argv[])
{
	char	**array;

	array = fill_array(argv, argc);
	if (!(array))
		return (-1);
	if (duplication_ver(argc, array) == -1)
	{
		free_array(array);
		return (-1);
	}
	free_array(array);
	return (0);
}

char	**fill_array(char **argv, int argc)
{
	int		i;
	int		j;
	char	**array;

	array = (char **) malloc((argc) * sizeof(char *));
	if (!(array))
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{
		array[j] = ft_itoa(ft_atoi_modified(argv[i]));
		if (!(array[j]) || (ft_strcmp(array[j], "42000000000") == 0))
		{
			free_array(array);
			return (NULL);
		}
		i++;
		j++;
	}
	array[j] = NULL;
	return (array);
}

int	duplication_ver(int argc, char **array)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 2)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (ft_strcmp(array[i], array[j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
