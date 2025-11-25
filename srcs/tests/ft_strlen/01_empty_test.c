/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_empty_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:39:08 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/25 16:39:08 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"

void	empty_test(void **list)
{
	clear_tests((t_test **)list);
	if (ft_strlen("") != 0)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
