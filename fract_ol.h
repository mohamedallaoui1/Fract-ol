/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:34:00 by mallaoui          #+#    #+#             */
/*   Updated: 2023/01/28 01:19:32 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 900.0
# define WIDTH  900.0
# define MAX_ITERATIONS 100

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_control
{
	double	zoom;
	double	scale;
	double	move_x;
	double	move_y;
	double	mouse_x;
	double	mouse_y;
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;
	int		color;
}				t_cntrl;

typedef struct cmplx
{
	double	real;
	double	imag;
}				t_complex;

typedef struct s_all
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_cntrl	contrl;
	char	**av;
	int		ac;
	int		(*f)(struct s_all *, int, int);
}			t_all;

int		pixel_iterate(t_all **vars);
int		control_key(int keycode, t_all *vars);
int		control_zoom(int button, int x, int y, t_all *vars);
int		mandelbrot(t_all *vars, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		julia(t_all *vars, int x, int y);
int		julia_move(int x, int y, t_all *vars);
int		burning_ship(t_all *vars, int x, int y);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
double	ft_atod(char *str);
void	initialize(t_all *vars, char **av, int ac);
void	show_usage(void);
void	color_shift(int keycode, t_all *vars);
void	control_keys_part2(int keycode, t_all *vars, double d);
int		close_window(t_all *vars);
void	initialize(t_all *vars, char **av, int ac);
double	return_res(char *str, double res, int i, double sign);

#endif