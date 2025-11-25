/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:38:18 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/25 16:38:18 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libunit.h"
#include <string.h>

void	basic_test(void)
{
	char	*str;
	size_t	expected;
	size_t	result;
	// char	*str2;

	expected = 13;
	str = "Hello, World!";
	result = ft_strlen(str);
	// str2 = NULL;
	// *str2 = 'H';
	if (result != expected)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
