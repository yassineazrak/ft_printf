/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 19:34:10 by mobouzar          #+#    #+#             */
/*   Updated: 2019/08/05 10:27:05 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int	main()
{
	int	i;
	int j;

	// i = ft_printf("|%.o|%-.o|%#.o|%0.o|\n", 0U, 0U, 0U, 0U);
	// j =    printf("|%.o|%-.o|%#.o|%0.o|\n", 0U, 0U, 0U, 0U);
	// i =    ft_printf("|%-#23.5llX|%-023.5llX|%#023.5llX|%-#023.5llX|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	// j =    printf("|%-#23.5llX|%-023.5llX|%#023.5llX|%-#023.5llX|\n", ULLONG_MAX, ULLONG_MAX, ULLONG_MAX, ULLONG_MAX);
	i =    ft_printf("|%#|% h|% hZ|\n");
	j =    	  printf("|%#|% h|% hZ|\n");
	// j =    	  printf("|%010s|\n", "hello");
	// j =    	  printf("|%2.c|\n", 'h');


	printf("our = %d, sys = %d\n", i, j);
}