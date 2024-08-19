#pragma once

# include <stdbool.h>
# include "../../lib/libft/libft.h"

# define M_SIZE 2
# define J_SIZE 4
# define MAN "mandelbrot"
# define JUL "julia"

bool  validate_fractol_type(const char **av, int size);
