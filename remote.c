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

//echap 65307
//haut 65362
//bas 65364
//gauche 65361
//droite 65363
int	keyboard(int key, t_data *f)
{
	if (key == 65307)
		exit(1);
	else if (key == 65361)
		f->offset_x -= 42 / f->zoom;
	else if (key == 65363)
		f->offset_x += 42 / f->zoom;
	else if (key == 65362)
		f->offset_y -= 42 / f->zoom;
	else if (key == 65364)
		f->offset_y += 42 / f->zoom;
	generatefractal(f, f->name);
	return (0);
}

//scroll haut 4
//scroll bas 5
int	mouse(int action, int x, int y, t_data *f)
{
	if (action == 4)
		zoom(f, x, y, 1);
	else if (action == 5)
		zoom(f, x, y, -1);
	generatefractal(f, f->name);
	return (0);
}
