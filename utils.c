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

int	castdouble(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i += 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57) && !(str[i] == '.'))
			return (0);
		i += 1;
	}
	return (1);
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
