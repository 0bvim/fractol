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
#include "src/validations/avac.h"

int	main(int argc, const char **argv)
{
  if (validate_fractol_type(argv, argc))
    printf("In\n");
  else
    printf("Not in.\n");
  return (0);
}
