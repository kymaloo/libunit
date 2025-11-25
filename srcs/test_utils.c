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

void	load_test(t_test **list, char *name, void (*f)(void))
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
	int		result;
	int		status;
	pid_t	pid;

	total = 0;
	passed = 0;
	tmp = *list;
	if (!tmp)
		return (0);
	print_header("LIBUNIT TESTS");
	while (tmp)
	{
		pid = fork();
		total++;
		if (pid == 0)
			tmp->func();
		else
		{
			waitpid(pid, &status, 0);
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
		}
		print_result("LIBUNIT", tmp->name, result);
		if (result == LU_OK)
			passed++;
		tmp = tmp->next;
	}
	printf("\nSummary: %d/%d tests passed\n", passed, total);
	if (passed != total)
		return (-1);
	return (0);
}
