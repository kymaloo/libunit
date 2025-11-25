/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine-b <jlaine-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:40:24 by jlaine-b          #+#    #+#             */
/*   Updated: 2025/11/25 16:40:24 by jlaine-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"
#include <stdio.h>

int	launch_each_test(t_test *tmp, int *total, int passed, t_test **list);
int	select_result(int result);

void	load_test(t_test **list, char *name, void (*f)(void **list))
{
	t_test	*node;
	t_test	*it;

	node = (t_test *)malloc(sizeof(t_test));
	if (!node)
		return ;
	node->name = name;
	node->func = f;
	node->next = NULL;
	if (!*list)
		*list = node;
	else
	{
		it = *list;
		while (it->next)
			it = it->next;
		it->next = node;
	}
}

void	clear_tests(t_test **list)
{
	t_test	*it;
	t_test	*tmp;

	if (!list || !*list)
		return ;
	it = *list;
	while (it)
	{
		tmp = it->next;
		free(it);
		it = tmp;
	}
	*list = NULL;
}

int	launch_tests(t_test **list)
{
	t_test	*tmp;
	int		total;
	int		passed;

	total = 0;
	passed = 0;
	tmp = *list;
	if (!tmp)
		return (0);
	write(1, "=== LIBUNIT TESTS ===\n", 23);
	passed = launch_each_test(tmp, &total, passed, list);
	write(1, "\nSummary: ", 11);
	ft_putnbr_fd(passed, 1);
	write(1, "/", 1);
	ft_putnbr_fd(total, 1);
	write(1, " tests passed \n", 16);
	if (passed != total)
		return (-1);
	return (0);
}

int	launch_each_test(t_test *tmp, int *total, int passed, t_test **list)
{
	pid_t	pid;
	int		result;

	result = RES;
	while (tmp)
	{
		pid = fork();
		if (pid == -1)
			result = FORK_ERR;
		*total = *total + 1;
		if (pid == 0)
			tmp->func((void **)list);
		else
			result = select_result(result);
		print_result("LIBUNIT", tmp->name, result);
		if (result == LU_OK)
			passed++;
		tmp = tmp->next;
	}
	return (passed);
}

int	select_result(int result)
{
	int		status;

	if (wait(&status) == -1)
		result = WAIT_ERR;
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_SUCCESS)
			result = LU_OK;
		if (WEXITSTATUS(status) == EXIT_FAILURE)
			result = LU_KO;
	}
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
		result = LU_SEGV;
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGBUS)
		result = LU_BUS;
	return (result);
}
