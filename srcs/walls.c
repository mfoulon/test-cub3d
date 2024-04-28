#include "cub3d.h"

//This function checks if the character at the given row and column is either a wall ('1') or an empty space (' ').
int	check_wall(char **map, int row, int col)
{
	if (map[row][col] != '1' && map[row][col] != ' ')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
//This function checks a horizontal line in the map (a row) to ensure that all characters are either walls or empty spaces.
int	check_wall_(char **map, int row, int i)
{
	while (map[row][i])
	{
		if (map[row][i] != '1' && map[row][i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
//This function checks for extended walls, i.e., walls that extend beyond the width of the adjacent row.
int	check_extended_wall(char **map, int row)
{
	int	l1;
	int	l2;

	l1 = ft_strlen(map[row]);
	l2 = 0;
	if (map[row + 1])
		l2 = ft_strlen(map[row + 1]);
	if (l1 > l2 && l2 > 0)
	{
		if (check_wall_(map, row, l2))
			return (EXIT_FAILURE);
	}
	else if (l2 > l1)
	{
		if (check_wall_(map, row + 1, l1))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
