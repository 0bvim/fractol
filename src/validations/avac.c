#include "avac.h"
#include <stdbool.h>

//TODO: validate and parse args for julia.

static bool  validate(const char *name, int size)
{
  if (size == M_SIZE)
    return (!ft_strncmp(name, MAN, 10));
  else if (size == J_SIZE)
    return (!ft_strncmp(name, JUL, 5));
  else
    return (false);
}

bool  validate_fractol_type(const char **av, int size)
{
  if (validate(av[1], size))
    return (true);
  return (false);
}

