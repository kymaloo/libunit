/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:45:09 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/25 17:05:17 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

int	main(void)
{
	int	result;

	result = 0;
	result += test_launcher();
	if (result != 0)
		return (-1);
	return (0);
}
