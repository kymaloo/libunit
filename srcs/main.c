/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:45:09 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/26 12:14:44 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

int	main(void)
{
	int	passed;
	int	total;

	passed = 0;
	write(1, "=== LIBUNIT TESTS ===\n", 23);
	passed += ft_strlen_launcher(&total);
	passed += ft_atoi_launcher(&total);
	passed += ft_split_launcher(&total);
	write(1, "\nSummary: ", 11);
	ft_putnbr_fd(passed, 1);
	write(1, "/", 1);
	ft_putnbr_fd(total, 1);
	write(1, " tests passed \n", 16);
	if (passed != total)
		return (-1);
	return (0);
}
