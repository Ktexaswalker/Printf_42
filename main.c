/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartine <hmartine@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:47:55 by hmartine          #+#    #+#             */
/*   Updated: 2022/04/02 15:23:28 by hmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include "ft_printf.h"
#include<limits.h>

int	main(void)
{
	void	*a;

	ft_printf("\nString");
	ft_printf("\nHola");
	ft_printf("\n*Puntero");
	ft_printf("\n%p -> ", &a);
	printf("\n%p print->.. ", &a);
	printf("\n%p print ->.", (void *)-14523);
	ft_printf("\n%p -> ", (void *)-14523);
	ft_printf("\nhex");
	ft_printf("\nx -> %x", -123456);
	ft_printf("\nHEX");
	ft_printf("\nX -> %X", -123456);
	ft_printf("\nInt, Int");
	ft_printf("\n Int D: %d, Int I: %i", 123456, 123456);
	ft_printf("\nPorcentaje");
	ft_printf("\n%%");
	ft_printf("hola\n%p", (void *)ULONG_MAX);
	printf("adios\n%p", (void *)ULONG_MAX);
	return (0);
}
