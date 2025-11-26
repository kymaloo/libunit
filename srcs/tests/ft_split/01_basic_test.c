/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:47:36 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/26 11:54:31 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	basic_test_split(void)
{
	char	*line;
	char	c;	
	int		i;
	char	**tab;

	line = "bonjour les amis";
	c = ' ';
	i = 0;
	tab = ft_split(line, c);
	if (ft_strncmp(tab[0], "bonjour", 9) != 0)
		return (-1);
	if (ft_strncmp(tab[1], "les", 4) != 0)
		return (-1);
	if (ft_strncmp(tab[2], "amis", 5) != 0)
		return (-1);
	if (tab[3])
		return (-1);
	return (1);
}
