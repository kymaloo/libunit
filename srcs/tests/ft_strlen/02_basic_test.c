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

int ft_strlen_basic_test(void)
{
	char	*str;
	size_t	expected;
	size_t	result;

    if (result != expected)
        return (LU_KO);
    return (LU_OK);
}
