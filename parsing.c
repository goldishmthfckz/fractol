/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:05:12 by estegana          #+#    #+#             */
/*   Updated: 2024/03/09 17:05:13 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parsingjulia(int ac, char **av)
{
	if (ac != 4)
		return (0);
	else
	{
		if (!castdouble(av[2]) || !castdouble(av[3]))
			return (0);
	}
	return (1);
}

//si pas de parametre > msg d'erreur
//si 1 parametre mais mauvais nom de fractal > msg d'erreur
int	parsing(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("enter fractal name ; -julia- or -mandelbrot-\n");
		return (0);
	}
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "julia") != 0
			&& ft_strcmp(av[1], "mandelbrot") != 0)
		{
			ft_printf("invalid fractal\n");
			return (0);
		}
		else
			return (1);
	}
	return (1);
}

int	parsing2(int ac, char **av)
{
	if (parsing(ac, av) == 0)
		return (0);
	else
	{
		if (ac > 2)
		{
			if (ft_strcmp(av[1], "julia") != 0)
			{
				ft_printf("too many args\n");
				return (0);
			}
			else
			{
				if (parsingjulia(ac, av) == 0)
				{
					ft_printf("julia takes 2 double casted args\n");
					return (0);
				}
			}
		}
	}
	return (1);
}
