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

# define A 1920
# define O 1080

typedef struct s_data
{
	char		*name;
	void		*mlx;
	void		*win;
	void		*img;
	void		*imgaddr;
	int			bits;
	int			len;
	int			endian;
	int			color;
	int			x;
	int			y;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	double		offset_x;
	double		offset_y;
	double		zoom;
	int			max_iterations;
}				t_data;

//main
int		generatefractal(t_data *fractal, char *name);

//algos
void	*draw(void *tmp, char *name);
void	mandelbrot(t_data *fractal);
void	julia(t_data *fractal);

//remote
void	zoom(t_data *fractal, int x, int y, int zoom);
int		keyboard(int key, t_data *fractal);
int		mouse(int action, int x, int y, t_data *fractal);

//utils
int		parsing(int ac, char **av);
void	init_fractal(t_data *fractal);
void	ft_color(t_data *fractal, int x, int y, int color);
int		exit_fractal(t_data *fractal);

#endif
