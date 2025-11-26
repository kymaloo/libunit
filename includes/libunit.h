/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:52:22 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/26 11:57:10 by jlaine-b         ###   ########.fr       */
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
	WAIT_ERR,
	FORK_ERR,
};

typedef struct s_test
{
	char			*name;
	int				(*func)(void);
	struct s_test	*next;
}					t_test;

void	load_test(t_test **list, char *name, int (*f)(void));
int		ft_tests(t_test **list, const char *func_name, int *total);
int		launcher_strlen(int *total);
int		launcher_atoi(int *total);
int		launcher_split(int *total);
void	clear_tests(t_test **list);

void	print_result(const char *func_name, const char *test_name, int result);

void ft_write_colored(int fd, char *color, char *str);


int ft_strlen_launcher(void);
int ft_strlen_empty_test(void);
int ft_strlen_basic_test(void);

int ft_atoi_launcher(void);
int ft_atoi_basic_test(void);
int ft_atoi_negative_test(void);
int ft_atoi_zero_test(void);
int ft_atoi_whitespace_test(void);
int ft_atoi_sign_test(void);
int ft_atoi_mixed_test(void);
int ft_atoi_large_positive_test(void);
int ft_atoi_large_negative_test(void);
int ft_atoi_leading_zeros_test(void);
int ft_atoi_empty_string_test(void);

#endif