/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:21:10 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/26 12:11:03 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"

int	ft_strlen_launcher(int *total)
{
	t_test	*tests;
	int		result;

	tests = NULL;
	load_test(&tests, "Basic test", &ft_strlen_basic_test);
	load_test(&tests, "Empty test", &ft_strlen_empty_test);
	result = ft_tests(&tests, "FT_ATOI", total);
	clear_tests(&tests);
	return (result);
}
