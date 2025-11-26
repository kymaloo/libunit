/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:21:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/26 11:54:55 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"

int	launcher_atoi(int *total)
{
	t_test	*tests;
	int		result;

	tests = NULL;
	// load_test(&tests, "Basic test", &basic_test_atoi);
	// load_test(&tests, "Empty test", &empty_test);
	result = ft_tests(&tests, "FT_SPLIT", total);
	clear_tests(&tests);
	return (result);
}
