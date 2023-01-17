/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:01 by crepou            #+#    #+#             */
/*   Updated: 2023/01/17 16:44:26 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	*ft_put_color(void *str, uint8_t c, size_t n)
{
	size_t		count;
	void		*str_cp;

	str_cp = str;
	count = 0;
	while (count < n)
	{
		*(uint8_t *) str_cp = c;
		str_cp++;
		count++;
	}
	return (str);
}

int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	unsigned long	i;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
	if (!mlx)
		ft_error();
	printf("Width: %d Height: %d\n", mlx->width, mlx->height);
	img = mlx_new_image(mlx, 128, 128);
	i = 0;
	while (i < 128 * 128 * sizeof(int32_t))
	{
		if (i % 4 == 0)
			img->pixels[i] = 148;
		if (i % 4 == 1)
			img->pixels[i] = 0;
		if (i % 4 == 2)
			img->pixels[i] = 211;
		if (i % 4 == 3)
			img->pixels[i] = 255;
		i++;
	}
	mlx_image_to_window(mlx, img, 50, 50);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

void ft_putpixel(mlx_image_t **img, int x, int y, int color)
{
	
}

int	main(int argc, char *argv[])
{
	
}