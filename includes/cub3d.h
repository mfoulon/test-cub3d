#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/errno.h>
# include <string.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define EQUAL 0

/* -------- WINDOW CONFIG ----- */
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1

/* -------- KEY VALUES -------- */
# define RIGHT_M 2
# define LEFT_M 0
# define DOWN_M 1
# define UP_M 13
# define RIGHT_R 124
# define LEFT_R 123
# define ESC_KEY 53
# define WIN_CLOSE 17

/* -------- MAP -------- */
# define BUFF_SIZE 256
# define WALL '1'
# define EMPTY '0'
# define COL 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'X'
# define SQUARE 32

# define FLOOR "F"
# define CEILLING "C"

# define NORTH_TEXTURE "NO"
# define SOUTH_TEXTURE "SO"
# define EAST_TEXTURE "EA"
# define WEST_TEXTURE "WE"

/* -------- COLORS -------- */
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		**map;
	int			total_width;
	int			total_height;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*filepath;
	char		starting_pos; //not used yet
	t_color		floor_color; //not used yet
	t_color		ceilling_color; //not used yet
	t_vector	player; //not used yet
}	t_map;

typedef struct s_img
{
	void	*mlx_img; //ancien *ptr
	char	*addr;
	int		len;
	int		bpp;
	int		endian;
	int		*arr;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	double		x;
	double		y;
	double		dx;	//direction x
	double		dy;
	double		px;	//position x
	double		py;
	double		moovespeed;
	double		rotspeed; //rotate speed
	bool			is_mooving;
}	t_player;

typedef struct s_ray
{
	double	cx; // camera plane
	double	dx; // direction x
	double	dy; // direction y
	int		mx; // map x
	int		my; // map y
	int		sx; // step x
	int		sy; // step y
	double	sdx; // side distance x
	double	sdy; // side distance y
	double	ddx; // delta distance x
	double	ddy; // delta distance y
	double	wd; // wall distance
	int		side; // side of the wall hit
	int		h; // height of the wall
	int		ds; // draw start
	int		de; // draw end
	double	wx; // wall x
} t_ray;

typedef struct s_program
{
	//mlx data
	void		*mlx_ptr;
	void		*win_ptr;

	//game inputs
	int			argc;
	char		**argv;
	char		**cub_content;
	t_map		*map;

	//image
	t_img		*img;
	t_img		tex; //--> t_img?

	t_player	*player;
	double		pos_x;
	double		pos_y;
	double      dir_x;
	double      dir_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	double		r_angle;
	double		wallx;
	double		tex_pos;
	double		tex_step;
	int			r_right;
	int			m_right;
	int			r_left;
	int			m_left;
	int			m_up;
	int			m_down;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			x;
	int			tex_x;
	int			tex_y;
	int			screen_w;
	int			screen_h;
}				t_program;

//PARSING//

//cub.c//
int	check_extention(char *src, char *to_find);
void	check_texture(char **content, int *i);
void	check_colors(char **content, int *i);
void	check_content(char **content);

//get_data.c//
void	get_map_textures(t_program *game_ptr);
void	get_rgb(t_color *color, char **str);
void	get_colors(t_program *ptr);
void	get_player_pos(t_map *map);
void	get_map(t_program *data);
void	get_map_size(t_program *data);

//map.c//
int	check_player_surroundings(char **map, int row, int col);
void	check_map(char **map);
void	map_checks_(t_map map, int row, int col);
void	check_map_full(t_map map);

//parsing.c//
void	get_content(t_program *ptr);
void	parse_map(t_program *ptr);

//utils.c//
int	nbr_of_lines(char *filename);
void  free_split(char **tab);
int	check_new_line(char *str);
int	is_charset(char c, char *set);
int	get_map_len(t_program *ptr);
void	ft_puterror(char *msg);
void	*ft_garbage_collector(void *ptr, bool clean);


//walls.c//
int	check_wall(char **map, int row, int col);
int	check_wall_(char **map, int row, int i);
int	check_extended_wall(char **map, int row);


//RENDERING//

//img_pix_put//
void	img_pix_put(t_img *img, int x, int y, int color);

//display_2d.c//
void	display_2d(t_program *data);
void	draw_tile(t_program *data, int	col, int row, int color);
int	render_2d(t_program *data);

//init.ray.c//
void    init_ray(t_ray *ray, int x, t_player *player);

#endif
