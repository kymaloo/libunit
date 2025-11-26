/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:21:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/26 12:29:35 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"
#include <stdio.h>

int	real_launcher(int *total)
{
	t_test	*tests;
	int		result;

	printf("real\n");
	tests = NULL;
	load_test(&tests, "ok test", &ok_test);
	load_test(&tests, "ko test", &ko_test);
	load_test(&tests, "segfault test", &segfault_test);
	load_test(&tests, "bus test", &bus_test);

	result = ft_tests(&tests, "REAL", total);
	clear_tests(&tests);
	return (result);
}
