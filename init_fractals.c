/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:53:34 by estegana          #+#    #+#             */
/*   Updated: 2024/03/09 16:53:35 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//initialise donnees de mandel
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

//initialise donnees de julia si y a pas de parametres en plus passes
void	init_juliastandard(t_data *f)
{
	f->x = 0;
	f->y = 0;
	f->color = 0xbddfff;
	f->zoom = 250;
	f->offset_x = -2;
	f->offset_y = -1.5;
	f->max_iterations = 42;
	f->cx = -0.8;
	f->cy = -0.156;
}

//initialise donnees de julia ac les parametres passes
void	init_juliaargs(t_data *f, char *cx, char *cy)
{
	f->x = 0;
	f->y = 0;
	f->color = 0xbddfff;
	f->zoom = 250;
	f->offset_x = -2;
	f->offset_y = -1.5;
	f->max_iterations = 42;
	f->cx = ft_atoi(cx);
	f->cy = ft_atoi(cy);
}
