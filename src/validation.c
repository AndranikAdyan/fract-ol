/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadyan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 22:53:41 by aadyan            #+#    #+#             */
/*   Updated: 2025/04/06 14:54:15 by aadyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

static void	print_help_menu(void)
{
	ft_putstr_fd(CYAN"╔════════════════════════════════════╗\n", 1);
	ft_putstr_fd("║          "YELLOW"FRACT-OL PROJECT"CYAN"          ║\n", 1);
	ft_putstr_fd("║          "YELLOW"Username: aadyan"CYAN"          ║\n", 1);
	ft_putstr_fd("╚════════════════════════════════════╝\n"RESET, 1);
	ft_putstr_fd(YELLOW"Usage:\n"RESET, 1);
	ft_putstr_fd(GREEN"./fractol <fractal name>\n", 1);
	ft_putstr_fd("Example: ./fractol mandelbrot\n", 1);
	ft_putstr_fd(YELLOW"Fractals:\n"RESET, 1);
	ft_putstr_fd("• mandelbrot\n", 1);
	ft_putstr_fd("• julia\n", 1);
	ft_putstr_fd("• tricorn\n", 1);
	ft_putstr_fd("• celtic_mandelbar\n", 1);
	ft_putstr_fd("• burning_ship\n", 1);
	ft_putstr_fd("• newton\n", 1);
	ft_putstr_fd(YELLOW"Controls:\n"RESET, 1);
	ft_putstr_fd("Arrows     → move fractal\n", 1);
	ft_putstr_fd("+ / -      → zoom in / out\n", 1);
	ft_putstr_fd("Scroll     → zoom in / out\n", 1);
	ft_putstr_fd("R          → reset fractal view\n", 1);
	ft_putstr_fd("W A S D    → change Julia parameters\n", 1);
	ft_putstr_fd("Space      → change colors\n", 1);
	ft_putstr_fd("L          → lock animation\n", 1);
	ft_putstr_fd("N / M      → something interesting :)\n", 1);
	ft_putstr_fd(GREEN"Have fun exploring fractals!\n"RESET, 1);
}

static int	check_fractal(char *fractal)
{
	if (ft_strcmp(fractal, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(fractal, "julia") == 0)
		return (1);
	else if (ft_strcmp(fractal, "tricorn") == 0)
		return (1);
	else if (ft_strcmp(fractal, "celtic_mandelbar") == 0)
		return (1);
	else if (ft_strcmp(fractal, "burning_ship") == 0)
		return (1);
	else if (ft_strcmp(fractal, "newton") == 0)
		return (1);
	return (0);
}

int	validation(int ac, char *av[])
{
	if (ac != 2)
	{
		print_help_menu();
		return (0);
	}
	if (!check_fractal(av[1]))
	{
		ft_putstr_fd(RED"Invalid fractal name!\n"RESET, 2);
		ft_putstr_fd("Available fractals:\n", 1);
		ft_putstr_fd("• mandelbrot\n", 1);
		ft_putstr_fd("• julia\n", 1);
		ft_putstr_fd("• tricorn\n", 1);
		ft_putstr_fd("• celtic_mandelbar\n", 1);
		ft_putstr_fd("• burning_ship\n", 1);
		ft_putstr_fd("• newton\n", 1);
		return (0);
	}
	return (1);
}
