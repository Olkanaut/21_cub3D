/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshang <bshang@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:31:56 by bshang            #+#    #+#             */
/*   Updated: 2020/09/21 19:25:20 by bshang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_HEADER_H
# define CUB_HEADER_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/minilibx_mms/mlx.h"
# define BUFFER_SIZE 1024
# define ERR -1
# define ERR_MAP -2
# define ERR_MEM -3
# define ERR_OPEN -4
# define ERR_ARG -5
# define ERR_FILE -6
# define UI unsigned int
# define UC unsigned char
# define V void
# define FOV 60.
# define FOV_V 10.
# define SC 300.
# define WALL_HEIGHT 80.
# define SPRITE_SIZE_COEF 0.2
# define STEP_ROT 5.
# define STEP_MOVE 0.1
# define RAY_FARTHEST_POINT 20.
# define PLAN_RAY_LEN P_SC * 0.52
# define P_OFF 0.
# define A_SC 1.1
# define PANEL_SIZE 300.
# define B_WIN_OFFSET 300.
# define GUN_SIZE 0.35
# define PATH_ARMS_C "/Users/bshang/ololo/cub/textures/arms/arm.xpm"
# define PATH_ARMS "/Users/bshang/ololo/cub/textures/arms/scoop.xpm"
# define PATH_SKY "/Users/bshang/ololo/cub/textures/sky/neon_sky.xpm"
# define PATH_SKY_C "/Users/bshang/ololo/cub/textures/sky/curtains.xpm"
# define PATH_MUS "afplay music/Burial-Street_Halo_cut1.mp3&"
# define PATH_MUS_C "afplay music/Cabaret_1972.mp3&"
# define C1 0xE25F1D
# define C2 0x31C0EC
# define C3 0x6c4cc7
# define C4 0xf2ef88
# define C5 0x0f0b3b
# define C6 0xbd1108
# define C7 0xc8ecf7
# define C8 0x565669
# define C9 0xf7f7f7

typedef struct	s_l
{
	char		*rem;
	char		*rem_start;
	int			fd;
	struct s_l	*next;
}				t_l;

typedef struct	s_player
{
	double		pos[2];
	int			flag;
	double		dir;
}				t_player;

typedef struct	s_w
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	void		*data;
	int			bpp;
	int			llen;
	int			endian;
	double		res[2];
}				t_w;

typedef struct	s_t
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	void		*data;
	int			bpp;
	int			llen;
	int			endian;
	int			img_width;
	int			img_height;
}				t_t;

typedef struct	s_image
{
	int			j;
	double		dist;
	int			sp_vis_count;
	int			sp_eaten_count;
	double		sc_arms;
	int			plan_scale;
	double		plan_size[2];
}				t_image;

typedef struct	s_txtr
{
	t_t			*no;
	t_t			*ea;
	t_t			*so;
	t_t			*we;
	t_t			*sp1;
	t_t			*arm;
	t_t			*sky;
	UI			color_ceil;
	UI			color_floor;
}				t_txtr;

typedef struct	s_obstacle
{
	double		x0;
	double		y0;
	double		x_txtr;
	char		side;
	UI			color;
	int			img_width;
	int			img_height;
}				t_obstacle;

typedef struct	s_scanned
{
	char		*path_no;
	char		*path_so;
	char		*path_ea;
	char		*path_we;
	char		*sprite;
	int			spr_c;
	int			floor[3];
	int			ceiling[3];
	int			res[2];
	t_list		*raw_map;
	int			flag;
	int			f_val[13];
	size_t		map_size[2];
	int			save_f;
	int			bonus_f;
}				t_scanned;

typedef struct	s_sprite
{
	int			x;
	int			y;
	double		w;
	double		h;
	double		dist;
	int			flag;
}				t_sprite;

typedef struct	s_head
{
	t_scanned	*scan;
	t_player	*pl;
	t_sprite	*sp_ar;
	char		**map;
	t_w			*w;
	t_w			*w_a;
	t_w			*w_p;
	t_w			*w_arms;
	t_txtr		*txtr;
	t_image		*im;
	t_obstacle	*obst;
	double		*arr_v_dist;
	UI			temp_color;
}				t_head;

int				main(int argc, char **argv);
int				play(t_head *head);
void			set_scanned_struct(t_scanned *scanned);
int				check_fname(char *name, int fd);
int				check_scrshot_flag(char *name, t_scanned *scanned);
int				check_f(int *flags);
int				is_obj(char c);
char			*even_string(char *m, size_t size_max);
int				convert_raw_to_valid_field(t_head *head);
int				finalize(int fd, int res);
void			print_error(int t);
int				get_next_line(int fd, char **line);
int				cleaner(int fd, t_l **origin, char *buf, int res);
char			*ft_strjoin_free(char **s1, char *s2);
void			init_structs(t_head *head);
int				process_line(char *line, t_scanned *input_d);
int				process_line_start(char *line, t_scanned *scanned);
int				read_file(t_head *head, t_scanned *scanned, int fd);
int				scan_file(int argc, char **argv, t_head *head);
int				read_colors(char a, char *p, int *color, int *flag);
int				read_res(char *p, int *res, int *flag);
int				read_map(char *line, t_scanned *scan);
int				read_file_link(char a, char *p, char **link, int *flag);
double			to_degrees(double radians);
double			to_rad(double degrees);
void			calc_dist_to_wall(t_head *head, double angle);
void			put_sc_pxl(t_head *h, void *ptr, double p[2], UI color);
void			draw_plan(t_head *head);
void			set_sprite_distances(t_head *h);
void			eat_spr(t_head *h, int x, int y);
void			define_spr_and_fill(t_head *head, double x, double y, int flag);
void			set_sprite_flags(t_head *head);
void			draw_sprites(t_head *head);
t_t				*set_textures(t_head *h, t_t *s, char *path);
void			fill_color(t_head *head, double j, double i, int flag);
void			define_plan_size(t_head *h);
void			draw_arms(t_head *h);
void			draw_txtr_pixel_sky(t_head *head, double y, double angle);
void			draw_txtr_pxl(t_head *head, double i, double y_r, double y1);
void			draw_vert(t_head *head, double angle);
void			draw_axo(t_head *head);
int				draw_window(t_head *head);
int				draw_status(t_head *h, int flag);
int				proc_event(int key_num, void *ptr);
void			rotate_event(t_head *head, int key);
void			move_event(t_head *head, int key);
int				close_event(void *var);
UI				create_trgb(UI t, UI r, UI g, UI b);
void			set_colors(t_head *head);
void			get_color(t_t *data, int x, int y, UI *color);
void			check_texture(t_head *head, t_t *side);
void			get_txtr_details(t_head *head, int flag, int x, int y);
int				init_images_and_put_to_win_and_clear(t_head *head, int flag);
int				init_bonus_textures(t_head *head);
int				init_textures(t_head *head);
int				init_window(t_head *head);
void			clear_images(t_head *h);
void			my_mlx_pixel_put(t_w *data, int x, int y, int color);
double			calc_d(double x1, double x2, double y1, double y2);
void			calc_obst_coord(t_head *h);
double			norm_angle(double angle);
int				save_screenshot(t_head *head);

#endif
