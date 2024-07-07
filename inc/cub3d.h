/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvastena <fvastena@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:06:59 by toadzima          #+#    #+#             */
/*   Updated: 2024/07/07 18:58:19 by fvastena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <string.h>
# include <ctype.h>
# include <stddef.h>
# include <math.h>

# include "../libft/includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# define S_WIDTH 1920
# define S_HEIGHT 1080
# define ROT_SPEED 0.1
# define MOVE_SPEED 0.06
# define SIZE 64
# define FOV 0.70

# define E_M_INIT "Error\nmlx_init() failed"
# define E_M_WIN "Error\nmlx_new_window() failed"
# define E_M_IMG "Error\nmlx_xpm_file_to_image() failed"
# define E_M_ADDR "Error\nmlx_get_data_addr() failed"
# define E_MALLOC "Error\nmalloc() failed"
# define E_RES "Error\nResolution too high"
# define E_ARGS "Error\nUsage: ./cub3D <path_to_file.cub>"
# define E_FORMAT "Error\nWrong file format <.cub>"
# define E_MAP_CLOSED "Error\nMap is not closed"
# define E_TX "Error\nTexture is missing"
# define E_MAP_CHAR "Error\nInvalid, missing or duplicate char in the map"
# define E_OPEN "Error\nOpen of the file failed"
# define E_MAP_SIZE "Error\nMap is too big"
# define E_ARG_RGB "Error\nBad argument for the RGB"
# define E_ARG "Error\nBad argument in the file"
# define E_C_F "Error\nCheck the argument C or F"
# define E_RGB "Error\nWrong RGB input"
# define E_DUP "Error\nDuplicate parameters"
# define E_PATH "Error\nCheck the path of the texture"
# define E_TEX "Error\nCheck the texture name & path"
# define E_PATH_ARG "Error\nToo much arguments in one line"
# define E_MISS_ARG "Error\nMissing arguments in the file"
# define E_PATH_TEXT "Error\nThe texture doesn't exist"
# define E_ERR_END_TXT "Error\nThe texture path has to finish by .xpm"

// # define KEY_ESC 53
// # define KEY_W 13
// # define KEY_A 0
// # define KEY_S 1
// # define KEY_D 2
// # define KEY_LEFT 123
// # define KEY_RIGHT 124

// Windows keycode
# define KEY_ESC 65307
# define KEY_W 122
# define KEY_A 113
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_parsing
{
	char	**file;
	char	**map;
	char	*textures[6];
	int		x;
	int		height;
	int		map_height;
	int		line_len;
	int		real_width;
	int		end_args;
	int		is_valid[6];
}	t_parsing;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_img
{
	void	*ptr;
	int		*addr;
	int		bpp;
	int		width;
	int		height;
	int		endian;
}			t_img;

typedef struct s_player
{
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	plane_x;
	float	plane_y;
	float	dir_x;
	float	dir_y;
	char	orientation;
	int		up;
	int		down;
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
}	t_player;

typedef struct s_ray
{
	float	camera_x;
	float	dir_x;
	float	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		line_height;
	int		draw_start;
	float	delta_dist_y;
	float	delta_dist_x;
	float	side_dist_x;
	float	side_dist_y;
	float	wall_dist;
	float	wall_x;
	int		side;
}	t_ray;

typedef struct s_tx
{
	int				*n;
	int				*w;
	int				*e;
	int				*s;
	unsigned long	f_color;
	unsigned long	c_color;
}				t_tx;

typedef struct s_cubd
{
	int			**pixels;
	t_img		screen;
	t_ray		ray;
	t_mlx		mlx_vars;
	t_img		mlx_imgs[4];
	t_player	player;
	t_parsing	*pars;
	t_tx		*tx;
}	t_cubd;

// APPLY_RAYCASTING.C
void			set_screen_pixels(t_cubd *datas, t_ray *ray, int x, int i);
void			get_line_height(t_ray *ray, t_player player);

// EVENTS.C
int				exit_game(t_cubd *datas);
int				key_pressed(int key_code, t_cubd *datas);
int				key_released(int key_code, t_cubd *datas);

// FT_ERRORS.C
void			ft_errors(t_cubd *datas, char *err_msg, char *opt);

// FREE_ALL.C
void			free_all(t_cubd *datas);
void			ft_free_parsing(t_parsing *pars);

// FREE_UTILS.C
void			ft_free(void *ptr);
void			free_tabs(void **tab, size_t size);
void			free_textures(char **textures, t_tx *tx);
void			mlx_free(t_cubd *datas);

// GAME.C
int				cub3d_game(t_cubd *datas);

// INIT_PLAYER.C
void			set_player_infos(t_cubd *datas);
void			init_all(t_cubd *datas);

// MOVES.C 
int				move_up(t_cubd *datas, t_player player);
int				move_down(t_cubd *datas, t_player player);
int				move_left(t_cubd *datas, t_player player);
int				move_right(t_cubd *datas, t_player player);

// PARSING.C
int				ft_parsing(char *str, t_cubd *datas);
int				ft_check_map_char(char c);
int				ft_check_inside_map(t_parsing *pars, int i, int j, int cpy);
int				ft_is_map_closed(t_parsing *pars);

// PARSING_UTILS.C
int				ft_check_path(t_cubd *datas, int j, int i);
int				ft_check_int_rgb(char *tab);
int				ft_check_rgb_num(t_cubd *datas, int j);
int				ft_is_valid(int nbr, t_cubd *datas, int j, int i);
void			ft_check_rgb_arg(t_cubd *datas, int j, int i);

// PARSING_CHECKER.C
int				ft_check_file(t_cubd *datas, t_parsing *pars);
int				ft_check_current_line(t_cubd *datas, int j, int i);
int				ft_check_rgb(t_cubd *datas, int j, int i);
char			**ft_stock_file(char *str, t_cubd *datas, t_parsing *pars);
char			**add_line_to_pars(t_cubd *datas, char *line, char **file);

// PARSING_CHECKER_UTILS.C
int				ft_check_all_args(t_parsing *pars, int i);
int				ft_check_format(char *str);
int				ft_iswhitespace(char *str, int i);
int				ft_check_map(t_parsing *pars);
int				ft_copy_map(t_cubd *datas, t_parsing *pars);

// RAYCASTING.C
void			init_ray(t_ray *ray, t_cubd *datas, int trigger, int i);
void			raycasting(t_cubd *datas);

// RENDER.C
void			render_screen(t_cubd *datas);

// ROTATION.C
void			rotate_left(t_player *player);
void			rotate_right(t_player *player);

// TEXTURES_FILE.C
unsigned long	create_rgb(int red, int green, int blue);
void			get_texture_from_file(t_parsing *pars);
int				ft_check_format_text(char *str);

// TEXTURES_IMGS.C
void			set_mlx_imgs(t_cubd *datas);
void			ft_init_s_img(t_img *s_img, t_cubd *datas);

// VALIDATE_MOVE.C
int				validate_move(t_cubd *data, double new_x, double new_y);

// LIB_ADAPTED.C
size_t			cub3d_strlen(char *str);
char			*cub3d_strdup(char *str);
char			*cub3d_strtrim(char *str);
char			*cub3d_strjoin(char *s1, char *s2);

// UTILS.C
int				ft_is_num(char c);
int				ft_clean_map(t_parsing *pars);
int				ft_check_side(t_parsing *pars, int i, int j);

#endif