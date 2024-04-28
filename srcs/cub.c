#include "cub3d.h"

int	check_extention(char *src, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(src) - ft_strlen(to_find);
	while ((src[j] && to_find[i])
		&& (src[j++] == to_find[i++]))
    ;
	if (j == (int)ft_strlen(src))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void	check_texture(char **content, int *i)
{
	int	found;

	found = 0;
	while (*i < 4 && content[*i])
	{
		if (ft_strncmp(content[*i], "NO ", 3) == 0
			|| ft_strncmp(content[*i], "SO ", 3) == 0
			|| ft_strncmp(content[*i], "WE ", 3) == 0
			|| ft_strncmp(content[*i], "EA ", 3) == 0)
			found++;
		(*i)++;
	}
	if (found != 4 && *i != found)
		ft_puterror("Error : Textures !\n");
	if (*i == 0)
		ft_puterror("Error : Empty .cub file !\n");
}

void	check_colors(char **content, int *i)
{
	int	found;
	int	j;
	int	ex;

	found = 0;
	ex = *i;
	j = *i + 2;
	while (*i < j && content[*i])
	{
		if (ft_strncmp(content[*i], "F ", 2) == 0
			|| ft_strncmp(content[*i], "C ", 2) == 0)
			found++;
		(*i)++;
	}
	if (*i - ex != found && found != 2)
		ft_puterror("Error : Colors !\n");
}

void	check_content(char **content)
{
	int	i;

	i = 0;
	check_texture(content, &i);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	check_colors(content, &i);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	if (!content[i])
		ft_puterror("Error : Map doesn't exist!\n");
}
