/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:21:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/25 22:44:32 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"

int	launcher_atoi(void)
{
	t_test	*tests;
	int		result;

	tests = NULL;
	load_test(&tests, "Basic test", &basic_test);
	load_test(&tests, "Empty test", &empty_test);
	result = ft_tests(&tests);
	clear_tests(&tests);
	return (result);
}