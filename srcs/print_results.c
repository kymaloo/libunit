/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:06:14 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/25 17:42:37 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"
#include <stdio.h>

void	print_result(const char *func_name, const char *test_name, int result)
{
	const char	*status;

	if (result == LU_OK)
		status = "OK" ;
	else if (result == LU_KO)
		status = "KO";
	else if (result == LU_SEGV)
		status = "SIGSEGV";
	else if (result == LU_BUS)
		status = "SIGBUS";
	else if (result == RES)
		status = "UNKNOWN ERROR";
	write(1, func_name, ft_strlen(func_name));
	write(1, ":", 1);
	write(1, test_name, ft_strlen(test_name));
	write(1, ":", 1);
	write(1, status, ft_strlen(status));
	write(1, "\n", 1);
}
