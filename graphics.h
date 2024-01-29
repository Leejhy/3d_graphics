
#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include "mlx.h"
# include "./read/read_line.h"

typedef struct s_dda
{
	float	start_x;
	float	start_y;
	float	dx;
	float	dy;
	float	dis;
	float	inc_x;
	float	inc_y;
}	t_dda;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_xyz
{
	float	x;
	float	y;
	float	z;
}	t_xyz;

typedef struct s_coord
{
	float	offset_x;
	float	offset_y;
	float	height;
	float	width;
	int		col;
	int		row;
	int		gap;
	int		z_gap;
	t_xyz	**xyz_map;
}	t_coord;

//fdf.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
//init.c
void		vars_img_init(t_vars *vars, t_coord *coord, t_data *img);
void		xyz_map_init(t_coord *coord, int **z_map);
void		coord_init(t_coord *coord);
void		rotate_init(t_coord *coord);
//hook.c
int			esc_hook(int key, t_vars *vars);
int			exit_hook(void);
//put_pixel.c
void		ft_write_pixel(t_data *img, t_coord coord);
void		write_dda(t_xyz xyz, t_xyz next_xyz, t_data *img, t_coord coord);
//fdf_utils.c
size_t		ft_strlen(char *str);
void		xyz_frees(t_xyz **xyz, int row);
//rotation.c
void		euler_x(float *old_y, float *old_z, double angle);
void		euler_z(float *old_x, float *old_y, double angle);
//parsing.c
void		f_check(char *str);
int			ft_line_cnt(char *file_name);
int			**parsing(char *file_name, int *col_size, int *row_size);
//read_map.c
int			**read_map(int fd, int line_cnt, int *col_size, int *row_size);
int			**map_to_coordinate(char **map, int x_cnt, int y_cnt);
int			**make_coordinate(int x_cnt, int y_cnt);
char		**get_map(int fd, int *line_cnt);
long long	ft_atoll(const char *str);
//readmap_utils.c
void		check_valid_map(char **map, size_t col_cnt, size_t line_cnt);
int			check_ln(char *str);
int			is_sep(char c, char *sep);
size_t		ft_col_cnt(char *str, char *sep);
void		map_frees(char **map);
//filecheck.c
int			ft_strncmp(char *s1, char *s2, size_t n);
size_t		ft_word_cnt(char *str, char sep);
char		*ft_strdup(char *str, char sep);
void		split_frees(char **ptr);
void		filename_check(char *str);
//error.c
void		ft_error(int err);
void		args_error(void);
void		malloc_failed(void);
void		file_error(void);
void		map_error(void);

#endif