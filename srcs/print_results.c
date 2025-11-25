/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_results.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:06:14 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/25 17:10:32 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/libunit.h"
#include <stdio.h>

void	print_header(const char *title)
{
	if (!title)
		title = "TESTS";
	printf("%s=== %s ===%s\n", LU_BOLD LU_BLUE, title, LU_RESET);
}

void	print_result(const char *func_name, const char *test_name, int result)
{
	const char	*status;
	const char	*col;

	if (result == LU_OK)
	{
		status = "OK" ;
		col = LU_GREEN;
	}
	else if (result == LU_KO)
	{
		status = "KO";
		col = LU_RED;
	}
	else if (result == LU_SEGV)
	{
		status = "SIGSEGV";
		col = LU_RED;
	}
	else if (result == LU_BUS)
	{
		status = "SIGBUS";
		col = LU_RED;
	}
	printf("%s:%s:%s%s%s\n", func_name, test_name, col, status, LU_RESET);
}