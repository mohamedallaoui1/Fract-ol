/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:36:27 by mallaoui          #+#    #+#             */
/*   Updated: 2023/01/27 18:32:15 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	show_usage(void)
{
	ft_putstr("\e[1;33mHow to compile : \e[1;31m./fractol\e[0m \
\e[1;32m[Name of fractal] \e[1;35m[Real part] [Imaginairy part]\e[0m\n \
	\e[1;32m[Name of fractal] : mandelbrot julia burningship\e[0m\n \
	\e[1;35m[\e[1;32mJulia \e[1;35mOptions] : [Real part] [Imaginairy part]\e[0m\
	\e[1;37m⚠️ ONLY FOR JULIA ⚠️\e[0m\n\n\
\e[1;33mUsage :\e[0m\n\
        \e[1;37mZoom \e[1;31mIN \e[1;37mor \e[1;31mOUT \e[1;37musing the \e[1;31mscroll wheel\e[0m\n\
        \e[1;37mMove using the \e[1;31mUP \e[1;37mor \e[1;31mDOWN\e[0m\
 \e[1;37mor \e[1;31mLEFT \e[1;37mor \e[1;31mRIGHT \e[1;37marrow kies in the keyboard\e[0m\n\
        \e[1;37mChange color with the Buttons : \e[1;31mR \e[1;32mG \e[1;36mB\e[0m\n\
        \e[1;37mTo get back to the defualt mode \
press the \e[1;31mmiddle mouse button\e[0m\n");
}

void	color_shift(int keycode, t_all *vars)
{
	if (keycode == 15)
		vars->contrl.color = 256 * 256 * 265;
	if (keycode == 11)
		vars->contrl.color = 265;
	if (keycode == 5)
		vars->contrl.color = 2 * 259 * 256;
}

void	control_keys_part2(int keycode, t_all *vars, double d)
{
	if (keycode == 125)
	{
		vars->contrl.im_start -= d;
		vars->contrl.im_end -= d;
	}
	if (keycode == 124)
	{
		vars->contrl.re_start += d;
		vars->contrl.re_end += d;
	}
	if (keycode == 35)
		vars->f = &burning_ship;
	if (keycode == 38)
		vars->f = &julia;
	if (keycode == 46)
		vars->f = &mandelbrot;
}

int	close_window(t_all *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
	return (0);
}

void	initialize(t_all	*vars, char **av, int ac)
{
	vars->av = av;
	vars->ac = ac;
	vars->contrl.zoom = 0.01;
	vars->contrl.move_x = 0.0;
	vars->contrl.move_y = 0.0;
	vars->contrl.re_end = 2.0;
	vars->contrl.re_start = -2.0;
	vars->contrl.im_end = 2.0;
	vars->contrl.im_start = -2.0;
	vars->contrl.mouse_x = -0.4;
	vars->contrl.mouse_y = 0.6;
	vars->contrl.color = 60606060;
	if (ac == 4)
	{
		vars->contrl.mouse_x = ft_atod(av[2]);
		vars->contrl.mouse_y = ft_atod(av[3]);
	}
	if (ac == 3)
		vars->contrl.mouse_x = ft_atod(av[2]);
}
