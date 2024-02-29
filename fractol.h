/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estegana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:01:02 by estegana          #+#    #+#             */
/*   Updated: 2024/02/23 20:01:05 by estegana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>//malloc, free
# include <unistd.h>//write
# include <math.h>
# include "libft/incl/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*imgaddr;
	int			bits;
	int			length;
	int			endian;
	int			x;
	int			y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
		double	offset_x;
	double	offset_y;
	double	zoom;
	int		max_iterations;
}				t_data;

//main
void	init_fractal(t_data *fractal);
int	generatefractal(t_data *fractal, char *name);
void	*drawmandelbrot(void *fractal_void);
void	calculatemandelbrot(t_data *fractal);
void	put_color_to_pixel(t_data *fractal, int x, int y, int color);

//remote


//utils
int	parsing(int ac, char **av);

#endif
