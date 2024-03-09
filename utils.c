/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:44:42 by estegana          #+#    #+#             */
/*   Updated: 2024/03/01 19:44:43 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//si pas de parametre > msg d'erreur
//si + d'1 parametre > msg d'erreur
//si 1 parametre mais pas de fractale valide > msg d'erreur
int	parsing(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("enter fractal name ; either -julia- or -mandelbrot-\n");
		return (0);
	}
	if (ac > 2)
	{
		ft_printf("too many args\n");
		return (0);
	}
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "julia") != 0
			&& ft_strcmp(av[1], "mandelbrot") != 0)
		{
			ft_printf("enter valid fractal\n");
			return (0);
		}
		else
			return (1);
	}
	return (1);
}

//initialise donnees de la fractale
void	init_fractal(t_data *f)
{
	f->x = 0;
	f->y = 0;
	f->color = 0xbddfff;
	f->zoom = 250;
	f->offset_x = -2;
	f->offset_y = -1.5;
	f->max_iterations = 42;
}

//
void	ft_color(t_data *f, int x, int y, int color)
{
	int	*buffer;

	buffer = f->imgaddr;
	buffer[(y * f->len / 4) + x] = color;
}

//efface le contenu de la window et free les data de la fractale
int	exit_fractal(t_data *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	free(f);
	exit(0);
}
