/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:52:22 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/25 17:37:43 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "colors.h"

enum e_result
{
	RES,
	LU_OK,
	LU_KO,
	LU_SEGV,
	LU_BUS,
};

typedef struct s_test
{
	char			*name;
	void			(*func)(void);
	struct s_test	*next;
}					t_test;

void	load_test(t_test **list, char *name, void (*f)(void));
int		launch_tests(t_test **list);
void	clear_tests(t_test **list);

void	print_header(const char *title);
void	print_result(const char *func_name, const char *test_name, int result);

int		test_launcher(void);
void	empty_test(void);
void	basic_test(void);

#endif