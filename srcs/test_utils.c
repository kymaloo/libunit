#include "../includes/libunit.h"
#include <stdio.h>

// Create a test node with name and testing function
void load_test(t_test **list, char *name, int (*f)(void))
{
    t_test *node;
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
        t_test *it = *list;
        while (it->next)
            it = it->next;
        it->next = node;
    }
}

void clear_tests(t_test **list)
{
    t_test *it;
    t_test *tmp;
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

void print_header(const char *title)
{
    if (!title)
        title = "TESTS";
    printf("%s=== %s ===%s\n", LU_BOLD LU_BLUE, title, LU_RESET);
}

void print_result(const char *func_name, const char *test_name, int result)
{
    const char *status;
    const char *col;

    if (result == LU_OK)
        status = "OK", col = LU_GREEN;
    else if (result == LU_KO)
        status = "KO", col = LU_RED;
    else if (result == LU_SEGV)
        status = "SIGSEGV", col = LU_RED;
    else if (result == LU_BUS)
        status = "SIGBUS", col = LU_RED;
    printf("%s:%s:%s%s%s\n", func_name, test_name, col, status, LU_RESET);
}

int launch_tests(t_test **list)
{
    t_test *tmp;
    int total;
    int passed;
    int result;
    int status;
    pid_t   pid;

    total = 0;
    passed = 0;
    tmp = *list;
    if (!tmp)
        return (0);
    print_header("LIBUNIT TESTS");
    while (tmp)
    {
        pid = fork();
        if (pid == 0)
        {
            total++;
            result = tmp->func();
        }
        else
        {
            waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
            result = 0;
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
