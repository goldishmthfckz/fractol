/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:00:09 by estegana          #+#    #+#             */
/*   Updated: 2024/02/23 20:00:11 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_data *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->max_iterations = 42;
}

int	generatefractal(t_data *fractal, char *name)
{
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
		drawmandelbrot(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}

void	*drawmandelbrot(void *fractal_void)
{
	t_data	*fractal;

	fractal = (t_data *)fractal_void;
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < 700)
	{
		while (fractal->y < 700)
		{
			calculatemandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	return (NULL);
}

void	calculatemandelbrot(t_data *fractal)
{
	int		i;
	double	x_temp;

	//fractal->name = "mandel";
	i = 0;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy
			* fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
}

void	put_color_to_pixel(t_data *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->imgaddr;
	buffer[(y * fractal->length / 4) + x] = color;
}

//1. parsing : 1 seul arg valide (nom de la fractale)
//2.a. initialiser struct fractal
//2.b. connecter le systeme graphique et systeme d'exploitation (mlx_init)
//2.c. ouvrir nouvelle fenetre (mlx_new_window)
//2.d. remplir la fenetre
//2.e. gerer le clavier et la souris
int	main(int ac, char **av)
{
	t_data	*fractal;

	if (parsing(ac, av) == 0)
		exit(1);
	else
	{
		fractal = (t_data*)malloc(sizeof(t_data));
		init_fractal(fractal);
		fractal->mlx = mlx_init();
		fractal->win = mlx_new_window(fractal->mlx, 640, 480, "estegana fractol");
		fractal->img = mlx_new_image(fractal->mlx, 640, 480);
		fractal->imgaddr = mlx_get_data_addr(fractal->img, &fractal->bits, &fractal->length, &fractal->endian);
		generatefractal(fractal, av[1]);
		mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
		mlx_loop(fractal->mlx);
	}
}
