/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:21:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/26 11:54:59 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"

int	launcher_strlen(int *total)
{
	t_test	*tests;
	int		result;

	tests = NULL;
	load_test(&tests, "Basic test", &basic_test_strlen);
	load_test(&tests, "Empty test", &empty_test_strlen);
	result = ft_tests(&tests, "FT_ATOI", total);
	clear_tests(&tests);
	return (result);
}
