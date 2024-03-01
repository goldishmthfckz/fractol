/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:09:33 by estegana          #+#    #+#             */
/*   Updated: 2024/02/29 15:09:37 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *f, int x, int y, int zoom)
{
	double	zooml;

	zooml = 1.42;
	if (zoom == 1)
	{
		f->offset_x = (x / f->zoom + f->offset_x) - (x / (f->zoom * zooml));
		f->offset_y = (y / f->zoom + f->offset_y) - (y / (f->zoom * zooml));
		f->zoom *= zooml;
	}
	else if (zoom == -1)
	{
		f->offset_x = (x / f->zoom + f->offset_x) - (x / (f->zoom / zooml));
		f->offset_y = (y / f->zoom + f->offset_y) - (y / (f->zoom / zooml));
		f->zoom /= zooml;
	}
	else
		return ;
}

//void	set_random_julia(double *cx, double *cy)
//{
//	*cx = generate_random_c();
//	*cy = generate_random_c();
//}

//echap 53
//haut 126
//bas 125
//gauche 123
//droite 124
//R 15
//C 8
//H 4
//J 38
//P 35
//M 46
int	keyboard(int key, t_data *fractal)
{
	if (key == 53)
		exit(1);
	else if (key == 123)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (key == 124)
		fractal->offset_x += 42 / fractal->zoom;
	else if (key == 126)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (key == 125)
		fractal->offset_y += 42 / fractal->zoom;
	generatefractal(fractal, fractal->name);
	return (0);
}

//scroll haut 4
//scroll bas 5
int	mouse(int action, int x, int y, t_data *fractal)
{
	if (action == 4)
		zoom(fractal, x, y, 1);
	else if (action == 5)
		zoom(fractal, x, y, -1);
	generatefractal(fractal, fractal->name);
	return (0);
}
