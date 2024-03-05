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
	draw(fractal, name);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	return (0);
}

//1. parsing : 1 seul arg valide (nom de la fractale)
//2.> initialiser struct fractal
//2.> connecter le systeme graphique et systeme d'exploitation (mlx_init)
//2.> ouvrir nouvelle fenetre taille absc / ord (mlx_new_window)
//2.> creer image de la taille de la fenetre (mlx_new_image)
//puis recup son adresse pr la modif plus tard avec mlx_get_data_addr)
//2.> gerer le clavier (mlx_key_hook) et la souris (mlx_mouse_hook)
//2.> generer la fractale en fonction de son av[1]
//2.> raffraichissement infini en attente de commande (mlx_loop)
int	main(int ac, char **av)
{
	t_data	*f;

	if (parsing(ac, av) == 0)
		exit(1);
	else
	{
		f = (t_data *)malloc(sizeof(t_data));
		init_fractal(f);
		f->mlx = mlx_init();
		f->win = mlx_new_window(f->mlx, A, O, "estegana fractol");
		f->img = mlx_new_image(f->mlx, A, O);
		f->imgaddr = mlx_get_data_addr(f->img, &f->bits, &f->len, &f->endian);
		generatefractal(f, av[1]);
		mlx_key_hook(f->win, keyboard, f);
		mlx_mouse_hook(f->win, mouse, f);
		mlx_hook(f->win, 17, 0L, exit_fractal, f);
		mlx_loop(f->mlx);
	}
	return (0);
}
