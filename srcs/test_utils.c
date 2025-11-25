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

int	launch_each_test(t_test *tmp, int *total, int passed, t_test **list, const char *func_name);
int	select_result(int result);

void	load_test(t_test **list, char *name, int (*f)(void))
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

int	ft_tests(t_test **list, const char *func_name, int *total)
{
	t_test	*tmp;
	int		passed;

	passed = 0;
	tmp = *list;
	if (!tmp)
		return (0);
	write(1, "=== LIBUNIT TESTS ===\n", 23);
	passed = launch_each_test(tmp, total, passed, list, func_name);
	return (passed);
}

int	launch_each_test(t_test *tmp, int *total, int passed, t_test **list, const char *func_name)
{
	pid_t	pid;
	int		result;
	int		output;

	result = RES;
	while (tmp)
	{
		pid = fork();
		if (pid == -1)
			result = FORK_ERR;
		*total = *total + 1;
		if (pid == 0)
		{
			output = tmp->func();
			clear_tests(list);
			if (output == 0)
				exit(EXIT_SUCCESS);
			exit(EXIT_FAILURE);
		}
		else
			result = select_result(result);
		print_result(func_name, tmp->name, result);
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
