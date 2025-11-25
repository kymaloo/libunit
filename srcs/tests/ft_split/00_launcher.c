/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:21:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/25 23:09:51 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"

int	launcher_split(int *total)
{
	t_test	*tests;
	int		result;

	tests = NULL;
	load_test(&tests, "Basic test", &basic_test_split);
	// load_test(&tests, "Empty test", &empty_test);
	result = ft_tests(&tests, "FT_STRLEN", total);
	clear_tests(&tests);
	return (result);
}