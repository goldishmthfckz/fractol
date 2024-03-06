/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:19:02 by estegana          #+#    #+#             */
/*   Updated: 2024/02/29 19:19:04 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//tant que le pt (x;y) reste ds la fenetre, calculer + attribuer couleur
void	*draw(void *tmp, char *name)
{
	t_data	*f;

	f = (t_data *)tmp;
	f->x = 0;
	f->y = 0;
	while (f->x < A)
	{
		while (f->y < O)
		{
			if (ft_strncmp(name, "mandelbrot", 11) == 0)
				mandelbrot(f);
			else if (ft_strncmp(name, "julia", 6) == 0)
				julia(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	return (NULL);
}

//z0 = 0
//z1 = (z0)^2 + c = c (avec c = x + iy)
//..
//zn = (zn-1)^2 + c
//noir=0x000000
void	mandelbrot(t_data *f)
{
	int		i;
	double	tmp;

	f->name = "mandelbrot";
	f->zx = 0.0;
	f->zy = 0.0;
	f->cx = (f->x / f->zoom) + f->offset_x;
	f->cy = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while (++i < f->max_iterations)
	{
		tmp = (f->zx * f->zx - f->zy * f->zy) + f->cx;
		f->zy = 2. * f->zx * f->zy + f->cy;
		f->zx = tmp;
		if (f->zx * f->zx + f->zy * f->zy >= __DBL_MAX__)
			break ;
	}
	if (i == f->max_iterations)
		ft_color(f, f->x, f->y, 0x000000);
	else
		ft_color(f, f->x, f->y,(f->color * i));
}

//zn+1 = zn^2 + c
void	julia(t_data *f)
{
	int		i;
	double	tmp;

	f->name = "julia";
	f->zx = (f->x / f->zoom) + f->offset_x;
	f->zy = (f->y / f->zoom) + f->offset_y;
	f->cx = -0.9;
	f->cy = -0.03;
	i = 0;
	while (++i < f->max_iterations)
	{
		tmp = (f->zx * f->zx - f->zy * f->zy) + f->cx;
		f->zy = 2. * f->zx * f->zy + f->cy;
		f->zx = tmp;
		if (f->zx * f->zx + f->zy * f->zy >= __DBL_MAX__)
			break ;
	}
	if (i == f->max_iterations)
		ft_color(f, f->x, f->y, 0x000000);
	else
		ft_color(f, f->x, f->y, (f->color * i));
}
