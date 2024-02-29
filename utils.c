#include "fractol.h"

//si pas de parametre > msg d'erreur
//si + d'1 parametre > msg d'erreur
//si 1 parametre mais pas de fractale valide > msg d'erreur
int	parsing(int ac, char **av)
{
	if (ac == 1)
	{
		ft_printf("enter fractal name ; either -julia- or -mandelbrot-\n");
		return (0);
	}
	if (ac > 2)
	{
		ft_printf("too many args\n");
		return (0);
	}
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "julia") != 0 && ft_strcmp(av[1], "mandelbrot") != 0)
		{
			ft_printf("enter valid fractal\n");
			return (0);
		}
		else
			return (1);
	}
	return (1);
}

//efface le contenu de la window et free les data de la fractale
//int	exit_fractal(t_data *fractal)
//{
//	mlx_destroy_image(fractal->mlx_ptr, fractal->image);
//	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
//	free(fractal->mlx_ptr);
//	free(fractal);
//	exit(1);
//	return (0);
//}
