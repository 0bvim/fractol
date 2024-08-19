/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:01:30 by vde-frei          #+#    #+#             */
/*   Updated: 2024/08/19 01:39:36 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "validations/avac.h"

static mlx_image_t* image;

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int main(int argc, const char **argv)
{
	mlx_t	*mlx;

	if (validate_fractol_type(argv, argc))
	{
		if (!(mlx = mlx_init(800, 600, "FRACTAL DO LEME AO PONTAL", true)))
		{
			puts(mlx_strerror(mlx_errno));
			return(EXIT_FAILURE);
		}
		if (!(image = mlx_new_image(mlx, 128, 128)))
		{
			mlx_close_window(mlx);
			puts(mlx_strerror(mlx_errno));
			return (EXIT_FAILURE);
		}
		if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		{
			mlx_close_window(mlx);
			puts(mlx_strerror(mlx_errno));
			return (EXIT_FAILURE);
		}
		mlx_loop_hook(mlx, ft_hook, mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	else
		printf("Not in.\n");
	return (EXIT_SUCCESS);
}
