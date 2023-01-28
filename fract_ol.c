/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:18:21 by mallaoui          #+#    #+#             */
/*   Updated: 2023/01/28 01:22:59 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	check_arg(char *s, t_all *vars)
{
	if ((vars->ac >= 2 && vars->ac < 5) && ft_strcmp(s, "julia") == 0)
		vars->f = &julia;
	else if ((vars->ac == 2) && ft_strcmp(s, "mandelbrot") == 0)
		vars->f = &mandelbrot;
	else if ((vars->ac == 2) && ft_strcmp(s, "burningship") == 0)
		vars->f = &burning_ship;
	else
		show_usage();
}

int	pixel_iterate(t_all **vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_clear_window((*vars)->mlx, (*vars)->mlx_win);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			(*vars)->f(*vars, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window((*vars)->mlx, (*vars)->mlx_win, \
		(*vars)->img.img, 0, 0);
	return (0);
}

int	mlx_funct(t_all *vars)
{
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, \
		HEIGHT, WIDTH, "Fract-ol project");
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, \
		&vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	mlx_mouse_hook(vars->mlx_win, control_zoom, vars);
	mlx_hook(vars->mlx_win, 2, 1L << 2, control_key, vars);
	mlx_hook(vars->mlx_win, 6, 0L, julia_move, vars);
	mlx_hook(vars->mlx_win, 17, 0L, close_window, vars);
	mlx_loop_hook(vars->mlx, pixel_iterate, &vars);
	mlx_loop(vars->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_all	*vars;

	if (ac > 1)
	{
		vars = (t_all *)malloc (sizeof(t_all));
		initialize(vars, av, ac);
		check_arg(av[1], vars);
		mlx_funct(vars);
	}
	else
		show_usage();
	while (1);
}
