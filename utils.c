/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallaoui <mallaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:29:28 by mallaoui          #+#    #+#             */
/*   Updated: 2023/01/26 18:14:00 by mallaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(0);
}

int	check_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(((str[i] >= '0' && str[i] <= '9') || str[i] == '.')))
			return (1);
		i++;
	}
	return (0);
}

int	count_points(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
			count++;
		i++;
	}
	return (count);
}

double	ft_atod(char *str)
{
	double	res;
	double	sign;
	int		i;

	i = 0;
	res = 0.0;
	sign = 1.0;
	while ((str[i] >= 9 && str[i] < 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	if (count_points(str) > 1 || check_error(&str[i]))
		ft_putstr("Error: invalid input");
	res = return_res(&str[i], res, i, sign);
	return (res);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
