/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:01:30 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/14 00:40:38 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
			|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		printf("In\n");
	}
	else
	{
		printf("Not in.\n");
	}
}
