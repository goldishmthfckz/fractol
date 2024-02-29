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

int	generatefractal(t_data *fractal, char *name)
{
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
		drawmandelbrot(fractal);
	else if (ft_strncmp(name, "julia", 6) == 0)
		drawjulia(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
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
		fractal->win = mlx_new_window(fractal->mlx, ABSCISSES, ORDONNEES, "estegana fractol");
		fractal->img = mlx_new_image(fractal->mlx, ABSCISSES, ORDONNEES);
		fractal->imgaddr = mlx_get_data_addr(fractal->img, &fractal->bits, &fractal->length, &fractal->endian);
		//keyboard
		//mouse
		//exit
		generatefractal(fractal, av[1]);
		mlx_loop(fractal->mlx);
	}
}
